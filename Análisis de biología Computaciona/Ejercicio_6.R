# Exercise 6
# Define a function to reverse the DNA sequence
reverseDNA <- function(dnaSequence){
  # Reverse the order of the sequence
  reversedSequence <- rev(strsplit(dnaSequence, "")[[1]])
  
  # Convert the list back to a single string
  return(paste0(reversedSequence, collapse = ""))
}

# Example usage
# Reverse a DNA sequence
dnaSequence <- "ATCGATCGATCG"
reversedDNA <- reverseDNA(dnaSequence)  
print(reversedDNA)
