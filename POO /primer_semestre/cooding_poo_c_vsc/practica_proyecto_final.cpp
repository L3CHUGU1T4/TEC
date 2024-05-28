#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

class Archivo {
public:
    char matricula[10], nombre[16], appaterno[16], apmaterno[16];
    int calif;

    Archivo(const char* p_mat, const char* p_nom, const char* p_ap, const char* p_am, int p_cal) {
        strcpy(matricula, p_mat);
        strcpy(nombre, p_nom);
        strcpy(appaterno, p_ap);
        strcpy(apmaterno, p_am);
        calif = p_cal;
    }

    Archivo(){
        //constructor vacio
    }

    void despliega(){
        std::cout << "Matricula = " << matricula << "\n";
        std::cout << "Nombre = " << nombre << "\n";
        std::cout << "Ap. paterno = " << appaterno << "\n";
        std::cout << "Ap. materno = " << apmaterno << "\n";
        std::cin.get();
    }

    void graba() {
        std::ofstream arch("alumnos.csv", std::ios::app);
        if (!arch) {
            //Manejar error de apertura de archivo
            return;
        }
        arch << matricula << "," << nombre <<  "," << appaterno << "," << apmaterno << "," << calif << "\n";
        arch.close();
    }

    void busca_registro(std::string &buf, const char* matricula) {
        std::ifstream arch("alumnos.csv");
        if (!arch) {
            //manejar error de apertura de archivo
            return;
        }
        bool existe = false;
        while (getline(arch, buf)) {
            if (strncmp(buf.c_str(), matricula, 9) == 0) {
                existe = true;
                break;
            }
        }
        if (!existe) buf = "XXX";
    }

    void listar() {
        std::ifstream arch("alumnos.csv");
        if (!arch) {
            std::cout << "Error al abrir el archivo para listar.\n";
            return;
        }
        std::string line;
        std::cout << "Matricula Nombre        Ap. Paterno     Ap. Materno     Calif\n";
        std::cout << "===============================================================\n";
        while (getline(arch, line)) {
            std::istringstream iss(line);
            std::string matricula, nombre, appaterno, apmaterno;
            int calif;
            getline(iss, matricula, ',');
            getline(iss, nombre, ',');
            getline(iss, appaterno, ',');
            getline(iss, apmaterno, ',');
            iss >> calif;

            std::cout << std::left << std::setw(10) << matricula
                      << std::setw(15) << nombre
                      << std::setw(15) << appaterno
                      << std::setw(15) << apmaterno
                      << std::setw(5) << calif << std::endl;
        }
        std::cin.get();
    }    
};

void altas() {
    char matricula[10], nombre[16], appaterno[16], apmaterno[16];
    int calif;
    //pide y valida la matricula
    while (true) {
        std::cout << "Indica la matrícula del alumno: ";
        std::cin.getline(matricula, 10);
        for (size_t i = 0; i < strlen(matricula); ++i) {
            matricula[i] = toupper(matricula[i]);
        }

        if ((strlen(matricula) != 9) || (matricula[0] != 'A') || (matricula[1] != '0')) {
            std::cout << "Error la matrícula debe estar en el formato \"A09999999\"\n";
            std::cin.get();
        } else {
            break;
        }
    }

    //Pide y valida el nombre
    while (true) {
        std::cout << "Ingrersa el nombre del alumno: ";
        std::cin.getline(nombre, 16);
        if ((strlen(nombre) < 1) || (strlen(nombre) > 15)) {
            std::cout << "Error, el nombre debe tener entre 1 y 15 caracteres\n";
            std::cin.get();
        } else {
            break;
        }
    }

    //pide y valida el apellido paterno
    while (true) {
        std::cout << "Ingrersa el apellido paterno del alumno: ";
        std::cin.getline(appaterno, 16);
        if ((strlen(appaterno) < 1) || (strlen(appaterno) > 15)) {
            std::cout << "Error, el apellido paterno debe tener entre 1 y 15 caracteres\n";
            std::cin.get();
        } else {
            break;
        }
    }

    //pide y valida el apellido materno
    while (true) {
        std::cout << "Ingrersa el apellido materno del alumno: ";
        std::cin.getline(apmaterno, 16);
        if ((strlen(apmaterno) < 1) || (strlen(apmaterno) > 15)) {
            std::cout << "Error, el apellido materno debe tener entre 1 y 15 caracteres\n";
            std::cin.get();
        } else {
            break;
        }
    }

    //pide y valida la calificación del alumno
    while (true) {
        std::cout << "Ingresa la calificación del alumno: ";
        std::cin >> calif;
        if ((calif < 1) || (calif > 1000)) {
            std::cout << "Error, la calificación debe estar entre 1 y 10\n";
            std::cin.get();  // Limpiar el buffer de entrada
        } else {
            break;
        }
    }

     for (size_t i = 0; i < strlen(nombre); ++i) {
        if (nombre[i] == ' ') {
            nombre[i] = '_';
        }
    }
    Archivo obj(matricula, nombre, appaterno, apmaterno, calif);
    obj.graba();
}

//sección para realizar la consulta de los alumnos registrados 

void consultas() {
    char matricula[10];
    std::cout << "Indica la matricula a consultar: ";
    std::cin.getline(matricula, 10); 
    std::string cad;
    Archivo obj;
    obj.busca_registro(cad, matricula);
    if (cad == "XXX") {
        std::cout << "Error, matrícula inexistente en archivo\n";
        std::cin.get();
    } else{
        std::cout << "Rregistro encontrado: " << cad << "\n";
        std::cin.get();
    }
}

//Sección del menu

void menu() {
    int op;
    do {
        std::cout << "1) Alta de alumnos\n";
        std::cout << "2) Consulta de alumnos\n";
        std::cout << "3) Listado de alumnos\n";
        std::cout << "4) Terminar\n";
        std::cout << "Indique la opción deseada: ";
        std::cin >> op;
        std::cin.ignore(); 

        switch (op) {
        case 1:
            altas();
            break;
        case 2:
            consultas();
            break;
        case 3: {
            Archivo obj;
            std::cout << "Matrícula   Nombre    Apellido Paterno   Apellido materno   Calificación\n";
            std::cout << "========================================================================\n";
            obj.listar();
            break;
        }
        case 4:
            std::cout << "Programa terminado.\n";
            break;
        default:
            std::cout << "Opción inválida, Intente nuevamente.\n";
        }
    } while (op !=4);
}

int main() {
    menu();
    return 0;
}