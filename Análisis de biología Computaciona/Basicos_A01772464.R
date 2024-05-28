#Leobardo de Jesús Carbajal
#Brisa Sofia León Pérez

#1.	Crear un vector x con los datos 10, 11, 13, −1, 6,3

x <- c(10, 11, 13, -1, 6, 3)



#2.	Calcula estadísticas simples de x. Calcular la media, la desviación estándar y la varianza. 
#Crear un objeto (vector) con el nombre est.x en el que guardar los 3 estadísticos.


# Vector de ejemplo
x <- c(10, 20, 30, 40, 50)

# media
media <- mean(x)

# desviación estándar
desviacion_estandar <- sd(x)

# varianza
varianza <- var(x)

#objeto vector
est.x <- c(media, desviacion_estandar, varianza)

#resultados
est.x


# Ejercicio 4

#secuencia
20:50 
#media
mean (20:60) 
#suma
sum(51:91) 



#Ejercicio 4

#vector con 10 valores aleatorios entre -100 y +50
vector_aleatorio <- sample(-100:50, 10, replace = TRUE)

#vector generado
print(vector_aleatorio)

#ejercicio 5
fb <- numeric(10)
fb[1] <- fb[2] <- 1
for (i in 3:10) {
  fb[i] <- fb[i - 1] + fb[i - 2]
}
print(fb)


#Ejercicio 6
vector_a <- c(10, 20, 30, 4, 50, -60)

maximo <- max(vector_a)
print(maximo)

minimo <- min(vector_a)
print(minimo)


#7.	Ejercicio 7

vector_a <- c(10,20)
vector_b <- c(3,4)

producto <- vector_a * vector_b
print(producto)



#8.Ejercicio 8


cuenta <- function(vector, valor) {
  cantidad <- sum(vector == valor)
  return(cantidad)
}

resultado <- cuenta(c(10, 20, 10, 7, 24, 7, 5), 7)
print(resultado) 


#ejecicio 9
enesimo <- function(vec, num) {
  return(vec[seq(from = 1, to = length(vec), by = num)])
}
v <- 1:100
enesimo(v, 5)





