#Leobardo de Jesús Carbajal
#A01772464
#==============================
# Importamos paquetes necesarios
library(ggplot2)
library(dplyr)
library(ggtree)

read_sequence_from_txt <- function(file_path) { 
  seq <- readLines(file_path)
  seq <- gsub("[^ACGT]", "", seq) 
  seq <- paste(seq, collapse = "")
  return(seq)
}

# Función para calcular el tamaño de la secuencia
calculate_sequence_size <- function(sequence) { 
  return(nchar(sequence))
}

# Función para calcular el porcentaje de nucleótidos
calculate_nucleotide_composition <- function(sequence) { 
  nucleotides <- table(strsplit(sequence, "")[[1]])
  nucleotide_percentage <- (nucleotides / nchar(sequence)) * 100
  return(nucleotide_percentage)
}

folder_path <- "/Users/leodejesus/Desktop/all/escuela/segundo semestre/Biologia_computacional/lechuguita" 
file_paths <- list.files(folder_path, full.names = TRUE)  # Listar los archivos de la carpeta
sequence_data <- list()


# Procesar cada archivo de la carpeta (directorio)
for (i in seq_along(file_paths)) {
  file_path <- file_paths[i]  # Obtener la ruta del archivo
  
  # Leer la secuencia del archivo y realizar los cálculos necesarios
  sequence <- read_sequence_from_txt(file_path)
  seq_length <- calculate_sequence_size(sequence)
  nucleotide_composition <- calculate_nucleotide_composition(sequence)
  
  # Guardar los resultados en un marco de datos
  df <- data.frame(Sequence = rep(basename(file_path), length(nucleotide_composition)),
                   Base = names(nucleotide_composition),
                   Percentage = as.numeric(nucleotide_composition))
  
  sequence_data[[i]] <- df  # Guardar el marco de datos en la lista
}

combined_data <- do.call(rbind, sequence_data)

p_secuencia<-ggplot(combined_data, aes(x = Base, y = Percentage, fill = Sequence)) + 
  geom_bar(stat = "identity", position = "dodge") +  
  labs(title = "Nucleotide Composition of DNA Sequences", x = "Nucleotide", y = "Percentage (%)", fill = "Sequence File") + 
  theme_minimal() + 
  theme(axis.text.x = element_text(angle = 45, hjust = 1)) 


# Procesar cada archivo de la carpeta (directorio)
for (file_path in file_paths) {
  cat("\n")
  cat("Archivo procesado:", basename(file_path), "\n")
  
  # Leer la secuencia del archivo
  sequence <- read_sequence_from_txt(file_path)
  
  # Calcular el tamaño de la secuencia
  seq_length <- calculate_sequence_size(sequence)
  
  # Calcular la composición de nucleótidos
  nucleotide_composition <- calculate_nucleotide_composition(sequence)
  
  # Imprimir los resultados
  cat("Secuencia original:", sequence, "\n")
  cat("Tamaño de la secuencia:", seq_length, "nucleótidos\n")
  cat("Composición de nucleótidos:\n")
  cat("A:", nucleotide_composition["A"], "(", round(nucleotide_composition["A"], 2), "%)\n")
  cat("C:", nucleotide_composition["C"], "(", round(nucleotide_composition["C"], 2), "%)\n")
  cat("G:", nucleotide_composition["G"], "(", round(nucleotide_composition["G"], 2), "%)\n")
  cat("T:", nucleotide_composition["T"], "(", round(nucleotide_composition["T"], 2), "%)\n")
}
# Generamos un árbol filogenético ficticio
tree <- rtree(20)

# Creamos un objeto de árbol filogenético con ggtree
ggtree_tree <- ggtree(tree)

# Añadimos el árbol filogenético al gráfico existente
p_secuencia <- p_secuencia + ggtree_tree

# Mostramos el gráfico actualizado
print(p_secuencia)