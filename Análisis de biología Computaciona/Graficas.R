# Cargamos librerías
library(ggplot2)
library(dplyr)
library(seqinr)

# Especificamos el directorio donde están los archivos .txt
fasta_directory <- "/Users/mayra/OneDrive/Escritorio/UNI/Biología/COVID_sequences"

# Verificamos que el directorio exista y cambiamos el directorio de trabajo
if (!dir.exists(fasta_directory)) {
  stop("Directory does not exist: ", fasta_directory)
} else {
  setwd(fasta_directory)
}

# Listamos todos los archivos .txt
fasta_files <- list.files(pattern = "\\.txt$", full.names = TRUE)

# Verificamos si hay archivos para procesar
if (length(fasta_files) == 0) {
  stop("No .txt files found in the directory.")
}

# Inicializamos una lista vacía para almacenar los datos
sequence_data <- list()

# Procesamos cada archivo
for (i in seq_along(fasta_files)) {
  file_path <- fasta_files[i]
  
  # Leemos y procesamos la secuencia
  sequences <- tryCatch({
    read.fasta(file = file_path, seqtype = "DNA")
  }, error = function(e) {
    cat("Error reading file: ", file_path, "\nError message: ", e$message, "\n")
    return(NULL)
  })
  
  if (is.null(sequences)) {
    next  # Saltamos al siguiente archivo si hay error
  }
  
  # Obtenemos la primera secuencia y calculamos su longitud
  dna_sequence <- tolower(paste(sequences[[1]], collapse = ""))
  seq_length <- nchar(dna_sequence)
  
  # Contamos los nucleótidos y calculamos los porcentajes
  counts <- table(strsplit(dna_sequence, "")[[1]])
  percentages <- counts / seq_length * 100
  
  # Preparamos un marco de datos
  df <- data.frame(Sequence = rep(basename(file_path), length(percentages)),
                   Base = names(percentages),
                   Percentage = as.numeric(percentages))
  sequence_data[[i]] <- df
}

# Combinamos todos los marcos de datos en uno solo
combined_data <- do.call(rbind, sequence_data)

# Graficamos los datos
ggplot(combined_data, aes(x = Sequence, y = Percentage, fill = Base)) +
  geom_bar(stat = "identity", position = "fill") +
  labs(title = "Nucleotide Composition of DNA Sequences", x = "Sequence File", y = "Percentage (%)", fill = "Nucleotide") +
  theme_minimal() +
  theme(axis.text.x = element_text(angle = 45, hjust = 1))
