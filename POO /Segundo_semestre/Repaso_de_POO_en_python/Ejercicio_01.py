#Realice un programa que cree la clse "Computadora" y el objeto "modelo1" y muestre las propiedades de la computadora: Disco duro, memoria, procesador y monitor.
class Computadora(): #Creamos la clase Computadora
    disco_duro = "500 Mb"
    memoria = "8Gb RAM"
    procesador = "Core i5 2.8 GHz"
    monitor = "14'' No Touch"

    def modelo1(self):

        print("Disco Duro : ",self.disco_duro)    
        print("Memoria    : ",self.memoria)
        print("Procesador : ",self.procesador)
        print("Monitor    : ",self.monitor)    

#Fin de la clase Computadora
computadora1 = Computadora()
computadora1.modelo1()