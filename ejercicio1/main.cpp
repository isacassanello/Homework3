#include "headers.h"

int main(){
    cout << "--------------------------------------------------------" << "\n" << endl;

    // creo las mediciones
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3);
    Presion presion(101.3f, 5.8f, 6.1f);

    // creo el objeto de SaveFlightData
    SaveFlightData datosOriginales(posicion, presion);

    ofstream archivoSalida("vuelo.dat", ios::binary);
    if (!archivoSalida) {
        cerr << "Error al abrir archivo para escribir\n";
        return 1;
    }

    datosOriginales.serializar(archivoSalida);
    archivoSalida.close();

    // leo los datos desde el archivo en otro objeto
    SaveFlightData datosLeidos;

    ifstream archivoEntrada("vuelo.dat", ios::binary);
    if (!archivoEntrada) {
        cerr << "Error al abrir archivo para leer.\n";
        return 1;
    }

    datosLeidos.deserializar(archivoEntrada);
    archivoEntrada.close();

    // muestro los datos recuperados
    cout << "============ Datos Recuperados del Archivo ============\n" << endl;
    datosLeidos.imprimir();

    cout << "\n--------------------------------------------------------";

    return 0;
}