#include <iostream>

using namespace std;

/**
 * Estructura Nodo para la lista simplemente ligada.
 * Un nodo contiene un valor (dato) y un puntero al siguiente nodo en la lista.
 */
struct Nodo {
    int dato;        // Valor almacenado en el nodo.
    Nodo* siguiente; // Puntero al siguiente nodo en la lista.
};

/**
 * Estructura Lista que representa una lista simplemente ligada.
 * La lista contiene un puntero a la cabeza de la lista, desde donde se accede a los demás nodos.
 */
struct Lista {
    Nodo* cabeza; // Puntero al primer nodo de la lista (cabeza).
    
    /**
     * Constructor por defecto que inicializa la lista vacía.
     * Inicializa el puntero `cabeza` como `nullptr`, indicando que la lista está vacía.
     */
    Lista() : cabeza(nullptr) {}
};

/**
 * Inserta un nuevo elemento al inicio de la lista.
 * Crea un nuevo nodo con el valor proporcionado y lo coloca al inicio de la lista.
 * 
 * Complejidad: O(1) ya que solo se crea un nodo y se actualizan punteros, 
 * sin necesidad de recorrer la lista.
 *
 * @param lista Referencia a la lista donde se insertará el nuevo nodo.
 * @param valor Valor que se asignará al nuevo nodo.
 */
void insertarInicio(Lista &lista, int valor) {
    Nodo* nuevo = new Nodo; // Crear un nuevo nodo en memoria dinámica.
    nuevo->dato = valor; // Asignar el valor al nodo.
    nuevo->siguiente = lista.cabeza; // El nuevo nodo apunta al nodo que era la cabeza actual.
    lista.cabeza = nuevo; // Actualizar la cabeza de la lista para que apunte al nuevo nodo.
}

/**
 * Busca un nodo que contenga un valor específico en la lista.
 * Recorre la lista desde la cabeza buscando un nodo que contenga el valor proporcionado.
 * Si lo encuentra, retorna un puntero al nodo; si no, retorna `nullptr`.
 * 
 * Complejidad: O(n) en el peor caso, donde n es el número de nodos en la lista.
 * Esto ocurre cuando el valor buscado está al final de la lista o no está presente.
 * 
 * @param lista Referencia a la lista en la que se buscará el valor.
 * @param valor Valor a buscar en los nodos de la lista.
 * @return Nodo* Puntero al nodo que contiene el valor, o `nullptr` si no se encuentra.
 */
Nodo* buscar(Lista &lista, int valor) {
    Nodo* actual = lista.cabeza; // Iniciar desde la cabeza de la lista
    while (actual != nullptr) { // Recorrer la lista
        if (actual->dato == valor) { // Si se encuentra el valor, retornar el nodo
            return actual;
        }
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }
    return nullptr; // Si no se encuentra el valor, retornar nullptr
}

/**
 * Modifica el valor de un nodo en la lista.
 * Busca un nodo que contenga el valor antiguo y lo reemplaza por un valor nuevo.
 * 
 * Complejidad: O(n), ya que primero debe buscar el nodo con el valor antiguo
 * y luego modificarlo, lo que puede requerir recorrer la lista completa en el peor caso.
 * 
 * @param lista Referencia a la lista donde se realizará la actualización.
 * @param valorAntiguo Valor del nodo que se desea actualizar.
 * @param valorNuevo Valor nuevo que reemplazará al valor antiguo.
 * @return true si la actualización fue exitosa, false si el nodo no se encontró.
 */
bool actualizar(Lista &lista, int valorAntiguo, int valorNuevo) {
    Nodo* nodo = buscar(lista, valorAntiguo); // Buscar el nodo con el valor antiguo
    if (nodo != nullptr) { // Si el nodo se encuentra, actualizar el valor
        nodo->dato = valorNuevo;
        return true;
    }
    return false; // Si no se encuentra, retornar falso
}

/**
 * Elimina un nodo de la lista que contenga un valor específico.
 * Ajusta los punteros para eliminar el nodo de la lista y libera su memoria.
 * 
 * Complejidad: O(n), donde n es el número de nodos de la lista. En el peor caso,
 * el valor a eliminar está en el último nodo o no está presente, lo que requiere
 * recorrer toda la lista.
 * 
 * @param lista Referencia a la lista donde se eliminará el nodo.
 * @param valor Valor del nodo que se desea eliminar.
 * @return true si la eliminación fue exitosa, false si el nodo no se encontró.
 */
bool eliminar(Lista &lista, int valor) {
    Nodo* actual = lista.cabeza; // Iniciar desde la cabeza
    Nodo* anterior = nullptr; // Puntero para rastrear el nodo anterior

    // Recorrer la lista buscando el valor
    while (actual != nullptr && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    // Si no se encontró el nodo
    if (actual == nullptr) {
        return false; // No se encontró el valor
    }

    // Si el nodo a eliminar es la cabeza
    if (anterior == nullptr) {
        lista.cabeza = actual->siguiente; // La cabeza ahora apunta al siguiente nodo
    } else {
        anterior->siguiente = actual->siguiente; // Saltar el nodo a eliminar
    }

    delete actual; // Liberar la memoria del nodo eliminado
    return true;
}

/**
 * Imprime todos los elementos de la lista.
 * Recorre la lista desde la cabeza y muestra los valores almacenados en los nodos.
 * 
 * Complejidad: O(n), donde n es el número de nodos en la lista, ya que es necesario
 * recorrer toda la lista para imprimir sus elementos.
 * 
 * @param lista Referencia a la lista que se desea imprimir.
 */
void imprimirLista(Lista &lista) {
    Nodo* actual = lista.cabeza; // Empezar desde la cabeza
    while (actual != nullptr) { // Recorrer hasta llegar al final de la lista
        cout << actual->dato << " -> "; // Imprimir el valor del nodo
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }
    cout << "nullptr" << endl; // Indicar el final de la lista
}

// Función principal para probar las operaciones CRUD
int main() {
    Lista lista;

    // Insertar elementos
    insertarInicio(lista, 5);
    insertarInicio(lista, 10);
    insertarInicio(lista, 15);

    // Imprimir lista
    cout << "Lista después de insertar: ";
    imprimirLista(lista);

    // Buscar un elemento
    Nodo* encontrado = buscar(lista, 10);
    if (encontrado) {
        cout << "Elemento 10 encontrado en la lista." << endl;
    } else {
        cout << "Elemento 10 no encontrado en la lista." << endl;
    }

    // Actualizar un elemento
    if (actualizar(lista, 10, 20)) {
        cout << "Elemento 10 actualizado a 20." << endl;
    } else {
        cout << "Elemento 10 no encontrado para actualizar." << endl;
    }

    // Imprimir lista después de actualizar
    cout << "Lista después de actualizar: ";
    imprimirLista(lista);

    // Eliminar un elemento
    if (eliminar(lista, 5)) {
        cout << "Elemento 5 eliminado de la lista." << endl;
    } else {
        cout << "Elemento 5 no encontrado para eliminar." << endl;
    }

    // Imprimir lista después de eliminar
    cout << "Lista después de eliminar: ";
    imprimirLista(lista);

    return 0;
}
