//Area de librerias
#include "iostream"

char cad1[21], cad2[21];
int x;

int main(){

printf("Indica la cadena uno  : "); gets(cad1);
	if (strlen(cad1)>20){
		printf("Error, m%cximo 20 caracteres\n",160);
		getchar();
	}
	else {
		printf("Indica la cadena dos  : "); gets(cad2);
		x = strlen(cad2);
		if(x>20){
			printf("Error, m%cximo 20 caracteres\n",160);
			getchar();
		}
		else{
			printf("Cadena 1 = %s\n", cad1);
			printf("Cadena 2 = %s\n", cad2);
			x = strcmp(cad1,cad2); //strcmp compara cadenas
			if(x==0){
				printf("Las cadenas son iguales");
			}
			else{
				printf("Las cadenas son diferentes");
			}
		}
	}
}
