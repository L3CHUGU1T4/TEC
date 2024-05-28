library(ggplot2)
library(dplyr)

# Function to read sequence from text file
read_sequence_from_txt <- function(file_path) { 
  seq <- readLines(file_path)
  seq <- paste(seq, collapse = "")
  return(seq)
}

# Function to calculate the size of the sequence
calculate_sequence_size <- function(sequence) { 
  return(nchar(sequence))
}

# Function to calculate nucleotide composition
calculate_nucleotide_composition <- function(sequence) { 
  nucleotides <- table(strsplit(sequence, "")[[1]])
  nucleotide_percentage <- (nucleotides / nchar(sequence)) * 100
  return(nucleotide_percentage)
}

# Function to calculate GC content
calculate_gc_content <- function(sequence) { 
  gc_content <- (sum(strsplit(sequence, "")[[1]] == "G" | strsplit(sequence, "")[[1]] == "C") / nchar(sequence)) * 100
  return(gc_content)
}

# Function to get the complementary sequence
get_complementary_sequence <- function(sequence) { 
  complementary_sequence <- chartr("ATCG", "TAGC", sequence)
  return(complementary_sequence)
}

# Update the folder path to the path you provided
folder_path <- "/Users/leodejesus/Desktop/all/escuela/segundo semestre/Biologia_computacional/txt"

file_paths <- list.files(folder_path, full.names = TRUE) # List files in the folder

sequence_data <- list()

# Process each file in the folder
for (file_path in file_paths) {
  sequence <- read_sequence_from_txt(file_path)
  sequence_size <- calculate_sequence_size(sequence)
  nucleotide_composition <- calculate_nucleotide_composition(sequence)
  gc_content <- calculate_gc_content(sequence)
  complementary_sequence <- get_complementary_sequence(sequence)
  
  # Print results
  cat("\n")
  cat("Processing file:", file_path, "\n")
  cat("Original sequence:", sequence, "\n")
  cat("Sequence size:", sequence_size, "nucleotides\n")
  cat("Nucleotide composition:\n")
  cat("A:", nucleotide_composition["A"], "(", round(nucleotide_composition["A"], 2), "%)\n")
  cat("C:", nucleotide_composition["C"], "(", round(nucleotide_composition["C"], 2), "%)\n")
  cat("G:", nucleotide_composition["G"], "(", round(nucleotide_composition["G"], 2), "%)\n")
  cat("T:", nucleotide_composition["T"], "(", round(nucleotide_composition["T"], 2), "%)\n")
  cat("GC content:", gc_content, "%\n")
  cat("Complementary sequence:", complementary_sequence, "\n")
  
  # Dataframe for ggplot
  df <- data.frame(Sequence = rep(basename(file_path), length(nucleotide_composition)),
                   Base = names(nucleotide_composition),
                   Percentage = as.numeric(nucleotide_composition))
  
  sequence_data[[length(sequence_data) + 1]] <- df 
}

# Combine all data frames into one
combined_data <- do.call(rbind, sequence_data)

# Plot the data
ggplot(combined_data, aes(x = Sequence, y = Percentage, fill = Base)) + 
  geom_bar(stat = "identity", position = "fill") +
  labs(title = "Nucleotide Composition of DNA Sequences", x = "Sequence File", y = "Percentage (%)", fill = "Nucleotide") + 
  theme_minimal() + 
  theme(axis.text.x = element_text(angle = 45, hjust = 1))
