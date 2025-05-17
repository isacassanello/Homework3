#include "Clases.h"

int main(){
    cout << "-------------------------------------------------" << "\n" << endl;
    
    JuntarDatos colectorDatos;

    // agrego doubles
    colectorDatos.agregar(1.3);
    colectorDatos.agregar(2.1);
    colectorDatos.agregar(3.2);

    // agrego strings
    colectorDatos.agregar(string("Hola"));
    colectorDatos.agregar(string("Mundo"));

    // agrego listas de enteros
    colectorDatos.agregarLista({1, 2});
    colectorDatos.agregarLista({3, 4});

    // creo el constructor de JSON
    ConstruirJson constructor(colectorDatos);
    constructor.imprimirJson();

    cout << "\n-------------------------------------------------";

    return 0;
}