#pragma once
#include <iostream>
#include "Punto.h"
using namespace std;

// ===================================== CLASE CIRCULO =====================================

class Circulo{
    private:
        Punto centro;
        double radio;
    
    public:
        Circulo() = default;
        Circulo(const Punto &centro, double r);

        Punto getCentro() const;
        double getRadio() const;

        void setCentro(const Punto &c);
        void setRadio(double r);

        void mostrar() const;

        ~Circulo() = default;
};