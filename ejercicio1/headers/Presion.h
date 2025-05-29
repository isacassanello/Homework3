#pragma once
#include "IMediciones.h"
#include "MedicionBase.h"

// ============================ Clase Presion ============================

// Clase derivada que representa mediciones de presion
class Presion : public MedicionBase {
    public:
        float presionEstatica; // p
        float presionDinamica; // q

        Presion() = default; 
        Presion(float p, float q, float t); 
        
        Presion(const Presion& otro); // constructor de copia
        Presion& operator=(const Presion& otro); // asignacion por copia

        void serializar(ofstream& out) const override; // metodo heredado de la interfaz
        void deserializar(ifstream& in) override; // metodo heredado de la interfaz

        void imprimir() const override; // metodo heredado de la clase abstracta

        ~Presion() = default;
}; 