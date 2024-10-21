#include <iostream>
#include <vector>

using namespace std;

// Función que ordena usando el método de intercambio (O(n^2))
void ordenaIntercambio(vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[i] > vec[j]) {
                swap(vec[i], vec[j]);
            }
        }
    }
}

// Función que ordena usando el método de burbuja (O(n^2))
void ordenaBurbuja(vector<int>& vec) {
    bool swapped;
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // Si no hubo intercambio, el array ya está ordenado
    }
}

// Función de combinación para el ordenamiento Merge Sort
void merge(vector<int>& vec, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = vec[left + i];
    for (int j = 0; j < n2; j++) R[j] = vec[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) vec[k++] = L[i++];
    while (j < n2) vec[k++] = R[j++];
}

// Función que ordena usando el método Merge Sort (O(n log n))
void ordenaMerge(vector<int>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        ordenaMerge(vec, left, mid);
        ordenaMerge(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

// Función de búsqueda secuencial (O(n))
int busqSecuencial(const vector<int>& vec, int dato) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == dato) {
            return i;
        }
    }
    return -1;  // No encontrado
}

// Función de búsqueda binaria (O(log n))
int busqBinaria(const vector<int>& vec, int dato, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == dato) {
            return mid;
        } else if (vec[mid] < dato) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // No encontrado
}

int main() {
    int n, numBusquedas, dato;
    
    // Solicitando el número de elementos
    cout << "Ingrese el número de elementos en el vector: ";
    cin >> n;

    vector<int> vec(n);
    
    // Llenando el vector con n números
    cout << "Ingrese los " << n << " números:\n";
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    // Ordenando el vector con los tres métodos
    vector<int> vecIntercambio = vec, vecBurbuja = vec, vecMerge = vec;

    ordenaIntercambio(vecIntercambio);
    ordenaBurbuja(vecBurbuja);
    ordenaMerge(vecMerge, 0, vecMerge.size() - 1);

    // Solicitando la cantidad de búsquedas
    cout << "Ingrese la cantidad de búsquedas que desea realizar: ";
    cin >> numBusquedas;

    for (int i = 0; i < numBusquedas; ++i) {
        cout << "Ingrese el número que desea buscar: ";
        cin >> dato;

        // Búsqueda secuencial
        int resultadoSecuencial = busqSecuencial(vec, dato);
        if (resultadoSecuencial != -1) {
            cout << "Búsqueda secuencial: el número " << dato << " se encuentra en el índice " << resultadoSecuencial << ".\n";
        } else {
            cout << "Búsqueda secuencial: el número " << dato << " no se encontró.\n";
        }

        // Búsqueda binaria
        int resultadoBinario = busqBinaria(vecMerge, dato, 0, vecMerge.size() - 1);
        if (resultadoBinario != -1) {
            cout << "Búsqueda binaria: el número " << dato << " se encuentra en el índice " << resultadoBinario << ".\n";
        } else {
            cout << "Búsqueda binaria: el número " << dato << " no se encontró.\n";
        }
    }

    return 0;
}
