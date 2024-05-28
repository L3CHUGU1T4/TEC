import os
import shutil
import utilerias as ut

obj_ut = ut.Utilerias()

class Juego_BN:
    def __init__(self, nuevo_juego=False):
        self.matriz = []
        self.file = ""
        self.aciertos = 0
        self.fallos = 0
        self.base_file = "inicial.csv"  # Archivo base

        if nuevo_juego:
            self.file = obj_ut.pide_cadena("📂 Indica el nombre del archivo para guardar la nueva partida: ", 1, 10) + ".csv"
            self.inicializa_matriz()
        else:
            self.mostrar_menu()
            self.file = obj_ut.pide_cadena("📂 Indica el nombre del archivo: ", 0, 10)
            if len(self.file) == 0:
                self.file = "inicial.csv"
                print("🆕 ¡Nuevo juego creado con el archivo inicial.csv!")
                self.inicializa_matriz()
            else:
                self.file += ".csv"
                print(f"📂 Cargando archivo {self.file}...")
                self.carga_matriz()

    def mostrar_menu(self):
        print("""
██████╗  █████╗ ████████╗ █████╗ ██╗     ██╗      █████╗     ███╗   ██╗ █████╗ ██╗   ██╗ █████╗ ██╗     
██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██║     ██║     ██╔══██╗    ████╗  ██║██╔══██╗██║   ██║██╔══██╗██║     
██████╔╝███████║   ██║   ███████║██║     ██║     ███████║    ██╔██╗ ██║███████║██║   ██║███████║██║     
██╔══██╗██╔══██║   ██║   ██╔══██║██║     ██║     ██╔══██║    ██║╚██╗██║██╔══██║╚██╗ ██╔╝██╔══██║██║     
██████╔╝██║  ██║   ██║   ██║  ██║███████╗███████╗██║  ██║    ██║ ╚████║██║  ██║ ╚████╔╝ ██║  ██║███████╗
╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝    ╚═╝  ╚═══╝╚═╝  ╚═╝  ╚═══╝  ╚═╝  ╚═╝╚══════╝
        """)
        print("================================================================")
        print("| 🕹️  ¡Bienvenido al Juego de Batalla Naval! 🕹️                   |")
        print("| Para comenzar, ingresa el nombre del archivo que deseas       |")
        print("| cargar. Si deseas un juego nuevo, simplemente presiona [ENTER]|")
        print("| Escribe el nombre del archivo sin extensión                   |")
        print("================================================================")

    def inicializa_matriz(self):
        if not os.path.exists(self.base_file):
            obj_ut.error(f"❌ El archivo base {self.base_file} no existe")
            return

        shutil.copy(self.base_file, self.file)
        self.carga_matriz()

    def carga_matriz(self):
        print(f"📂 Archivo: {self.file}")
        if os.path.exists(self.file):
            with open(self.file, "r") as arch:
                self.matriz = []  # Reiniciar la matriz para evitar duplicación
                ren = 0
                for registro in arch.readlines():
                    registro = registro.strip()  # Elimina el salto de línea del final de cada renglón
                    lista = registro.split(",")
                    self.matriz.append([])
                    for col in range(8):
                        self.matriz[ren].append(lista[col])
                        # Sumar aciertos y fallos al cargar la matriz
                        if lista[col] == "A":
                            self.aciertos += 1
                        elif lista[col] == "X":
                            self.fallos += 1
                    ren += 1
            print("📊 Matriz cargada exitosamente!")
        else:
            obj_ut.error("❌ Error, el archivo no existe")
            self.matriz = None  # Establecer matriz a None si el archivo no existe

    def muestra_matriz(self):
        if self.matriz is None:  # Verificar si la matriz es None antes de mostrarla
            print("⚠️ No hay matriz cargada para mostrar.")
            return
        
        print("\n   0 1 2 3 4 5 6 7 ")
        print("  " + ("-" * 17))
        for ren in range(8):
            print(str(ren) + "|", end="")
            for col in range(8):
                if self.matriz[ren][col] == "V" or self.matriz[ren][col] == "B":
                    print(" ", end="|")
                else:
                    print(self.matriz[ren][col], end='|')
            if ren == 0:
                print(f"     🎯 ACIERTOS = {self.aciertos}", end="")
            if ren == 1:
                print(f"     ❌ FALLOS   = {self.fallos}", end="")
            print("")
            print("  " + "-" * 17)

    def descarga_matriz(self, nombre_file=None):
        if nombre_file is None:
            nombre_file = self.file
        with open(nombre_file, "w") as arch:
            for ren in range(8):
                registro = ""
                for col in range(8):
                    registro += self.matriz[ren][col] + ","
                registro = registro[:-1] + "\n"
                arch.write(registro)
        print(f"💾 Archivo {nombre_file} guardado exitosamente!")

    def mostrar_mensaje_panico(self):
        print("""
██████╗  █████╗ ███╗   ██╗██╗ ██████╗ ██████╗     ██╗██╗██╗
██╔══██╗██╔══██╗████╗  ██║██║██╔════╝██╔═══██╗    ██║██║██║
██████╔╝███████║██╔██╗ ██║██║██║     ██║   ██║    ██║██║██║
██╔═══╝ ██╔══██║██║╚██╗██║██║██║     ██║   ██║    ╚═╝╚═╝╚═╝
██║     ██║  ██║██║ ╚████║██║╚██████╗╚██████╔╝    ██╗██╗██╗
╚═╝     ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝ ╚═════╝ ╚═════╝     ╚═╝╚═╝╚═╝
        """)
        obj_ut.error("😱 ¡Pánico! Partida guardada.")

    def tiro(self, ren, col):
        if ren == 8 and col == 8:
            nombre_file = obj_ut.pide_cadena("💾 Indica el nombre del archivo para guardar la partida: ", 1, 10) + ".csv"
            self.descarga_matriz(nombre_file)
            self.mostrar_mensaje_panico()
        elif ren == 8 or col == 8:
            self.descarga_matriz()
        else:
            if self.matriz[ren][col] == "A" or self.matriz[ren][col] == "X":
                obj_ut.error("❌ Error, ya hay un tiro previo en esa celda")
            else:
                if self.matriz[ren][col] == "V":
                    obj_ut.error("🌊 Celda vacía, se incrementan los errores")
                    self.fallos += 1
                    self.matriz[ren][col] = "X"
                else:
                    obj_ut.error("🚢 ¡Celda con barco! Se incrementan los aciertos")
                    self.aciertos += 1
                    self.matriz[ren][col] = "A"

if __name__ == "__main__":
    opcion = obj_ut.pide_entero("Selecciona una opción (1 para nuevo juego, 2 para cargar juego): ", 1, 2)
    if opcion == 1:
        juego = Juego_BN(nuevo_juego=True)
    elif opcion == 2:
        juego = Juego_BN()
    juego.muestra_matriz()
