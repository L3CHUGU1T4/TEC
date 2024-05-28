#include "iostream"
#include "string.h"

class Persona{
    public:
        char nom[16], ap[16], am[16];
        int edad;
    public:
        Persona(char p_nom[16], char p_ap[16], char p_am[16], int p_edad){
            strcpy(nom,p_nom);
            strcpy(ap,p_ap);
            strcpy(am,p_am);
            edad = p_edad;
        }

        void muestra(){
            printf("Nombre              : %s\n" ,nom);
            printf("ap paterno          : %s\n" ,ap);
            printf("ap materno          : %s\n" ,am);
            printf("Edad                : %d\n" ,edad);
            getchar();
        }
};

int main(){
    char v_nom[16], v_ap[16], v_am[16];
    int v_edad;

    Persona obj1("Armando", "Arias", "Armas", 25);
    obj1.muestra();

    printf("-----------------------------------------------------------\n");
    printf("Indica el Nombre       : "); gets(v_nom);
    printf("Indica el ap. paterno  : "); gets(v_ap);
    printf("Indica el ap. materno  : "); gets(v_am);
    printf("Indica La edad         : "); scanf("%d", &v_edad);
    printf("-----------------------------------------------------------\n");
    
    Persona obj2(v_nom, v_ap, v_am, v_edad);
    obj2.muestra();
}