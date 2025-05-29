#pragma once
#include <iostream>
#include <fstream>
using namespace std;

// ============================ Clase IMediciones ============================

// Interfaz para todas las clases que se puedan serializar y deserializar
class IMediciones{
    public:
        virtual void serializar(ofstream& out) const = 0;
        virtual void deserializar(ifstream& in) = 0;
        ~IMediciones() = default;
};