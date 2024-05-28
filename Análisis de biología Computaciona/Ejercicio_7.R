# Ejercicio 7
# Define a function to find the complementary DNA strand
findComplementaryDNA <- function(dnaSequence) {
  # Replace each nucleotide with its complement
  complementarySequence <- chartr("ATGC", "TACG", dnaSequence)
  
  # Return the complementary DNA sequence
  return(complementarySequence)
}

# Example usage:
# Get the complementary DNA strand of a given sequence
dnaSequence <- "ATCGATCGATCG"
complementaryDNA <- findComplementaryDNA(dnaSequence)  
print(complementaryDNA)
