#include <stdlib.h>  // Biblioteca estándar (aunque no es necesaria aquí)

/**
 * @class Nodo
 * @brief Representa un nodo de una estructura de datos enlazada.
 */
class Nodo {
public:
    int valor;      ///< Valor almacenado en el nodo.
    Nodo* siguiente; ///< Puntero al siguiente nodo en la lista/pila.

    /**
     * @brief Constructor del nodo.
     * @param v Valor que almacenará el nodo.
     * @param sig Puntero al siguiente nodo (por defecto es NULL).
     */
    Nodo(int v, Nodo* sig = NULL) {
        valor = v;
        siguiente = sig;
    }
};
