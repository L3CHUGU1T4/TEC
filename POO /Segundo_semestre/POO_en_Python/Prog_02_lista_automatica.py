"""
Crear una matriz de 8 x 8 

Estados de una celda:
"""
matriz = []

# Función para crear la matriz automáticamente 
def crea_matriz():
    global matriz
    for ren in range(8):
        matriz.append([])
        for col in range(8):
            matriz[ren].append("V")
    matriz[1][2] = "B"
    matriz[1][3] = "B"
    matriz[3][6] = "B"
    matriz[4][6] = "B"
    matriz[5][6] = "B"
    matriz[6][0] = "B"
    matriz[6][1] = "B"
    matriz[6][2] = "B"
    matriz[6][3] = "B"

# Función para mostrar la matriz en orden 

def muestra_matriz():
    global matriz
    print("-"*17)
    for ren in range(8):
        print("|", end ="")
        for col in range(8):
            print(matriz[ren][col], end="|")
        print("")
        print("-"*17)

#Funcion para descargar el contenido de una matriz en un archivo de tipo .csv
def descarga_matriz_file():
    nombre_file = input("Indica el nombre del archivo: ")
    nombre_file += ".csv"
    arch = open(nombre_file, "w") 
    for ren in range(8):
        registro = ""
        for col in range(8):
            registro += matriz[ren][col] + ","
        registro = registro[:-1] + "\n"  
        arch.write(registro)
    arch.close()

#Función para cargar archivos de una matriz
def carga_matriz_file():
    nombre_file = input("Indica el nombre del archivo: ")
    nombre_file += ".csv"
    arch = open(nombre_file,"r")
    ren = 0
    for registro in arch.readlines():
        registro = registro[:-1]
        lista = registro.split(",")
        matriz.append([])
        for col in range(8):
            matriz[ren].append(lista[col])
        ren += 1
    arch.close()


# Crear la matriz y luego descargar a un archivo
#crea_matriz()
#descarga_matriz_file()
carga_matriz_file()
muestra_matriz()