#include "Clases.h"

int main(){
    cout << "-------------------------------------------------" << "\n" << endl;
    cout << "Visualizacion del JSON:\n";
    
    JuntarDatos<double> datosDoubles;

    // agrego doubles
    datosDoubles.agregar(1.3);
    datosDoubles.agregar(2.1);
    datosDoubles.agregar(3.2);

    JuntarDatos<string> datosStrings;

    // agrego strings
    datosStrings.agregar("Hola");
    datosStrings.agregar("Mundo");

    JuntarDatos<vector<int>> datosListas;

    // agrego listas de enteros
    datosListas.agregar({1, 2});
    datosListas.agregar({3, 4});

    // creo el constructor de JSON
    ConstruirJson constructor;

    constructor.setVecDoubles(datosDoubles.procesar());
    constructor.setPalabras(datosStrings.procesar());
    constructor.setListas(datosListas.procesar());
    
    constructor.imprimirJson();

    cout << "\n-------------------------------------------------";

    return 0;
}