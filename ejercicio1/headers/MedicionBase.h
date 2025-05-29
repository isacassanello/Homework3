#pragma once
#include <memory>
#include "IMediciones.h"

// ============================ Clase MedicionBase ============================

// Clase base abstracta con tiempo de medición como unique_ptr
class MedicionBase : public IMediciones {
    protected:
        unique_ptr<float> tiempoMedicion;

    public:
        MedicionBase() = default; 
        MedicionBase(float t);

        MedicionBase(const MedicionBase& otro); // constructor de copia 
        MedicionBase& operator=(const MedicionBase& otro); // asignacion por copia
        
        float getTiempo();
        virtual void imprimir() const = 0; 

        ~MedicionBase() = default;
};