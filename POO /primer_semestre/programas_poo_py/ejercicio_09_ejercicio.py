class Autos():
    def __init__(self, p_marca = "",p_tipo = "", p_ver = "", p_elec = "", p_trans = "", p_este = "", p_cam = ""):
        self.__marca = p_marca
        self.__tipo = p_tipo
        self.__ver = p_ver
        self.__elec = p_elec
        self.__trans = p_trans
        self.__estereo = p_este
        self.__camara = p_cam

    def __del__(self):
        pass
        
    def despliega(self):
        print("{:11s}".format(self.__marca),end="")
        print("{:11s}".format(self.__tipo),end="")
        print("{:12s}".format(self.__ver),end="")
        print("{:11s}".format(self.__elec),end="")
        print("{:13s}".format(self.__trans),end="")
        print("{:9s}".format(self.__estereo),end="")
        print("{:6s}".format(self.__camara))

        
#Termina la clase 
print("="*72)
print("Marca  Tipo  Versión  Eléctrico  Transmisión  Estereo  Cámara")
print("="*72)   

obj1 = Autos("Nissan", "March", "Austero", "No", "manual", "No", "No")
obj1.despliega()
print("-"*72)

obj1 = Autos("Nissan", "March", "Lujo medio", "No", "Auto/Manual", "si", "No")
obj1.despliega()
print("-"*72)

obj1 = Autos("Seat", "Ibiza", "Austero", "No", "Manual", "Si", "No")
obj1.despliega()
print("-"*72)

del(obj1)

obj2 = Autos("BMW", "A3", "De lujo", "Si", "Automático", "Si", "Si")
obj2.despliega()
print("-"*72)

obj2 = Autos("Mitsubishi", "Outlander", "Estandar", "No", "Automático", "Si", "Si")
obj2.despliega()
print("-"*72)

del(obj2)

obj3 = Autos("Honda", "Civic", "Estandar", "No", "Estandar", "Si", "Si")
obj3.despliega()
print("-"*72)