#include "headers.h"

// =============================== Implementacion clase MedicionBase ===============================

MedicionBase::MedicionBase(float t) : tiempoMedicion(make_unique<float>(t)) {}

MedicionBase::MedicionBase(const MedicionBase& otro)
    : tiempoMedicion(make_unique<float>(*otro.tiempoMedicion)) {}

// operador de asignacion por copia
MedicionBase& MedicionBase::operator=(const MedicionBase& otro) { 
    if (this != &otro) {
        tiempoMedicion = make_unique<float>(*otro.tiempoMedicion);
    }
    return *this;
}

float MedicionBase::getTiempo(){
    return *tiempoMedicion;
}

// =============================== Implementacion clase Presion ===============================

Presion::Presion(float p, float q, float t) : MedicionBase(t), presionEstatica(p), presionDinamica(q) {}

Presion::Presion(const Presion& otro)
    : MedicionBase(otro), // llama al constructor de copia de la clase base
    presionEstatica(otro.presionEstatica),
    presionDinamica(otro.presionDinamica) {}

// operador de asignacion por copia
Presion& Presion::operator=(const Presion& otro) {
    if (this != &otro) {
        MedicionBase::operator=(otro);
        presionEstatica = otro.presionEstatica;
        presionDinamica = otro.presionDinamica;
    }
    return *this;
}

// guardo los datos de un objeto Presion en un archivo binario
void Presion::serializar(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(float));
        // 1) &presionEstatica obtiene la direccion de memoria donde esta almacenado el valor float presionEstatica
        // 2) reinterpret_cast<const char*> -> C++ no permite escribir directamente tipos como float en archivos. Necesita un puntero a char (byte)
        // 3) reinterpret_cast<const char*> convierte el puntero a float en un puntero a char, para que ofstream::write pueda escribir los bytes del numero en crudo
        // 4) sizeof(float) indica cuantos bytes hay que escribir 
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(float));
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float)); // accedo al contenido del puntero unique_ptr<float> usando .get() -> devuelve un puntero float*
}

void Presion::deserializar(ifstream& in) {
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(float));
        // lee los primeros 4 bytes del archivo y los guarda como un float en presionEstatica
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(float));
        // lee los siguientes 4 bytes del archivo y los guarda como un float en presionDinamica
    float t;
    in.read(reinterpret_cast<char*>(&t), sizeof(float));
        // lee los siguientes 4 bytes del archivo y los guarda en una variable temporal t
    tiempoMedicion = make_unique<float>(t); // creo un puntero que apunta a una copia de t
        // esto reconstruye el estado original del unique_ptr sin moverlo desde otro objeto
}

void Presion::imprimir() const {
    cout << "   -> Presion Estatica: " << presionEstatica << endl;
    cout << "   -> Presion Dinamica: " << presionDinamica << endl;
    cout << "   -> Tiempo: " << *tiempoMedicion << endl;
}

// =============================== Implementacion clase Posicion ===============================

Posicion::Posicion(float lat, float lon, float alt, float t) : MedicionBase(t), latitud(lat), longitud(lon), altitud(alt) {}

Posicion::Posicion(const Posicion& otro)
    : MedicionBase(otro), // llama al constructor de copia de la clase base
    latitud(otro.latitud),
    longitud(otro.longitud),
    altitud(otro.altitud) {}

// operador de asignacion por copia
Posicion& Posicion::operator=(const Posicion& otro) {
    if (this != &otro) {
        MedicionBase::operator=(otro);
        latitud = otro.latitud;
        longitud = otro.longitud;
        altitud = otro.altitud;
    }
    return *this;
}

// guardo los datos de un objeto Presion en un archivo binario
void Posicion::serializar(ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float)); // accedo al contenido del puntero unique_ptr<float> usando .get() -> devuelve un puntero float*
}

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
    cout << "   -> Tiempo: " << *tiempoMedicion << endl;
}

// ============================ Implementacion clase SaveFlightData ============================

SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q) 
    : posicion(p), presion(q) {}

void SaveFlightData::serializar(ofstream& out) const{
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(ifstream& in){
    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir() const{
    cout << "Medicion de Posicion:" << endl;
    posicion.imprimir();
    cout << "\nMedicion de Presion:" << endl;
    presion.imprimir();
}