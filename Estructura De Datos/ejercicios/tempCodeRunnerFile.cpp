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

int main() {
    int n;

    cout << "Ingrese un entero positivo (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: n debe ser un entero positivo." << endl;
        return 1;
    }

    int resultadoIterativo = sumaIterativa(n);
    int resultadoRecursivo = sumaRecursiva(n);
    int resultadoDirecto = sumaDirecta(n);

    cout << "Sumatoria iterativa de 1 hasta " << n << ": " << resultadoIterativo << endl;
    cout << "Sumatoria recursiva de 1 hasta " << n << ": " << resultadoRecursivo << endl;
    cout << "Sumatoria directa de 1 hasta " << n << ": " << resultadoDirecto << endl;

    return 0;
}