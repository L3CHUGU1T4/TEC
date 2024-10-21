#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Estructura para almacenar un registro de la bitácora
struct Registro {
    string mes;
    int dia;
    string hora;
    string ip;
    int puerto;
    string razon;
};

// Función para leer la bitácora desde el archivo y almacenarla en un vector
vector<Registro> leerBitacora(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    vector<Registro> bitacora;
    string linea;
    
    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return bitacora;
    }
    
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Registro reg;
        string ipCompleta;

        ss >> reg.mes >> reg.dia >> reg.hora >> ipCompleta;
        getline(ss, reg.razon); // Obtener la razón
        
        // Separar IP y puerto
        size_t pos = ipCompleta.find(':');
        reg.ip = ipCompleta.substr(0, pos); // Solo la IP
        reg.puerto = stoi(ipCompleta.substr(pos + 1)); // El puerto convertido a número

        bitacora.push_back(reg);
    }
    
    archivo.close();
    return bitacora;
}

// Función para comparar IPs
bool compararPorIP(const Registro &a, const Registro &b) {
    return a.ip < b.ip; // Comparar solo por la IP, ignorar el puerto
}

// Función para escribir el resultado en un archivo
void escribirBitacoraOrdenada(const vector<Registro> &bitacora, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escribir." << endl;
        return;
    }
    
    for (const auto &reg : bitacora) {
        archivo << reg.mes << " " << reg.dia << " " << reg.hora << " " 
                << reg.ip << ":" << reg.puerto << " " << reg.razon << endl;
    }
    
    archivo.close();
}

// Función para mostrar los registros en el rango de IPs
void mostrarRegistrosEnRango(const vector<Registro> &bitacora, const string &ipInicio, const string &ipFin) {
    for (const auto &reg : bitacora) {
        if (reg.ip >= ipInicio && reg.ip <= ipFin) {
            cout << reg.mes << " " << reg.dia << " " << reg.hora << " " 
                 << reg.ip << ":" << reg.puerto << " " << reg.razon << endl;
        }
    }
}

int main() {
    string archivoEntrada = "bitacora.txt";
    string archivoSalida = "bitacora_ordenada.txt";
    
    // Leer la bitácora
    vector<Registro> bitacora = leerBitacora(archivoEntrada);
    
    // Ordenar la bitácora por IP
    sort(bitacora.begin(), bitacora.end(), compararPorIP);
    
    // Escribir la bitácora ordenada en un archivo
    escribirBitacoraOrdenada(bitacora, archivoSalida);
    
    // Solicitar al usuario el rango de búsqueda por IP
    string ipInicio, ipFin;
    cout << "Ingrese la IP de inicio: ";
    cin >> ipInicio;
    cout << "Ingrese la IP de fin: ";
    cin >> ipFin;
    
    // Mostrar los registros en el rango de IPs
    mostrarRegistrosEnRango(bitacora, ipInicio, ipFin);
    
    return 0;
}
