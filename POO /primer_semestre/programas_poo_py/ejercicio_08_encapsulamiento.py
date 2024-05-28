class Persona():
    def __init__(self,p_nom = "NA", p_ap = "NA", p_am = "NA", p_edad = 0):
        self.__nom = p_nom
        self.ap = p_ap
        self.am = p_am
        self.edad = p_edad

    def __del__(self):
        pass

    def despliega(self):
        print("Nombre           : ",self.__nom)
        print("Apellido paterno : ",self.ap)
        print("Apellido materno : ",self.am)
        print("Edad             : ",self.edad)

#termina la clase persona

obj1 = Persona(p_nom = "Juan", p_ap = "Pérez", p_am = "López", p_edad = 15)
obj1.despliega()
print("-"*60)

obj1.nom = "Cambia"
obj1.despliega()
print("-"*60)

obj2 = Persona(p_nom = "Armando", p_ap = "Arias", p_am = "Baca", p_edad = 35)
obj2.despliega()
print("-"*60)

obj2 = Persona(p_nom = "Bernardo", p_ap = "Becerril", p_am = "Baca", p_edad = 45)
obj2.despliega()
print("-"*60)



