#pragma once
#include <fstream>
#include <memory>
#include <iostream>
using namespace std;

// ============================ Clase IMediciones ============================

class IMediciones{
    public:
        virtual void serializar(ofstream& out) const = 0;
        virtual void deserializar(ifstream& in) = 0;
        ~IMediciones() = default;
};

// ============================ Clase MedicionBase ============================

class MedicionBase : public IMediciones {
    protected:
        unique_ptr<float> tiempoMedicion;

    public:
        MedicionBase() = default; // constructor por default
        MedicionBase(float t); // constructor con tiempo

        MedicionBase(const MedicionBase& otro); // constructor de copia 
        MedicionBase& operator=(const MedicionBase& otro);
        
        float getTiempo();
        virtual void imprimir() const = 0; // metodo virtual puro para imprimir

        ~MedicionBase() = default;
};

// ============================ Clase Presion ============================

class Presion : public MedicionBase {
    public:
        float presionEstatica; // p
        float presionDinamica; // q

        Presion() = default; // constructor por default
        Presion(float p, float q, float t); // constructor con las presiones y el tiempo
        
        Presion(const Presion& otro); // constructor de copia
        Presion& operator=(const Presion& otro);

        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in) override;

        void imprimir() const override;

        ~Presion() = default;
}; 

// ============================ Clase Posicion ============================
class Posicion : public MedicionBase {
    public:
        float latitud, longitud, altitud; 

        Posicion() = default;
        Posicion(float lat, float lon, float alt, float t);
        
        Posicion(const Posicion& otro); // constructor de copia
        Posicion& operator=(const Posicion& otro);

        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in) override;

        void imprimir() const override;

        ~Posicion() = default;
};

// ============================ Clase SaveFlightData ============================
class SaveFlightData{
    public:
        Posicion posicion;
        Presion presion;

        SaveFlightData() = default;
        SaveFlightData(const Posicion& p, const Presion& q);

        void serializar(ofstream& out) const;
        void deserializar(ifstream& in);

        void imprimir() const;

        ~SaveFlightData() = default;
};