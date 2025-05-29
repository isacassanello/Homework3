#pragma once
#include "Posicion.h"
#include "Presion.h"

// ============================ Clase SaveFlightData ============================

// Clase contenedora para serializar/deserializar ambas mediciones
class SaveFlightData{
    public:
        Posicion posicion; // objeto que representa la medicion de posicion
        Presion presion; // objeto que representa la medicion de presion

        SaveFlightData() = default; 
        SaveFlightData(const Posicion& p, const Presion& q);

        void serializar(ofstream& out) const; // metodo que serializa ambos objetos al archivo binario
        void deserializar(ifstream& in); // metodo que deserializa ambos objetos al archivo binario

        void imprimir() const; // metodo que imprime por pantalla el contenido de ambas mediciones

        ~SaveFlightData() = default;
};