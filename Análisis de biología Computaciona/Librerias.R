#Leobardo de Jesús Carbajal A01772464
install.packages("BiocManager")
BiocManager::install("Biostrings")
library(Biostrings)

#Looking for useful built in functions  tips para encontrar funciones, etc
apropos("sample")
?sample
browseVignettes(package="Biostrings")

#Exercicse 1 definir la funcion de genrar un dna ramdom 
generateDNASequense <- function(n){
  #Definir los nucleotidos
  nucleotides <-c("A","C","G","T")
  
  dnaSequence <- sample(nucleotides,n,replace = TRUE)
  return(DNAString(paste(dnaSequence, collapse = "")))
}

#Ejemplo de uso 
randomDNA <- generateDNASequense(114)
print(randomDNA)



