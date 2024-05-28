class Computadora():
    
    def __init__(self, p_disco_duro = "NA", p_memoria = "NA", p_procesador = "NA", p_monitor = "NA"):
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

modelo1 = Computadora("256 Gb", "8 GB RAM", "Core i5 2.4 GHz", "14\" No Touch")
modelo1.despliega()

print("-"*60)

modelo2 = modelo1
modelo2.disco_duro = "512 Gb"
modelo2.despliega()

print("-"*60)

modelo3 = modelo2
modelo3.memoria = "12 Gb RAM"
modelo3.despliega()

print("-"*60)

modelo4 = modelo1
modelo4.disco_duro = "1 Tb"
modelo4.memoria = "16Gb RAM"
modelo4.despliega()