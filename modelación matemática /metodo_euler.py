#Método de Euler
#Importar las librerías
import numpy as np
from matplotlib import pyplot as plt
def df(y): #y'=y
    f = y
    return f
def funcion(x): #Solución exacta
    fun = 3*np.exp(x)
    return fun
#Condiciones iniciales
x0 = 0
y0 = 3
#Tamaño de paso
h = 0.4
#Numero de iteraciones
n = 2
x = np.array([x0])
y = np.array([y0])
for i in range(1,n+1):
    yn = y0 + h * df(y0)
    x0 = x0 +h
    y0 = yn
    x = np.append(x, x0)
    y = np.append(y, y0)

#Graficación
xp = np.linspace(0,0.8, 100)
plt.figure()
plt.plot(x, y) #Grafica método de Euler
plt.plot(xp, funcion(xp)) #Grafica solución exacta
plt.xlabel('x')
plt.ylabel('y')
plt.legend(['Euler', 'Exacto'])
plt.title('Método de Euler')
plt.grid()
plt.show()
print('x =', x)
print('y =', y)