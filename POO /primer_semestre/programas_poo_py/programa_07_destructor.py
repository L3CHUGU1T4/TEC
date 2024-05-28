class Persona():
    def __init__(self,p_nom = "NA", p_ap = "NA", p_am = "NA", p_edad = 0):
        self.nombre = p_nom
        self.apellido_paterno = p_ap
        self.apellido_materno = p_am
        self.edad = p_edad

    def __del__(self):
        pass

    def despliega(self):
        print("Nombre : ",self.nombre)
        print("Apellido paterno : ",self.apellido_paterno)
        print("Apellido materno : ",self.apellido_materno)
        print("Edad : ",self.edad)

#termina la clase persona

obj1 = Persona(p_nom = "Juan", p_ap = "Pérez", p_am = "López", p_edad = 15)
obj1.despliega()

print("-"*60)

obj2 = Persona()
obj2.despliega()

print("-"*60)

del(obj2)
obj2.despliega()




