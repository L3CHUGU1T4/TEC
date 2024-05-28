# Matriz creada de manera manual
matriz = [["A","B","C", "D"],["E","F","G","H"],["I","J","K","L"],["M","N","O","P"]]

# Imprimir la matriz
for ren in range(4):
    for col in range(4):
        print(matriz[ren][col], end=' ')
    print()

# Imprimir valor específico de la matriz
print("(3,1)=", matriz[3][1])  
