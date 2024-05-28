class Persona():
    def __init__(self):
        self.nom = "Juan"
        self.ap = "Pérez"
        self.am = "López"
        self.edad = 15

    def despliega(self):
        print("Nombre             : ", self.nom)
        print("Apellido materno   : ", self.ap)
        print("Apellido paterno   : ", self.am)
        print("Edad               : ", self.edad)

#termina la clase Persona

print("-"*60)

pancho = Persona()
pancho.despliega()

print("-"*60)
