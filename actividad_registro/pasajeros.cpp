#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct nodo {
    char nombre[50];
    int documento;
    int destino;
    nodo *sig;
};

nodo *cab, *aux, *aux2;

void registrar() {
    aux = new nodo;
    cout << "Nombre: ";
    cin >> aux->nombre;
    cout << "Documento: ";
    cin >> aux->documento;
    cout << "Destino (1: La Bocana, 2: Pianguita, 3: Ladrilleros): ";
    cin >> aux->destino;
    aux->sig = NULL;
    if(!cab) {
        cab = aux;
    } else {
        aux2 = cab;
        while(aux2->sig != NULL) {
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }
}

void mostrar() {
    aux = cab;
    if (aux == NULL) {
        cout << "No hay pasajeros registrados." << endl;
        return;
    }
    cout << "Lista de pasajeros:" << endl;
    while(aux != NULL) {
        cout << "Nombre: " << aux->nombre << ", Documento: " << aux->documento << ", Destino: " << aux->destino << " - ";
        switch(aux->destino) {
            case 1:
                cout << "La Bocana";
                break;
            case 2:
                cout << "Pianguita";
                break;
            case 3:
                cout << "Ladrilleros";
                break;
            default:
                cout << "Desconocido";
        }
        cout << endl;
        aux = aux->sig;
    }
}

void ordenar() {
    int tempDoc, tempDest;
    char tempNombre[50];
    aux2 = cab;
    while(aux2->sig != NULL) {
        aux = cab;
        while(aux->sig != NULL) {
            if(aux->destino > aux->sig->destino || 
               (aux->destino == aux->sig->destino && aux->documento > aux->sig->documento)) {
                //* Intercambiar destino
                tempDest = aux->destino;
                aux->destino = aux->sig->destino;
                aux->sig->destino = tempDest;
                
                //* Intercambiar documento
                tempDoc = aux->documento;
                aux->documento = aux->sig->documento;
                aux->sig->documento = tempDoc;
                
                //* Intercambiar nombre
                strcpy(tempNombre, aux->nombre);
                strcpy(aux->nombre, aux->sig->nombre);
                strcpy(aux->sig->nombre, tempNombre);
            }
            aux = aux->sig;
        }
        aux2 = aux2->sig;
    }
}

int main() {
    int opcion;
    do {
        cout << "\nMenu" << endl
             << "1. Registrar Pasajero" << endl
             << "2. Mostrar Pasajeros" << endl
             << "3. Ordenar Pasajeros" << endl
             << "4. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                registrar();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                ordenar();
                cout << "Pasajeros ordenados exitosamente." << endl;
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while(opcion != 4);

    // Liberar memoria
    while(cab != NULL) {
        aux = cab;
        cab = cab->sig;
        delete aux;
    }

    return 0;
}