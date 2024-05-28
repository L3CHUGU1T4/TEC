#include "iostream"
#include "string.h"

class Persona{
    public:
        char nom[16], ap[16], am[16];
        int edad;
    public:
        Persona(){
            strcpy(nom,"Juan");
            strcpy(ap,"Perez");
            strcpy(am,"Lopez");
            edad=15;
        }

        void muestra(){
            printf("Nombre        : %s\n" ,nom);
            printf("ap paterno    : %s\n" ,ap);
            printf("ap materno    : %s\n" ,am);
            printf("Edad          : %d\n" ,edad);
            getchar();
        }
};

int main(){
    Persona obj1;
    obj1.muestra();
}