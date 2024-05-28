#Este ejemplo esta basado en el ejemplo de la clase persona definido en la presentación

class Persona(): #Creamos la clase Persona
    nombre = "Leobardo"
    apellidos = "de Jesús Carbajal"
    edad = 19

    def muestra(self): #Se define un método qu emostrará las propiedades de la clase. (El parámetro self se debe incluir para indicar que se trata de un método del propio objeto que los invocará)

        print("Nombre    :",self.nombre)
        print("Apellidos :",self.apellidos)
        print("Edad      :",self.edad)

#Fin de la clase Persona

pancho = Persona() #Creamos un objeto llamdao "pancho" que pertenece a la clase Persona
pancho.muestra()   # A través del objeto "pancho" se llama al método "muestra"
