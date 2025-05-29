#include "Presion.h"

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