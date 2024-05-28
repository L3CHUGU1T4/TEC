#CARGAMOS LIBRERÍAS
library(ggplot2)
library(dplyr)
library(seqinr)

#DIRECTORIO DE ARCHIVOS FASTA
fasta_directory <- "/Users/leodejesus/Desktop/all/escuela/segundo semestre/Biologia_computacional/sec" 

# CONFIRMAR QUE EL DIRECTOIO EXISTA Y QUE ESTA CORRIENDO CORRECTAMENTE
if (!dir.exists(fasta_directory)) {
  stop("Directory does not exist: ", fasta_directory)
} else {
  setwd(fasta_directory)
}

# LISTAR TODOS LOS ARCHIVOS .TXT
fasta_files <- list.files(pattern = "\\.txt$", full.names = TRUE)  # Cambiado de .fasta a .txt

# CHECAR SI HAY ARCHIVOS PARA PROCESAR
if (length(fasta_files) == 0) {
  stop("No .fasta files found in the directory.")
}

#==========================================================================================

#FUNCIÓN PARA CALCULAR LONGITUD DE LAS SECUENCIAS DE CADA VARIANTE

leer_fasta_calcular_longitud <- function(file_name) {
  sequences <- tryCatch({   #VERIFICAR PARA ERRORES
    read.fasta(file = file_name, seqtype = "DNA")
  }, error = function(e) {
    cat("Error reading file: ", file_name, "\nError message: ", e$message, "\n")
    return(NULL)  # Return NULL on error
  })
  if (is.null(sequences)) {
    return(NULL)
  }
  
  # CALCULAR LONGITUD
  sequence_length <- length(sequences[[1]])
  return(sequence_length)
}

# CREAR LOOP PARA CORRER TODOS LOS ARCHIVOS Y RETORNAR EL RESULTADO
for (file in fasta_files) {
  seq_length <- leer_fasta_calcular_longitud(file)
  if (!is.null(seq_length)) {
    cat("La longitud de la secuencia en ", basename(file), " ese ", seq_length, " bases.\n")
  }
}

#=========================================================================================

#FUNCIÓN PARA CREAR GRÁFICA Y COMPARAR LAS BASES DE ADN DE CADA VARIANTE

sequence_data <- list()  #Inicializar una lista vacía para almacenar los datos de cada uno de los archivos

for (i in seq_along(fasta_files)) {   #Loop para procesar cada archivo de la carpeta (directorio)
  file_path <- fasta_files[i]
  
  #Leer la secuencia del archivo, saltándose el encabezado, y concatenando todas las líneas de secuencia 
  sequence_lines <- readLines(file_path)
  sequence <- tolower(paste(sequence_lines[-1], collapse = "")) 
  seq_length <- nchar(sequence)   #CALCULAR LONGITUD
  counts <- table(strsplit(sequence, "")[[1]])   #CONTAR NUCLEOTIDOS
  percentages <- counts / seq_length * 100  #CALCULA PORCENTAJES
  
  #CREAR DATA FRAME
  df <- data.frame(Sequence = rep(basename(file_path), length(percentages)),
                   Base = names(percentages),
                   Percentage = as.numeric(percentages)) 
  sequence_data[[i]] <- df  #ALMACENAR EN LISTA
} 

combined_data <- do.call(rbind, sequence_data) #COMBINA DATA FRAMES
#CREAR GRAFICAS
ggplot(combined_data, aes(x = Sequence, y = Percentage, fill = Base)) + geom_bar(stat = "identity", position = "fill") + labs(title = "Nucleotide Composition of DNA Sequences", x = "Sequence File", y = "Percentage (%)", fill = "Nucleotide") + theme_minimal() + theme(axis.text.x = element_text(angle = 45, hjust = 1))

#==========================================================================================

#FUNCIÓN PARA CALCULAR PORCENTAJE DE GC EN CADA VARIANTE

leer_fasta_y_sumar_GC <- function(file_name) {  #CREAR FUNCION
  sequences <- tryCatch({
    read.fasta(file = file_name, seqtype = "DNA")
  }, error = function(e) {    #VERIFICAR PARA ERROR
    cat("Error reading file: ", file_name, "\nError message: ", e$message, "\n")
    return(NULL)
  })
  
  if (is.null(sequences)) {
    return(NULL)
  }
  
  dna_sequence<- sequences[[1]]
  dna_sequence<- paste(dna_sequence, collapse = "")
  total_nucleotides<-nchar(dna_sequence)
  
  #SUMA DE G Y C
  percentageC<- sum(strsplit(dna_sequence, "")[[1]]=="c")/total_nucleotides*100
  percentageG<- sum(strsplit(dna_sequence, "")[[1]]=="g")/total_nucleotides*100
  
  return(percentageG+percentageC)
}

#CICLAMOS
for (file in fasta_files) {
  GC_sum <- leer_fasta_y_sumar_GC(file)
  if (!is.null(GC_sum)) {
    cat("El contenido de GC de", basename(file), " es: ", GC_sum, "\n")
  }
}

#=========================================================================================

#FUNCIÓN PARA CREAR SECUENCIAS COMPLEMENTARIAS EN REVERSA DE CADA VARIANTE
leer_fasta_y_complementar_reversear <- function(file_name) {   #CREAR FUNCION
  sequences <- tryCatch({
    read.fasta(file = file_name, seqtype = "DNA")   #ERROR
  }, error = function(e) {
    cat("Error reading file: ", file_name, "\nError message: ", e$message, "\n")
    return(NULL)
  })
  
  if (is.null(sequences)) {
    return(NULL)
  }
  
  dna_sequence<- sequences[[1]]
  dna_sequence<- paste(dna_sequence, collapse = "")
  
  #CREAMOS COMPLEMENTARIA
  complementarySequence<- chartr("atgc","tacg",dna_sequence)
  
  #PONEMOS EN REVERSA LA COMPLEMENTARIA
  reverseComplementSequence <- rev(strsplit(complementarySequence, "")[[1]])
  
  #Convert the list back to a single string
  return(paste0(reverseComplementSequence, collapse = ''))
}

#CICLAMOS
for (file in fasta_files) {
  DNA_comp<- leer_fasta_y_complementar_reversear(file)
  if (!is.null(DNA_comp)) {
    cat("\nLa secuencia complementaria en reversa de ADN de ", basename(file), " es: \n", DNA_comp, "\n")
  }
}

#==========================================================================================

#INTERPRETACIÓN ESCRITA DE LAS GRÁFICAS
