#pragma once
#include <iostream>
using namespace std;

// ===================================== CLASE PUNTO =====================================

class Punto{
    private:
        double coordenadaX;
        double coordenadaY;
    
    public:
        Punto() = default;
        Punto(double x, double y);

        double getX() const;
        double getY() const;

        void setX(double x);
        void setY(double y);

        void mostrar() const;     
        
        ~Punto() = default;
};