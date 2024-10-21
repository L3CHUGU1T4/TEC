#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstring>  // Para usar memset
using namespace std;

// Estructura para almacenar los registros
struct Registro {
    tm fechaHora;
    string ip;
    string razon;
};

// Función para leer el archivo bitacora.txt
vector<Registro> leerBitacora(const string &filename) {
    vector<Registro> registros;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string mes, dia, hora, ip, razon;
        ss >> mes >> dia >> hora >> ip;
        getline(ss, razon);

        // Crear estructura tm para almacenar la fecha y hora
        Registro reg;
        memset(&reg.fechaHora, 0, sizeof(reg.fechaHora));  // Inicializa a ceros
        istringstream horaStream(hora);
        strptime((mes + " " + dia + " " + hora).c_str(), "%b %d %H:%M:%S", &reg.fechaHora);
        reg.ip = ip;
        reg.razon = razon;
        registros.push_back(reg);
    }
    return registros;
}

// Función para ordenar los registros por fecha y hora
bool compararFechas(const Registro &a, const Registro &b) {
    return mktime(const_cast<tm *>(&a.fechaHora)) < mktime(const_cast<tm *>(&b.fechaHora));
}

// Función para solicitar fechas de inicio y fin al usuario
tm solicitarFecha(const string &mensaje) {
    string fechaStr;
    cout << mensaje;
    getline(cin, fechaStr);

    tm fecha = {};
    strptime(fechaStr.c_str(), "%b %d %H:%M:%S", &fecha);
    return fecha;
}

// Función para filtrar registros entre dos fechas
vector<Registro> filtrarPorFechas(const vector<Registro> &registros, const tm &fechaInicio, const tm &fechaFin) {
    vector<Registro> resultados;
    time_t inicio = mktime(const_cast<tm *>(&fechaInicio));
    time_t fin = mktime(const_cast<tm *>(&fechaFin));

    for (const auto &reg : registros) {
        time_t regTime = mktime(const_cast<tm *>(&reg.fechaHora));
        if (regTime >= inicio && regTime <= fin) {
            resultados.push_back(reg);
        }
    }
    return resultados;
}

// Función para guardar los resultados en un archivo
void guardarResultados(const string &filename, const vector<Registro> &registros) {
    ofstream file(filename);
    for (const auto &reg : registros) {
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%b %d %H:%M:%S", &reg.fechaHora);
        file << buffer << " " << reg.ip << " " << reg.razon << endl;
    }
}

int main() {
    // Leer el archivo bitacora.txt
    vector<Registro> registros = leerBitacora("bitacora.txt");

    // Ordenar los registros por fecha y hora
    sort(registros.begin(), registros.end(), compararFechas);

    //  Solicitar fechas de inicio y fin
    tm fechaInicio = solicitarFecha("Ingresa la fecha de inicio (MMM DD HH:MM:SS): ");
    tm fechaFin = solicitarFecha("Ingresa la fecha de fin (MMM DD HH:MM:SS): ");

    //  Filtrar registros por fechas
    vector<Registro> registrosFiltrados = filtrarPorFechas(registros, fechaInicio, fechaFin);

    //  Guardar los resultados en un archivo
    guardarResultados("resultado_ordenamiento.txt", registrosFiltrados);

    cout << "Resultados guardados en resultado_ordenamiento.txt" << endl;

    return 0;
}
