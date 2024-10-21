#include <iostream>
using namespace std;

int sumaIterativa(int n) {
    int suma = 0;
    for (int i = 1; i <= n; ++i) {
        suma += i;
    }
    return suma;
}

int sumaRecursiva(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + sumaRecursiva(n - 1);
    }
}

int sumaDirecta(int n) {
    return n * (n + 1) / 2;
}

void ejecutarPruebas() {
    int casos[] = {1, 5, 10, 100};  // Casos de prueba
    int resultadosEsperados[] = {1, 15, 55, 5050};  // Resultados esperados

    for (int i = 0; i < 4; ++i) {
        int n = casos[i];
        int esperado = resultadosEsperados[i];

        // Evaluación para sumaIterativa
        int resultadoIterativo = sumaIterativa(n);
        cout << "sumaIterativa(" << n << ") = " << resultadoIterativo << ". Esperado: " << esperado << endl;
        if (resultadoIterativo == esperado) {
            cout << "sumaIterativa PASA el caso de prueba." << endl;
        } else {
            cout << "sumaIterativa NO PASA el caso de prueba." << endl;
        }

        // Evaluación para sumaRecursiva
        int resultadoRecursivo = sumaRecursiva(n);
        cout << "sumaRecursiva(" << n << ") = " << resultadoRecursivo << ". Esperado: " << esperado << endl;
        if (resultadoRecursivo == esperado) {
            cout << "sumaRecursiva PASA el caso de prueba." << endl;
        } else {
            cout << "sumaRecursiva NO PASA el caso de prueba." << endl;
        }

        // Evaluación para sumaDirecta
        int resultadoDirecto = sumaDirecta(n);
        cout << "sumaDirecta(" << n << ") = " << resultadoDirecto << ". Esperado: " << esperado << endl;
        if (resultadoDirecto == esperado) {
            cout << "sumaDirecta PASA el caso de prueba." << endl;
        } else {
            cout << "sumaDirecta NO PASA el caso de prueba." << endl;
        }

        cout << "----------------------------------------" << endl;
    }
}

int main() {
    ejecutarPruebas();
    return 0;
}
