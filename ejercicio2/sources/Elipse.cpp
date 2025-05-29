#include "Elipse.h"

// ===================================== IMPLEMENTACION CLASE ELIPSE =====================================

Elipse::Elipse(const Punto &c, double a, double b) : centro(c), a(a), b(b) {}

Punto Elipse::getCentro() const{
    return centro;
}

double Elipse::getA() const{
    return a;
}

double Elipse::getB() const{
    return b; 
}

void Elipse::setCentro(const Punto &c){
    this->centro = c;
}

void Elipse::setA(double a){
    this->a = a;
}

void Elipse::setB(double b){
    this->b = b;
}

void Elipse::mostrar() const{
    cout << "   - Centro del Elipse: "; centro.mostrar();
    cout << "   - Semieje mayor (a): " << a << "\n   - Semieje menor (b): " << b << "\n" << endl;
}