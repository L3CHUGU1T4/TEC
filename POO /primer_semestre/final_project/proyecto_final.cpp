#include <stdio.h>
#include <conio.h>
#include <String.h>
#include <fstream>
using namespace std;

class Archivo {
public:
    char mat[10], nom[16], ap[16], am[16];
    int calf;

public:
    Archivo(char p_mat[10], char p_nom[16], char p_ap[16], char p_am[16], int p_calf) {
        strcpy(mat, p_mat);
        strcpy(nom, p_nom);
        strcpy(ap, p_ap);
        strcpy(am, p_am);
        calf = p_calf;
    }

    Archivo() {
        // Vacio
    }

    void despliega() {
        printf("clave = %s\n", mat);
        printf("Nombre = %s\n", nom);
        printf("Apellido Paterno = %s\n", ap); 
        printf("Apellido Materno = %s\n", am); 
        printf("Calificacion = %d\n", calf);
        getche();
    }

    void Graba() {
        ofstream arch;
        arch.open("alumnos.csv", ios::app);
        arch <<mat<<","<<nom<<","<<ap<<","<<am<<","<<calf<<"\n"; 
        arch.close();
    }

    void busca_rec(char* buf, char mat[10]) {
        bool existe;
        ifstream arch;
        arch.open("alumnos.csv", ios::in);
        existe = false;
        while (!arch.eof()) {
            arch >> buf;
            if (strnicmp(buf, mat, 9) == 0) {
                existe = true;
                break;
            }
        }
        if (!existe) strcpy(buf, "XXX");
    }

    void listado() {
        char cad[100], *token, mat[10], nom[16], ap[16], am[16], calf[3];
        for (int i = 0; i <= 110; i++) printf("\n");
        printf("Matricula  Nombre            Ap. Paterno       Ap. Materno       Calificacion \n");
            //  123456789  123456789012345   123456789012345   123456789012345 
        printf("------------------------------------------------------------------------------\n");
			
        ifstream arch;
        arch.open("alumnos.csv", ios::in);
        while (!arch.eof()) {
            arch >> cad;
            if (!arch.eof()) {
                token = strtok(cad, ","); strcpy(mat, token);
                token = strtok(NULL, ","); strcpy(nom, token);
                token = strtok(NULL, ","); strcpy(ap, token);
                token = strtok(NULL, ","); strcpy(am, token);
                token = strtok(NULL, ","); strcpy(calf, token);
                printf("%s  ", mat);
                for (int i = 0; i < strlen(nom); i++) if (nom[i] == '_') nom[i] = ' ';
                printf("%s  ", nom); for (int i = strlen(nom); i <= 15; i++) printf(" ");
                for (int i = 0; i < strlen(ap); i++) if (ap[i] == '_') ap[i] = ' ';
                printf("%s  ", ap); for (int i = strlen(ap); i <= 15; i++) printf(" ");
                for (int i = 0; i < strlen(am); i++) if (am[i] == '_') am[i] = ' ';
                printf("%s  ", am); for (int i = strlen(am); i <= 15; i++) printf(" ");
                
                printf("%s\n", calf); 
            }
        }
        arch.close();
        getche();
    }
};

void altas() {
    char mat[10], nom[16], ap[16], am[16];
    int calf;
    for (int i = 0; i <= 40; i++) printf("\n");
    while (true) {
        printf("Ingresa la matricula del alumno: "); gets(mat);
        strupr(mat);
        if ((strlen(mat) != 9) || (mat[0] != 'A') || (mat[1] != '0')) {
            printf("Error, la matricula debe de estar en el formato \"A01999999\"\n");
            getche();
        }
        else{
        	char buffer[100];
        	Archivo obj;
        	obj.busca_rec(buffer, mat);
        	
        	if (strcmp(buffer, "XXX") !=0){
        		printf("ERROR, matricula existente. Ingresa una matricula nueva o diferente\n");
        		getche();
			}
		else break;
		}
        
    }

    while (true) {
        printf("Indica el nombre del Alumno: "); gets(nom);
        if ((strlen(nom) < 1) || (strlen(nom) > 15) ||(!isupper(nom[0]))) {
            printf("Error, Nombre debe de tener entre 1 y 15 caracteres. El nombre debe iniciar con mayuscula\n");
            getche();
        }
        else break;
    }

    while (true) {
        printf("Ingresa el Apellido Paterno del Alumno: "); gets(ap);
        if ((strlen(ap) < 1) || (strlen(ap) > 15)||(!isupper(ap[0]))) {
            printf("Error, Apellido Paterno debe de tener entre 1 y 15 caracteres. El Ap. Paterno debe iniciar con mayuscula\n");
            getche();
        }
        else break;
    }

    while (true) {
        printf("Ingresa el Apellido Materno del Alumno: "); gets(am);
        if ((strlen(am) < 1) || (strlen(am) > 15)||(!isupper(am[0]))) {
            printf("Error, Apellido Materno debe de tener entre 1 y 15 caracteres.El Ap. Materno debe iniciar con mayuscula\n");
            getche();
        }
        else break;
    }

    while (true) {
        printf("Ingresa la calificacion del Alumno: "); scanf("%d", &calf);
        if ((calf < 1) || (calf > 100)) {
            printf("La calificacion debe de estar en formato de 1 a 100\n");
            getche();
        }
        else break;
    }

    for (int i = 0; i < strlen(nom); i++) if (nom[i] == ' ') nom[i] = '_';
    for (int i = 0; i < strlen(ap); i++) if (ap[i] == ' ') ap[i] = '_';
    for (int i = 0; i < strlen(am); i++) if (am[i] == ' ') am[i] = '_';
    Archivo obj(mat, nom, ap, am, calf);
	//obj.despliega();
    obj.Graba();
}

void consultas() {
    char cad[100], mat[10];
    char *token, nom[16], ap[10], am[16], calf[3];
    for (int i = 0; i <= 40; i++) printf("\n");
    printf("Indica la matricula a consultar: "); gets(mat);
    Archivo obj;
    obj.busca_rec(cad, mat);
    if (strcmp(cad, "XXX") == 0) {
        printf("Error, matricula de alumno inexistente en el archivo\n");
        getche();
    }
    else {
        token = strtok(cad, ",");
        token = strtok(NULL, ","); strcpy(nom, token);
        token = strtok(NULL, ","); strcpy(ap, token);
        token = strtok(NULL, ","); strcpy(am, token);
        token = strtok(NULL, ","); strcpy(calf, token);
        printf("Matricula    : %s\n", mat);
        for(int i=0; i<strlen(nom);i++) if(nom[i]=='_') nom[i]=' ';
        printf("Nombre       : %s\n", nom);
        for(int i=0; i<strlen(ap);i++) if(ap[i]=='_') ap[i]=' ';
        printf("Ap. Paterno  : %s\n", ap);
        for(int i=0; i<strlen(am);i++) if(am[i]=='_') am[i]=' ';
        printf("Ap. Materno  : %s\n", am);
        printf("Calificacion : %s\n", calf);
        getche();
    }
}

void menu() {
    int op;
    char falso[2];
    while (op != 4) {
        for (int i = 0; i < 40; i++) printf("\n");
        printf("1) Alta de Alumnos\n");
        printf("2) Consulta de Alumnos\n");
        printf("3) Lista de Alumnos\n");
        printf("4) Terminar\n");
        printf("Indica la opcion seleccionada: "); scanf("%d", &op);gets(falso);
        if (op == 1) altas();
        if (op == 2) consultas();
        if (op == 3) {
            Archivo obj;
            obj.listado();
        }
    }
}

int main() { 
    menu();
    return 0; 
}
