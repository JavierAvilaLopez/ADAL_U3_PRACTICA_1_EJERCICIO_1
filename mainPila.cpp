#include <iostream>
using namespace std;
#include "Pila.h"

/**
 * @brief Muestra el menú de opciones en pantalla.
 */
void showMenu() {
    cout << "============================\n";
    cout << "        MAIN MENU           \n";
    cout << "============================\n";
    cout << "N <name> : Create a new stack with the given name.\n";
    cout << "A <num>  : Push a disk of size <num> onto the stack.\n";
    cout << "D        : Pop a disk from the stack.\n";
    cout << "B        : Delete the current stack.\n";
    cout << "S        : Exit the program.\n";
    cout << "============================\n";
}

int main() {
    char operation; // Variable para almacenar la opción ingresada por el usuario
    int num;        // Variable para almacenar el número ingresado en la opción 'A'

    Pila* stack = nullptr; // Puntero a la pila, inicializado como nullptr para evitar accesos inválidos

    showMenu(); // Muestra el menú al inicio del programa

    do {
        cout << "\nEnter an option: ";
        cin >> operation; // Se lee la opción ingresada por el usuario

        switch (operation) {
            case 'N': { // Opción para crear una nueva pila con un nombre
                string name;
                cin >> name; // Se lee el nombre de la pila

                // Si ya existe una pila, se libera la memoria antes de crear una nueva
                if (stack) delete stack;

                stack = new Pila(name); // Se crea una nueva pila con el nombre ingresado
                cout << "Stack '" << name << "' created successfully.\n";
                break;
            }
            case 'A': // Opción para apilar un número en la pila
                if (stack == nullptr) { // Verifica si hay una pila creada
                    cout << "ERROR: No stack created. Use 'N <name>' first.\n";
                } else {
                    cin >> num; // Se lee el número que se va a apilar
                    stack->apilar(num); // Se apila el número en la pila
                }
                break;
            case 'D': // Opción para desapilar un elemento de la pila
                if (stack == nullptr) { // Si no hay pila creada, muestra error
                    cout << "ERROR: No stack created.\n";
                } else if (stack->estaVacia()) { // Si la pila está vacía, muestra mensaje
                    cout << "EMPTY\n";
                } else {
                    cout << "Removed disk: " << stack->desapilar() << endl;
                }
                break;
            case 'B': // Opción para eliminar la pila
                if (stack != nullptr) { // Verifica si hay una pila creada
                    delete stack; // Libera la memoria de la pila
                    stack = nullptr; // Se establece en nullptr para evitar accesos inválidos
                    cout << "Stack deleted successfully.\n";
                } else {
                    cout << "No stack to delete.\n";
                }
                break;
            case 'S': // Opción para salir del programa
                cout << "Exiting the program...\n";
                break;
            default: // Manejo de opción no válida
                cout << "Invalid command. Please try again.\n";
        }
    } while (operation != 'S'); // Se repite el bucle hasta que el usuario elija salir ('S')

    // Antes de salir, se libera la memoria si hay una pila creada
    if (stack != nullptr) {
        delete stack;
    }

    return 0; // Fin del programa
}
