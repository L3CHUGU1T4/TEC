# Ejercicio 8
# Define a function to find the reverse complement of a DNA strand
findReverseComplementDNA <- function(dnaSequence) { 
  # Replace each nucleotide with its complement
  complementarySequence <- chartr("ATGC", "TACG", dnaSequence)
  
  # Reverse the order of the complementary sequence
  reverseComplementSequence <- rev(strsplit(complementarySequence, "")[[1]])
  
  # Convert the list back to a single string
  return(paste0(reverseComplementSequence, collapse = ""))
}

# Example usage:
# Get the reverse complement of a given DNA sequence
dnaSequence <- "ATCGATCGATCG"
reverseComplementDNA <- findReverseComplementDNA(dnaSequence)
print(reverseComplementDNA)
