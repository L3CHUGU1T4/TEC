import Juego_BN as jbn
import utilerias as ut

def mostrar_menu_principal():
    print("""
██████╗  █████╗ ████████╗ █████╗ ██╗     ██╗      █████╗     ███╗   ██╗ █████╗ ██╗   ██╗ █████╗ ██╗     
██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██║     ██║     ██╔══██╗    ████╗  ██║██╔══██╗██║   ██║██╔══██╗██║     
██████╔╝███████║   ██║   ███████║██║     ██║     ███████║    ██╔██╗ ██║███████║██║   ██║███████║██║     
██╔══██╗██╔══██║   ██║   ██╔══██║██║     ██║     ██╔══██║    ██║╚██╗██║██╔══██║╚██╗ ██╔╝██╔══██║██║     
██████╔╝██║  ██║   ██║   ██║  ██║███████╗███████╗██║  ██║    ██║ ╚████║██║  ██║ ╚████╔╝ ██║  ██║███████╗
╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝    ╚═╝  ╚═══╝╚═╝  ╚═╝  ╚═══╝  ╚═╝  ╚═╝╚══════╝
    """)
    print("================================================================")
    print("| 🕹️  Menú Principal                                            |")
    print("| 1. Nuevo juego                                                |")
    print("| 2. Cargar juego                                               |")
    print("| 3. Guardar juego                                              |")
    print("| 4. Salir                                                      |")
    print("================================================================")

def mostrar_mensaje_derrota():
    print("""
██████╗ ███████╗██████╗ ██████╗ ██╗███████╗████████╗███████╗                ██╗
██╔══██╗██╔════╝██╔══██╗██╔══██╗██║██╔════╝╚══██╔══╝██╔════╝        ██╗    ██╔╝
██████╔╝█████╗  ██████╔╝██║  ██║██║███████╗   ██║   █████╗          ╚═╝    ██║ 
██╔═══╝ ██╔══╝  ██╔══██╗██║  ██║██║╚════██║   ██║   ██╔══╝          ██╗    ██║ 
██║     ███████╗██║  ██║██████╔╝██║███████║   ██║   ███████╗        ╚═╝    ╚██╗
╚═╝     ╚══════╝╚═╝  ╚═╝╚═════╝ ╚═╝╚══════╝   ╚═╝   ╚══════╝                ╚═╝
    """)

obj_ut = ut.Utilerias()
opcion = 0

while opcion != 4:
    mostrar_menu_principal()
    opcion = obj_ut.pide_entero("Selecciona una opción: ", 1, 4)
    
    if opcion == 1:
        obj_jbn = jbn.Juego_BN(nuevo_juego=True)
        obj_jbn.muestra_matriz()
        if obj_jbn.matriz is not None:
            while obj_jbn.aciertos < 9 and obj_jbn.fallos < 10:
                ren = obj_ut.pide_entero("Indica el renglón de tiro: ", 0, 8)
                col = obj_ut.pide_entero("Indica la columna de tiro: ", 0, 8)
                if ren == 8 and col == 8:
                    obj_jbn.tiro(ren, col)
                    break
                obj_jbn.tiro(ren, col)
                obj_jbn.muestra_matriz()

            if obj_jbn.aciertos == 9:
                obj_ut.error("🏆 ¡Has ganado el juego!")
            elif not (ren == 8 and col == 8):
                mostrar_mensaje_derrota()

    elif opcion == 2:
        obj_jbn = jbn.Juego_BN()
        if obj_jbn.matriz is not None:
            obj_jbn.muestra_matriz()
            while obj_jbn.aciertos < 9 and obj_jbn.fallos < 10:
                ren = obj_ut.pide_entero("Indica el renglón de tiro: ", 0, 8)
                col = obj_ut.pide_entero("Indica la columna de tiro: ", 0, 8)
                if ren == 8 and col == 8:
                    obj_jbn.tiro(ren, col)
                    break
                obj_jbn.tiro(ren, col)
                obj_jbn.muestra_matriz()

            if obj_jbn.aciertos == 9:
                obj_ut.error("🏆 ¡Has ganado el juego!")
            elif not (ren == 8 and col == 8):
                mostrar_mensaje_derrota()

    elif opcion == 3:
        if 'obj_jbn' in globals():
            obj_jbn.descarga_matriz()
        else:
            obj_ut.error("❌ No hay un juego en progreso para guardar.")

print("👋 ¡Gracias por jugar a Batalla Naval!")
