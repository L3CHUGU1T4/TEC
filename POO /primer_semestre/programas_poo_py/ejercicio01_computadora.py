class Computadora():
    disco_duro = "500 Mb"
    Memoria = "8 Gb Ram"
    Procesador = "Core i5 1.8 Ghz"
    Monitor = "14'' No Touch"

    def despliega(self):
        print("disco_dura : ",self.disco_duro)
        print("Memoria    : ",self.Memoria)
        print("Procesador : ",self.Procesador)
        print("Monitor    : ",self.Monitor)

#Termina la clase Computadora 

print("-"*50)

modelo1 = Computadora()
modelo1.despliega()

print("-"*50)

modelo2 = Computadora()
modelo2.disco_duro = "1 Tb"
modelo2.Memoria = "16 Gb Ram"
modelo2.Procesador = "Core i7 2.8 Ghz"
modelo2.Monitor = "16\"  Touch"

#en la linea anterios el back salsh (\) se utilioza para poder utilizar las comillas dentro de un print sin afectar las comillas del print 

modelo2.despliega()

print("-"*50)

modelo3 = Computadora()
modelo3.disco_duro = "256gb SSD"
modelo3.Memoria = "8 Gb Ram"
modelo3.Procesador = "AMD Athlon"
modelo3.Monitor = "15.6\" No Touch"
modelo3.despliega()

print("-"*50)

modelo4 = Computadora()
modelo4.disco_duro = "SSD de 512GB"
modelo4.Memoria = "8GB de RAM"
modelo4.Procesador = "AMD Ryzen 5 7535Hs"
modelo4.Monitor = "15.6\" 144Hz"
modelo4.despliega()

print("-"*50)

modelo5 = Computadora()
modelo5.disco_duro = "500GB de HDD"
modelo5.Memoria = "4GB de RAM"
modelo5.Procesador = "INTEL Core i3-1005G1"
modelo5.Monitor = "14\" HD LED"
modelo5.despliega()

print("-"*50)

modelo6 = Computadora()
modelo5.disco_duro = "512GB SSD"
modelo6.Memoria = "16GB de RAM"
modelo6.Procesador = "Intel Core i5-11400H"
modelo6.Monitor = "17.3\" FHD"
modelo6.despliega()

print("-"*50)