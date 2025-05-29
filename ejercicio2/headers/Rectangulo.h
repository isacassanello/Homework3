#pragma once
#include <iostream>
#include "Punto.h"
using namespace std;

// ===================================== CLASE RECTANGULO =====================================

class Rectangulo{
    private:
        Punto verticeInferiorIzquierdo; 
        double ancho;
        double largo;
    
    public:
        Rectangulo() = default;
        Rectangulo(const Punto &vertice, double a, double l);

        Punto getVertice() const;
        double getAncho() const;
        double getLargo() const;

        void setVertice(const Punto &vertice);
        void setAncho(double a);
        void setLargo(double l);

        void mostrar() const;

        ~Rectangulo() = default;
};