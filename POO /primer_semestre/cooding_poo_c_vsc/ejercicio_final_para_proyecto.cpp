#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

class Archivo {
public:
    char cve[6], nom[16];
    int pre;

    Archivo(const char* p_cve, const char* p_nom, int p_pre) {
        strcpy(cve, p_cve);
        strcpy(nom, p_nom);
        pre = p_pre;
    }

    Archivo() {
        // Constructor vacío
    }

    void despliega() {
        std::cout << "Clave = " << cve << "\n";
        std::cout << "Nombre = " << nom << "\n";
        std::cout << "Precio = " << pre << "\n";
        std::cin.get();
    }

    void graba() {
        std::ofstream arch("productos.csv", std::ios::app);
        if (!arch) {
            // Manejar error de apertura de archivo
            return;
        }
        arch << cve << "," << nom << "," << pre << "\n";
        arch.close();
    }

    void busca_rec(std::string &buf, const char* cve) {
        std::ifstream arch("productos.csv");
        if (!arch) {
            // Manejar error de apertura de archivo
            return;
        }
        bool existe = false;
        while (getline(arch, buf)) {
            if (strncmp(buf.c_str(), cve, 5) == 0) {
                existe = true;
                break;
            }
        }
        if (!existe) buf = "XXX";
    }

    void listado() {
        std::ifstream arch("productos.csv");
        if (!arch) {
            // Manejar error de apertura de archivo
            return;
        }
        std::string line;
        while (getline(arch, line)) {
            std::cout << line << "\n";
        }
        std::cin.get();
    }
};
void altas() {
    char cve[6], nom[16];
    int pre;
    // Pide y valida la matrícula
    while (true) {
        std::cout << "Indica la clave del producto: ";
        std::cin.getline(cve, 6);
        for (size_t i = 0; i < strlen(cve); ++i) {
            cve[i] = toupper(cve[i]);
        }

        if ((strlen(cve) != 5) || (cve[0] != 'P') || (cve[1] != '0')) {
            std::cout << "Error, la clave debe estar en el formato \"P0999\"\n";
            std::cin.get();
        } else {
            break;
        }
    }

    // Pide y valida el nombre
    while (true) {
        std::cout << "Indica el nombre del producto: ";
        std::cin.getline(nom, 16);
        if ((strlen(nom) < 1) || (strlen(nom) > 15)) {
            std::cout << "Error, el nombre debe tener entre 1 y 15 caracteres\n";
            std::cin.get();
        } else {
            break;
        }
    }

    // Pide y valida el precio
    while (true) {
        std::cout << "Indica el precio del producto: ";
        std::cin >> pre;
        if ((pre < 1) || (pre > 1000)) {
            std::cout << "Error, el precio debe estar entre 1 y 1,000 pesos\n";
            std::cin.get();  // Limpiar el buffer de entrada
        } else {
            break;
        }
    }

    for (size_t i = 0; i < strlen(nom); ++i) {
        if (nom[i] == ' ') {
            nom[i] = '_';
        }
    }
    Archivo obj(cve, nom, pre);
    obj.graba();
}
//calse de consultas
void consultas() {
    char cve[6];
    std::cout << "Indica la clave a consultar: ";
    std::cin.getline(cve, 6);
    std::string cad;
    Archivo obj;
    obj.busca_rec(cad, cve);
    if (cad == "XXX") {
        std::cout << "Error, clave de producto inexistente en archivo\n";
        std::cin.get();
    } else {
        std::cout << "Registro encontrado: " << cad << "\n";
        std::cin.get();
    }
}
//aqui voy 
void menu() {
    int op;
    do {
        std::cout << "1) Alta de productos\n";
        std::cout << "2) Consulta de productos\n";
        std::cout << "3) Lista de productos\n";
        std::cout << "4) Terminar\n";
        std::cout << "Indica la opción deseada: ";
        std::cin >> op;
        std::cin.ignore();  // Limpiar el buffer de entrada

        switch (op) {
        case 1:
            altas();
            break;
        case 2:
            consultas();
            break;
        case 3: {
            Archivo obj;
            obj.listado();
            break;
        }
        case 4:
            std::cout << "Programa terminado.\n";
            break;
        default:
            std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (op != 4);
}

int main() {
    menu();
    return 0;
}
