//Sección de librerias
#include "iostream"
//seccion de variables globales
int a;  //; es para guardar un espacio de memoria para la varibale 
float b;

int main(){
    a = 100;
    b = 3.1416;
    printf("A = %d\n", a);  //%d es para valores enteros
    printf("B = %.2f", b);  //%f para valores float agregar un .2 o cualquier numero limita la impreseion de decimales al numero indicado
    getchar();
}