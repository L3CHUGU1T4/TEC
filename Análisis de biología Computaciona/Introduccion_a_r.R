# This is a comment

#tipos de variables 

#string
name <- "leo"

#numeric value

a <- 12.23

#Bool

c <- TRUE

# Asignación de variables 
x <- 5L #De preferencia usar este método 
y = 10 #Puede generar problemas con programas mas pesados

x <- 5
class(x) # Para saber el tipo de dato que es 

x <- 5
y <- 10
x + y # suma 
x == y #comparación 
x < y & y > 5  # condicionantes

x <- c(1, 2, 3, 4, 5) #vectores utilizan c 
mean(x) #media de los elementos del vector 

#lista

e <- list(name="leo", age = 30, employed = TRUE)
print(e)

# Condicionantes 

if (condition) {
  #code to excute if condition is true
} 
else {
  #code to excute if condition is false
}

#Example
x <- 5

if (x < 10){
  print("x is less than 10")
}else {
  print("X is greater than or equal to 10")
}

# For loop

for (variable in sequence) {
  #code to excute 
}

# Example

for (i in 1:5) {
  print(i)
}

# While loop

while (condition) {
  #la condicion 
}

#example 

x<- 5
while (x > 0) {
  print(x)
  x <- x -1
}

#Funcione 

function_name <- function(arg1, arg2, ...) {
  #code to excute 
  return (output)
}

#function example

multiply <- function(x, y) {
  return(x * y)
}

result <- multiply(2, 3)
print(result)

#Using a variable to index a vector 

numbers <- c(1, 2, 3, 4, 5)
index <- 3
print(numbers[index])

#converting a character string to a numeric avalue

x <- "3.14"
y <- as.numeric(x)

#Example of creating a scatter plot whit numeric data

x<- c(1, 2, 3, 4, 5)
y <- c(3.14, 2.71, 1.62, 4.33, 5.55)
plot(x,y)











