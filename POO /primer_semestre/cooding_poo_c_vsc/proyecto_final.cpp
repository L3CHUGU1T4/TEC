//leobardo de jesus carbajal, a01772464 
//sección de librerias
#include <iostream> //Permite usar operaciones de entrada y salida como std::cout y std::cin.
#include <fstream>  //Proporciona funcionalidades para leer y escribir en archivos.
#include <cstring>  //Ofrece funciones para manipular cadenas de caracteres en C.
#include <cctype>   //Utilizada para operaciones de caracteres, como convertir caracteres a mayúsculas.
#include <iomanip>  //Para usar std::setw y std::left
#include <sstream>  // Para std::istringstream

void limpiarPantalla() {
    for (int i = 0; i < 50; ++i) {
        std::cout << "\n";
    }
}

//inicia clase Archivo
class Archivo {
public:     //Especifica que los miembros de la clase que siguen son accesibles desde cualquier parte del programa
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
        //constructor vacio. mandamos a llamar objetos sin parametros
    }

    void despliega(){
        std::cout << "Matricula = " << matricula << "\n";   // std::cout  se utilizan para imprimir mensajes en la consola / <<  se utiliza para enviar datos a la salida estándar.
        std::cout << "Nombre = " << nombre << "\n";  //  :: se utiliza para acceder a miembros de una clase o un espacio de nombres
        std::cout << "Ap. paterno = " << appaterno << "\n";
        std::cout << "Ap. materno = " << apmaterno << "\n";
        std::cin.get();
    }

    void graba() {
        limpiarPantalla();
        std::ofstream arch("alumnos.csv", std::ios::app);  //std::ofstream para escribir en archivos, /std::ifstream para leer archivos3|
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
        limpiarPantalla();
        std::ifstream arch("alumnos.csv");
        if (!arch) {
            std::cout << "Error al abrir el archivo.\n";
            std::cin.get();
            return;
        }
        // Imprime los encabezados de columna.
        std::cout << std::left
                  << std::setw(10) << "Matricula" 
                  << std::setw(15) << "Nombre" 
                  << std::setw(20) << "Ap. Paterno" 
                  << std::setw(20) << "Ap. Materno" 
                  << std::setw(5) << "Calif" << "\n";
        std::cout << std::setfill('-') << std::setw(70) << "-" << std::setfill(' ') << "\n";  // // Imprime la línea de separación con guiones./std::setw(70) establece el "ancho de campo

        std::string line;
        while (std::getline(arch, line)) {
            std::istringstream iss(line);
            std::string matricula, nombre, apellidoPaterno, apellidoMaterno, calif;  // Asumiendo que hay una columna calif

            std::getline(iss, matricula, ',');
            std::getline(iss, nombre, ',');
            std::getline(iss, apellidoPaterno, ',');
            std::getline(iss, apellidoMaterno, ',');
            std::getline(iss, calif, ',');

            std::cout << std::setw(10) << matricula 
                      << std::setw(15) << nombre 
                      << std::setw(20) << apellidoPaterno 
                      << std::setw(20) << apellidoMaterno 
                      << std::setw(5) << calif << "\n";
        }
        arch.close();
        std::cin.get();  // Pausa antes de continuar
    }
};


void altas() {
    limpiarPantalla();
    char matricula[10], nombre[16], appaterno[16], apmaterno[16];
    int calif;

    // Pide y valida la matricula
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
            // Verifica si la matrícula ya existe
            std::string cad;
            Archivo obj;
            obj.busca_registro(cad, matricula);
            if (cad != "XXX") {
                std::cout << "Error, la matrícula ya está registrada en el archivo.\n";
                std::cin.get();
                continue; // Vuelve al inicio del bucle si la matrícula ya existe
            }
            break; // Sale del bucle si la matrícula es válida y no está duplicada
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

    Archivo nuevoEstudiante(matricula, nombre, appaterno, apmaterno, calif);
    nuevoEstudiante.graba();
    limpiarPantalla();
}


//sección para realizar la consulta de los alumnos registrados 

void consultas() {
    char matricula[10];
    std::cout << "Indica la matricula a consultar: ";
    std::cin.getline(matricula, 10); 
    std::string cad;  //declara una variable llamada cad del tipo std::string
    Archivo obj;
    obj.busca_registro(cad, matricula);
    if (cad == "XXX") {
        std::cout << "XXX\n";
        std::cin.get();
    } else{
        std::cout << "Registro encontrado: " << cad << "\n";
        std::cin.get();
    }
    limpiarPantalla();
}

//Sección del menu

void menu() {
    limpiarPantalla();
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