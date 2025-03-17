#include"Pila.h"

// Constructor

Pila::Pila(string name) {
  this->name=name;
  this->cima = nullptr; // Inicializamos la pila vacia

}

// Devuelve el nombre de la pila
std::string Pila::nombrePila() {
  return name;
}

// Apilar disco
void Pila::apilar(int num) {
  Nodo* nuevoNodo = new Nodo(num, cima);
  cima = nuevoNodo; // Ahora la cima es el nuevo nodo
  cout<<"Apilando disco "<< num <<" en poste "<<name<<endl;
}


// Desapilar un disco
int Pila::desapilar(){

  if(cima==nullptr){
    cout<<"ERROR: Cima vacia"<<endl;
    return -1;
  }

  int num = cima->valor;
  Nodo* temp = cima;
  cima = cima->siguiente; // Mover la cima al siguiente nodo
  delete temp;
  cout<<"Desapilando disco "<< num <<" del poste "<<name<<endl;
  return num;
}

// Verificar si la pila está vacía
bool Pila::estaVacia() {
  return cima == nullptr;
}

