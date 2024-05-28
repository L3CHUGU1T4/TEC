#Leobardo de Jesús Carbajal
#A01772464
#Parte 2 evidencia 1

# Cargamos librerías necesarias
library(ggplot2)
library(dplyr)

# Directorio de archivos .txt con secuencias de ADN
fasta_directory <- "/Users/leodejesus/Desktop/all/escuela/segundo semestre/Biologia_computacional/sec" 

# Verificar la existencia del directorio
if (!dir.exists(fasta_directory)) {
  stop("Directory does not exist: ", fasta_directory)
} else {
  setwd(fasta_directory)
}

# Listar todos los archivos .txt
fasta_files <- list.files(pattern = "\\.txt$", full.names = TRUE)

# Verificar si hay archivos para procesar
if (length(fasta_files) == 0) {
  stop("No .txt files found in the directory.")
}

# Función para crear la secuencia complementaria
crear_secuencia_complementaria <- function(sequence) {
  # Usamos chartr para reemplazar los caracteres
  return(chartr("acgtACGT", "tgcaTGCA", sequence))
}

# Almacenar datos para gráficas
sequence_data <- list()
percentage_data <- list()

# Procesar cada archivo
for (file in fasta_files) {
  dna_sequence <- tolower(paste(readLines(file), collapse = ""))
  
  # Calculando longitudes y contenido de GC
  seq_length <- nchar(dna_sequence)
  cat("La longitud de la secuencia en ", basename(file), " es ", seq_length, " bases.\n")
  
  # Contar nucleótidos y calcular porcentajes
  counts <- table(strsplit(dna_sequence, "")[[1]])
  counts_complete <- setNames(as.numeric(c(counts['a'], counts['c'], counts['g'], counts['t'])), c('a', 'c', 'g', 't'))
  total_counts <- sum(counts_complete)  # Total de nucleótidos contados
  
  if (total_counts > 0) {  # Asegurar que hay datos para procesar
    percentages <- counts_complete / total_counts * 100
    # Crear DataFrame para la composición de nucleótidos y almacenar en la lista
    df_seq <- data.frame(Sequence = rep(basename(file), length(percentages)),
                         Base = names(percentages),
                         Percentage = percentages,
                         stringsAsFactors = FALSE)  # Evitar conversiones a factores
    sequence_data[[length(sequence_data) + 1]] <- df_seq
    
    # Crear DataFrame para los porcentajes y almacenar en la lista
    df_perc <- data.frame(Sequence = rep(basename(file), length(percentages)),
                          Nucleotide = names(percentages),
                          Percentage = percentages,
                          stringsAsFactors = FALSE)  # Evitar conversiones a factores
    percentage_data[[length(percentage_data) + 1]] <- df_perc
  } else {
    cat("No se encontraron nucleótidos válidos en ", basename(file), ".\n")
  }
  
  # Generar secuencia complementaria
  complementaria <- crear_secuencia_complementaria(dna_sequence)
  cat("La secuencia complementaria de ", basename(file), " es:\n", complementaria, "\n\n")
}

# Combina todos los DataFrames en uno para la visualización
combined_sequence_data <- do.call(rbind, sequence_data)
combined_percentage_data <- do.call(rbind, percentage_data)

# Colores pastel
colores_pastel <- c("#FFB6C1", "#ADD8E6", "#98FB98", "#FFD700")

# Crear gráfica de composición de nucleótidos
p_sequence <- ggplot(combined_sequence_data, aes(x = Sequence, y = Percentage, fill = Base)) +
  geom_bar(stat = "identity", position = "fill") +
  scale_fill_manual(values = colores_pastel) +  # Colores pastel
  labs(title = "Nucleotide Composition of DNA Sequences",
       x = "Sequence File",
       y = "Percentage (%)",
       fill = "Nucleotide") +
  theme_minimal() +
  theme(axis.text.x = element_text(angle = 45, hjust = 1)) +
  # Interpretación escrita de la gráfica
  geom_text(x = 0.5, y = -0.3, label = "Cada barra representa un archivo de secuencia de ADN.\nLa altura de la barra muestra el porcentaje de nucleótidos (A, C, G, T) en la secuencia.", size = 4, color = "gray30", hjust = 0, vjust = 1)

# Crear gráfica de porcentajes de nucleótidos
p_percentage <- ggplot(combined_percentage_data, aes(x = Sequence, y = Percentage, fill = Nucleotide)) +
  geom_bar(stat = "identity") +
  scale_fill_manual(values = colores_pastel) +  # Colores pastel
  labs(title = "Percentage of Nucleotides in DNA Sequences",
       x = "Sequence File",
       y = "Percentage (%)",
       fill = "Nucleotide") +
  theme_minimal() +
  theme(axis.text.x = element_text(angle = 45, hjust = 1)) +
  # Etiquetas de porcentaje
  geom_text(aes(label = paste0(round(Percentage, 2), "%")), position = position_stack(vjust = 0.5), size = 3) +
  # Interpretación escrita de la gráfica
  geom_text(x = 0.5, y = -0.3, label = "Cada barra representa un archivo de secuencia de ADN.\nLa altura de la barra muestra el porcentaje de cada nucleótido (A, C, G, T) en la secuencia.", size = 4, color = "gray30", hjust = 0, vjust = 1)

# Mostrar gráficas
print(p_sequence)
print(p_percentage)
