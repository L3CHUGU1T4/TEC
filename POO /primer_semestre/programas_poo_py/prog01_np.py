class Persona():
    nom = "Juan"
    ap = "Pérez"
    am = "Lopez"
    edad = 19

    def despliega(self):
        print("Nombre      : ",self.nom)
        print("Ap Paterno  : ",self.ap)
        print("Ap materno  : ",self.am)
        print("Edad        : ",self.edad)

#termina la calse Persona

obj1 = Persona()
obj1.despliega()

print("-"*50)

obj2 = Persona()
obj2.nom = "Pancho"
obj2.ap = "Pantera"
obj2.am = "Pistolas"
obj2.edad = 32
obj2.despliega()

print("-"*50)

obj1.despliega()

print("-"*50)

obj3 = Persona()
obj3.nom = "Leobardo"
obj3.ap = "De Jesús"
obj3.am = "Carbajal"
obj3.edad = 18
obj3.despliega()

print("-"*50)

obj4 = Persona()
obj4.nom = "Maria Fernanda"
obj4.ap = "Paez"
obj4.am = "Ruiz"
obj4.edad = 18
obj4.despliega()

print("-"*50)

obj5 = Persona()
obj5.nom = "Jose Emilio"
obj5.ap = "garcía"
obj5.am = "Gómez"
obj5.edad = 18
obj5.despliega()

print("-"*50)
