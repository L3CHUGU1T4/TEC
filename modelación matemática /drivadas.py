from sympy import *
from scipy.misc import derivative

x = Symbol ('x')

y = 2 * x**3 - 5 * x**2 + x - 1
derivada = y.diff(x)
print(derivada)
f = lambda x : 2 * x**3 - 5 * x**2 + x - 1
print(derivative(f,1,dx=1e-8))