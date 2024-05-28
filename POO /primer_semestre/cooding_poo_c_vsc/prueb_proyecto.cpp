#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <iomanip> // Para std::setw y std::left
#include <sstream> // Para std::istringstream

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

    Archivo() {
        // Constructor vacío
    }

    void despliega() {
        std::cout << "Matricula = " << matricula << "\n";
        std::cout << "Nombre = " << nombre << "\n";
        std::cout << "Ap. paterno = " << appaterno << "\n";
        std::cout << "Ap. materno = " << apmaterno << "\n";
        std::cin.get();
    }

    void graba() {
        std::ofstream arch("alumnos.csv", std::ios::app);
        if (!arch) {
            std::cout << "Error al abrir el archivo para grabar.\n";
            return;
        }
        arch << matricula << "," << nombre <<  "," << appaterno << "," << apmaterno << "," << calif << "\n";
        arch.close();
    }

    void busca_registro(std::string &buf, const char* matricula) {
        std::ifstream arch("alumnos.csv");
        if (!arch) {
            std::cout << "Error al abrir el archivo para buscar.\n";
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
    // ... (código existente de tu función altas)
}

void consultas() {
    // ... (código existente de tu función consultas)
}

void menu() {
    // ... (código existente de tu función menu)
}

int main() {
    menu();
    return 0;
}
