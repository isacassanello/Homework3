#include "Posicion.h"

// =============================== Implementacion clase Posicion ===============================

Posicion::Posicion(float lat, float lon, float alt, float t) : MedicionBase(t), latitud(lat), longitud(lon), altitud(alt) {}

// idem logica Presion
Posicion::Posicion(const Posicion& otro)
    : MedicionBase(otro), 
    latitud(otro.latitud),
    longitud(otro.longitud),
    altitud(otro.altitud) {}

// idem logica Presion
Posicion& Posicion::operator=(const Posicion& otro) {
    if (this != &otro) {
        MedicionBase::operator=(otro);
        latitud = otro.latitud;
        longitud = otro.longitud;
        altitud = otro.altitud;
    }
    return *this;
}

// idem logica Presion
void Posicion::serializar(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float)); 
}

// idem logica Presion
void Posicion::deserializar(ifstream& in) {
    in.read(reinterpret_cast<char*>(&latitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(float));
    float t;
    in.read(reinterpret_cast<char*>(&t), sizeof(float));
    tiempoMedicion = make_unique<float>(t); 
}

void Posicion::imprimir() const{
    cout << "   -> Posicion: (" << latitud << ", " << longitud << ", " << altitud << ")" << endl;
    cout << "      * El primer elmento es latitud, el segundo longitud y el tercero altitud" << endl;
    cout << "   -> Tiempo: " << *tiempoMedicion << endl;
}