class Persona():
  def __init__(self,p_nom="NA", p_ap="NA", p_am="NA", p_edad=0):
    self.nom = p_nom
    self.ap = p_ap
    self.am = p_am
    self.edad = p_edad

  def despliega(self):
    print("Nombre     : ",self.nom)
    print("Ap. Paterno: ",self.ap)
    print("Ap Materno : ",self.am)
    print("Edad       : ",self.edad)

obj1=Persona()
obj1.despliega()
print("-"*30)

obj2=Persona("Juan","Perez","Lopez",15)
obj2.despliega()
print("-"*30)

obj3=obj2
obj3.nom="Mario"
obj3.edad=18
obj3.despliega()
print("-"*30)

obj4=Persona(p_ap="Sanchez",p_edad=85)
obj4.despliega()