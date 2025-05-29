#pragma once
#include <iostream>
#include "Punto.h"
using namespace std;

// ===================================== CLASE ELIPSE =====================================

class Elipse{
    private:
        Punto centro;
        double a; // semieje mayor 
        double b; // semieje menor 
    
    public:
        Elipse() = default;
        Elipse(const Punto &centro, double a, double b);

        Punto getCentro() const;
        double getA() const;
        double getB() const;

        void setCentro(const Punto &c);
        void setA(double a);
        void setB(double b);

        void mostrar() const;

        ~Elipse() = default;
};