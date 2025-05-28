#include "headers.h"

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

// =============================== Implementacion clase Presion ===============================

Presion::Presion(float p, float q, float t) : MedicionBase(t), presionEstatica(p), presionDinamica(q) {}

// Constructor de copia: copia cada uno de los miembros del objeto original
Presion::Presion(const Presion& otro)
    : MedicionBase(otro), // llama al constructor de copia de la clase base para copiar el tiempo correctamente
    presionEstatica(otro.presionEstatica),
    presionDinamica(otro.presionDinamica) {}

// Operador de asignacion por copia
// Se asegura de que no haya autoasignacion y luego copia cada miembro manualmente
Presion& Presion::operator=(const Presion& otro) {
    if (this != &otro) {
        MedicionBase::operator=(otro);
        presionEstatica = otro.presionEstatica;
        presionDinamica = otro.presionDinamica;
    }
    return *this;
}

// Guardo los datos de un objeto Presion en un archivo binario
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
    cout << "           El primer elmento es latitud, el segundo longitud y el tercero altitud" << endl;
    cout << "   -> Tiempo: " << *tiempoMedicion << endl;
}

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