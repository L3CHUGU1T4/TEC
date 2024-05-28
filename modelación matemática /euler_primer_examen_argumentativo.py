'''
Código escrito por Leobardo de Jesús Carbajal
Primer Examen argumentativo 
Ejercicio 3 Método de euler
'''

from termcolor import colored #si no funciona el código elimina esta libreria 
import numpy as np

def df(y):  
    return y

def solucion_exacta(x):  # Solución exacta de la ecuación diferencial
    return 0.1 * np.exp(x)

# Condiciones iniciales
x0 = 0
y0 = 0.1

# Tamaño de paso
h = 0.1

# Número de pasos para llegar a x = 0.3 con h = 0.1
n = int(0.3 / h)

# Listas para almacenar los valores de x y y
x = [x0]
y = [y0]

# Método de Euler
for i in range(n):
    yn = y0 + h * df(y0)  # Calculamos y_n
    x0 += h  # Incrementamos x_n
    y0 = yn  # Actualizamos y0 para la siguiente iteración
    x.append(x0)  # Agregamos el valor de x_n a la lista de x
    y.append(y0)  # Agregamos el valor de y_n a la lista de y

# Calculamos el valor exacto para comparar
y_exacto = solucion_exacta(0.3)

# Imprimimos los resultados
print(colored(f"El valor aproximado de y(0.3) usando el Método de Euler es: {y[-1]}", 'green'))    # si el código arroja algún error eliminar colored(   y   , 'green')     de estas lineas de código
print(colored(f"El valor exacto de y(0.3) es: {y_exacto}", 'green'))                               # si el código arroja algún error eliminar colored(   y   , 'green')     de estas lineas de código




