#include "IMediciones.h"
#include "MedicionBase.h"
#include "Posicion.h"
#include "Presion.h"
#include "SaveFlightData.h"

int main(){
    cout << "--------------------------------------------------------" << "\n" << endl;

    // =================== CREACIÓN DE LAS MEDICIONES ===================

    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3); // creo un objeto de tipo Posicion con latitud, longitud, altitud y tiempo
    Presion presion(101.3f, 5.8f, 6.1f);  // creo un objeto de tipo Presion con presion estatica, presion dinamica y tiempo

    // =================== GUARDADO DE DATOS ===================

    SaveFlightData datosOriginales(posicion, presion); // creo un objeto SaveFlightData con las dos mediciones

    // abro un archivo binario para guardar los datos
    ofstream archivoSalida("vuelo.dat", ios::binary);
    if (!archivoSalida) {
        cerr << "Error al abrir archivo para escribir\n";
        return 1;
    }

    // serializo los datos al archivo
    datosOriginales.serializar(archivoSalida);
    archivoSalida.close();

    // =================== LECTURA DE DATOS DESDE ARCHIVO ===================

    SaveFlightData datosLeidos; // creo un nuevo objeto para cargar los datos desde el archivo

    // abro el archivo binario para lectura
    ifstream archivoEntrada("vuelo.dat", ios::binary);
    if (!archivoEntrada) {
        cerr << "Error al abrir archivo para leer.\n";
        return 1;
    }

    // seserializo los datos y los cargo en el nuevo objeto
    datosLeidos.deserializar(archivoEntrada);
    archivoEntrada.close();

    // =================== IMPRESIÓN DE LOS DATOS RECUPERADOS ===================

    cout << "============ Datos Recuperados del Archivo ============\n" << endl;
    datosLeidos.imprimir();

    cout << "\n--------------------------------------------------------";

    return 0;
}