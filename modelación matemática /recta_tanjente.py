'''
Determinación de la Recta Tangente en un punto
de la curva y=f(x)
Importamos las librerías
'''
import numpy as np
from scipy.misc import derivative
import matplotlib.pyplot as plt
def f(x):
    return np.cos(x**2)+np.exp(np.sqrt(x))

def df(f,x):
    return derivative(f, x, dx=1e-8)

def recta(f, df, x, a):
    return f(a) + df(f, a)*(x-a)

#Graficas
a = 1
xx = np.linspace(0, 2, 1000)
plt.style.use('classic')
plt.plot(xx, f(xx), label=r'f(x)')
plt.plot(xx, recta(f, df, xx, a), label='Recta Tangente')
plt.legend()
plt.grid()
plt.show()