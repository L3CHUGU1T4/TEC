#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <iomanip>
#include <sstream>

void limpiar() {
    for(int i =0; i < 50; ++i) {
        std::cout << "\n";
    }
}

class Archivo {
public: 
    char matricula[10], nombre[16], appaterno[16], apmaterno[16];
    int calif;

    Archivo(const char* p_mat, const char* p_nom, const char* p_ap, const char* p_ma, int p_cal) {
        strcpy(matricula, p_mat);
        strcpy(nombre, p_nom);
        strcpy(appaterno, p_ap);
        strcpy(apmaterno, p_ma);
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
        limpiar();
        std::ofstream arch("prueba_alumnos.csv", std::ios::app);
        if (!arch) {
            return;
        }
        arch << matricula << "," << nombre << "," << appaterno << "," << apmaterno << "," << calif << "\n";
        arch.close();
    }

    void busca_registro(std::string &buf, const char* matricula) {
        std::ifstream arch("prueba_alumnos.csv");
        if(!arch); {
            return;
        }
        bool existe = false;
        while (getline(arch, buf)) {
            if (strncmp(buf.c_str(), matricula, 9) == 0) {
                existe = true;
                break;
            }
        }
        if (!existe) buf = "xxx";
    }

    
};