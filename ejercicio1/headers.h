#pragma once
#include <fstream>
#include <memory>
#include <iostream>
using namespace std;

// ============================ Clase IMediciones ============================

// Interfaz para todas las clases que se puedan serializar y deserializar
class IMediciones{
    public:
        virtual void serializar(ofstream& out) const = 0;
        virtual void deserializar(ifstream& in) = 0;
        ~IMediciones() = default;
};

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