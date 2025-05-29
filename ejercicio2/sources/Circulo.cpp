#include "Circulo.h"

// ===================================== IMPLEMENTACION CLASE CIRCULO =====================================

Circulo::Circulo(const Punto &centro, double r) : centro(centro), radio(r) {}

Punto Circulo::getCentro() const{
    return centro;
}
double Circulo::getRadio() const{
    return radio;
}

void Circulo::setCentro(const Punto &c){
    this->centro = c;
}
void Circulo::setRadio(double r){
    this->radio = r;
}

void Circulo::mostrar() const{
    cout << "   - Centro del circulo: "; centro.mostrar();
    cout << "   - Radio del circulo: " << radio << "\n" << endl;
}