class Computadora():
    
    def __init__(self, p_disco_duro = "256 Gb", p_memoria = "8 GB RAM", p_procesador = "Core i5 2.4 GHz", p_monitor = "14\" No Touch"):
        self.disco_duro = p_disco_duro
        self.memoria = p_memoria
        self.procesador = p_procesador
        self.monitor = p_monitor
    
    def despliega(self):
        print("Disco duro  : ",self.disco_duro)
        print("Memoria     : ",self.memoria)
        print("Procesador  : ",self.procesador)
        print("Monitor     : ",self.monitor)
    
#termina la clase Computadora

print("-"*60)

modelo1 = Computadora()
modelo1.despliega()

print("-"*60)

modelo2 = Computadora(p_disco_duro = "512 Gb")
modelo2.despliega()
print("-"*60)

modelo3 = Computadora(p_disco_duro = "512 Gb", p_memoria = "12 GB RAM")
modelo3.despliega()

print("-"*60)

modelo4 = Computadora(p_disco_duro = "1Tb", p_memoria = "16 Gb RAM")
modelo4.despliega()

print("-"*60)

modelo5 = Computadora(p_disco_duro = "8 Tb")
modelo5.despliega()

print("-"*60)
