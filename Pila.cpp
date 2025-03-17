#include "Pila.h"  // Se asume que la clase Nodo está definida en "Nodo.h"

/**
 * @brief Constructor de la clase Pila.
 * @param name Nombre de la pila.
 */
Pila::Pila(string name) {
  this->name = name;
  this->cima = nullptr; // Inicializa la pila como vacía
}

/**
 * @brief Retorna el nombre de la pila.
 * @return Nombre de la pila.
 */
std::string Pila::nombrePila() {
  return name;
}

/**
 * @brief Agrega un nuevo elemento a la pila.
 * @param num Valor del disco que se va a apilar.
 */
void Pila::apilar(int num) {
  Nodo* nuevoNodo = new Nodo(num, cima); // Crea un nuevo nodo enlazado a la cima actual
  cima = nuevoNodo; // El nuevo nodo se convierte en la cima de la pila
  cout << "Pushing disk " << num << " onto post " << name << endl;
}

/**
 * @brief Extrae y devuelve el elemento en la cima de la pila.
 * @return Valor del disco eliminado. Retorna -1 si la pila está vacía.
 */
int Pila::desapilar() {
  if (cima == nullptr) { // Verifica si la pila está vacía
    cout << "ERROR: Stack is empty" << endl;
    return -1;
  }

  int num = cima->valor; // Guarda el valor del nodo superior
  Nodo* temp = cima;     // Almacena el nodo actual para eliminarlo luego
  cima = cima->siguiente; // Mueve la cima al siguiente nodo en la pila
  delete temp; // Libera la memoria del nodo eliminado
  cout << "Popping disk " << num << " from post " << name << endl;
  return num;
}

/**
 * @brief Verifica si la pila está vacía.
 * @return true si la pila está vacía, false en caso contrario.
 */
bool Pila::estaVacia() {
  return cima == nullptr;
}
