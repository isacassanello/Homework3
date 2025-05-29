#include "Punto.h"

// ===================================== IMPLEMENTACION CLASE PUNTO =====================================

Punto::Punto(double x, double y) : coordenadaX(x), coordenadaY(y) {}

double Punto::getX() const{
    return coordenadaX;
}

double Punto::getY() const{
    return coordenadaY;
}

void Punto::setX(double x){
    this->coordenadaX = x;
}

void Punto::setY(double y){
    this->coordenadaY = y;
}

void Punto::mostrar() const{
    cout << "(" << coordenadaX << ", " << coordenadaY << ")" << endl;
}  