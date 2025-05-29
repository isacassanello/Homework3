#include "SaveFlightData.h"

// ============================ Implementacion clase SaveFlightData ============================

SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q) 
    : posicion(p), presion(q) {}

// Serializa ambos objetos llamando a sus respectivos metodos
void SaveFlightData::serializar(ofstream& out) const{
    posicion.serializar(out);
    presion.serializar(out);
}

// Deserializa ambos objetos desde el archivo binario en el mismo orden en que fueron escritos
void SaveFlightData::deserializar(ifstream& in){
    posicion.deserializar(in);
    presion.deserializar(in);
}

// Imprime ambas mediciones usando sus metodos de impresion
void SaveFlightData::imprimir() const{
    cout << "Medicion de Posicion:" << endl;
    posicion.imprimir();
    cout << "\nMedicion de Presion:" << endl;
    presion.imprimir();
}