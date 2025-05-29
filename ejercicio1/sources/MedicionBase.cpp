#include "MedicionBase.h"

// =============================== Implementacion clase MedicionBase ===============================

MedicionBase::MedicionBase(float t) : tiempoMedicion(make_unique<float>(t)) {}

// Constructor de copia: crea un nuevo unique_ptr que apunta a una copia del float del otro objeto
// No se puede copiar directamente un unique_ptr porque su ownership es exclusivo, asi que se crea uno nuevo con el mismo valor apuntado por el unique_ptr del objeto original (otro)
MedicionBase::MedicionBase(const MedicionBase& otro)
    : tiempoMedicion(make_unique<float>(*otro.tiempoMedicion)) {}

// Operador de asignacion por copia
// Primero evita la autoasignacion, luego crea un nuevo unique_ptr con una copia del valor apuntado por el puntero del objeto original
MedicionBase& MedicionBase::operator=(const MedicionBase& otro) { 
    if (this != &otro) {
        tiempoMedicion = make_unique<float>(*otro.tiempoMedicion);
    }
    return *this;
}

float MedicionBase::getTiempo(){
    return *tiempoMedicion; 
}