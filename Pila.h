#include "Nodo.h"  // Se asume que Nodo está definido en otro archivo
#include <string>
#include <iostream>
using namespace std;

/**
 * @class Pila
 * @brief Representa una estructura de datos tipo pila (LIFO).
 */
class Pila {
private:
 Nodo* cima;  ///< Puntero al nodo en la cima de la pila.
 string name; ///< Nombre de la pila.

public:
 /**
  * @brief Constructor de la pila.
  * @param name Nombre de la pila.
  */
 Pila(string name);

 /**
  * @brief Obtiene el nombre de la pila.
  * @return Nombre de la pila.
  */
 string nombrePila();

 /**
  * @brief Agrega un nuevo elemento a la pila.
  * @param num Número que se va a apilar.
  */
 void apilar(int num);

 /**
  * @brief Extrae y devuelve el elemento en la cima de la pila.
  * @return El valor del nodo eliminado.
  */
 int desapilar();

 /**
  * @brief Verifica si la pila está vacía.
  * @return true si la pila está vacía, false en caso contrario.
  */
 bool estaVacia();
};
