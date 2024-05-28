#include "iostream"
#include "String.h"
#include "fstream" //Libreria para manipular archivos
using namespace std; //Jala las propiedades de "fstream"

	
char cve[6], nom[21];
int pre;

int main(){
	while (true){
		printf("Indica la clave del producto:"); gets(cve);
		if(strlen(cve)>5){
			printf("Error, clave de no mas de 5 caracteres\n");
			getchar();
		}
		else break;
	}
	while (true){
		printf("Indica el nombre:"); gets(nom);
		if(strlen(nom)>20){
			printf("Error, nombre de no mas de 20 caracteres\n");
			getchar();	
		}
		else break;
	}
	while(true){
		printf("Indica el precio: "); scanf("%d", &pre);
		if((pre < 1) || (pre > 10000)){
			printf("Error, el precio debe de estar entre 1 y 1\n");
			getchar();
		}
		else break;
	}
	
	ofstream arch;
	arch.open("Productos.csv", ios::app);
	arch <<cve<<","<<nom<<","<<pre<<"\n";
	arch.close();
}