class Utilerias:
    def error(self, msg):
        print(msg)
        input("Oprima [ENTER] para continuar")
        
    def pide_entero(self, msg, LI, LS):
        while True:
            v = input(msg)
            if not v.isnumeric():
                self.error("Error, valor fuera de rango")
            else:
                v = int(v)
                if v < LI or v > LS:
                    self.error("Error, valor fuera de rango")
                else:
                    return v
                
    def pide_cadena(self, msg, LI, LS):
        while True:
            cad = input(msg)
            if len(cad) < LI or len(cad) > LS:
                let = "Error, la cadena debe de tener entre " + str(LI) + " y " + str(LS) + " caracteres."
                self.error(let)
            else:
                return cad
