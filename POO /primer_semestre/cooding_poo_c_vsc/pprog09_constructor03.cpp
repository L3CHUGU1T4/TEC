#include "iostream"
#include "string.h"

class Persona {
	public:
		char nom[16], ap[16], am[16];
		int edad;
	public:

		Persona(){
			strcpy(nom,"NA");
			strcpy(ap,"NA");
			strcpy(am,"NA");
			edad=0;
		}
		
		Persona(char p_nom[16], char p_ap[16], char p_am[16], int p_edad ){
			strcpy(nom,p_nom);
			strcpy(ap,p_ap);
			strcpy(am,p_am);
			edad=p_edad;
		}
		
		void muestra(){
			printf("Nombre		: %s\n", nom);
			printf("Ap Paterno	: %s\n", ap);
			printf("Ap Materno	: %s\n", am);
			printf("Edad		: %d\n", edad);
			getchar();
		}
};

int main(){
	char v_nom[16], v_ap[16], v_am[16];
	int v_edad;
	
	Persona obj1;
	obj1.muestra();
	
	printf("---------------------------------------------------------\n");
	Persona obj2("Daniel", "Diaz", "Ortega", 27);
	obj2.muestra();
	
	printf("---------------------------------------------------------\n");
	printf("Indica el nombre	: "); gets(v_nom);
	printf("Indica el Ap Paterno: "); gets(v_ap);
	printf("Indica el Ap Materno: "); gets(v_am);
	printf("Indica la Edad		: "); scanf("%d",&v_edad);
	Persona obj3(v_nom, v_ap, v_am, v_edad);
	obj3.muestra();
}