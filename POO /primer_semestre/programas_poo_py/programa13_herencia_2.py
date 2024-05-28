class Persona():
    def __init__(self, p_nom, p_ap, p_am, p_edad):
        self.nom = p_nom 
        self.ap = p_ap
        self.am = p_am
        self.edad = p_edad

    def __del__(self):
        pass

    def despliega(self):
        print("Nombre            : ",self.nom)
        print("Apellido paterno  : ",self.ap)
        print("Apellido materno  : ",self.am)
        print("Edad              : ",self.edad)

#termina la clase persona

class Estudiante(Persona):
    def __init__(self, p_nom, p_ap, p_am, p_edad, p_mat, p_car):
        super().__init__(p_nom, p_ap, p_am, p_edad)
        self.mat =p_mat
        self.car = p_car

    def despliega(self):
        print("Matrícula         : ", self.mat)
        super().despliega()
        print("Carrera           : ", self.car)

class Deportista(Estudiante):
    def __init__(self, p_nom, p_ap, p_am, p_edad, p_mat, p_car, p_deporte):
         super().__init__(p_nom, p_ap, p_am, p_edad, p_mat, p_car)
         self.deporte = p_deporte
    
    def despliega(self):
        super().despliega()
        print("Deporte           : ",self.deporte)


print("-"*50)
obj1 = Persona("Juan", "Pérez", "López", 20)
obj1.despliega()
print("-"*50)

est1 = Estudiante("Leobardo", "De Jesús", "Carbajal", 18, "A01772464", "ITC")
est1.despliega()
print("-"*50)

dep1 = Deportista("Bernardo", "bermudes", "Bernal", 15, "A1223567", "ITC", "Baloncesto")
dep1.despliega()
print("-"*50)
 