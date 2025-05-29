#pragma once
#include "IMediciones.h"
#include "MedicionBase.h"

// ============================ Clase Posicion ============================

// Clase derivada que representa mediciones de posicion
class Posicion : public MedicionBase {
    public:
        float latitud, longitud, altitud; 

        Posicion() = default; 
        Posicion(float lat, float lon, float alt, float t); 
        
        Posicion(const Posicion& otro); // constructor de copia
        Posicion& operator=(const Posicion& otro); // asignacion por copia

        void serializar(ofstream& out) const override; // metodo heredado de la interfaz
        void deserializar(ifstream& in) override; // metodo heredado de la interfaz

        void imprimir() const override; // metodo heredado de la clase abstracta

        ~Posicion() = default;
};