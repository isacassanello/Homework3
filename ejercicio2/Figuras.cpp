#include "Figuras.h"

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

// ===================================== IMPLEMENTACION CLASE CIRCULO =====================================

Rectangulo::Rectangulo(const Punto &vertice, double a, double l) 
    : verticeInferiorIzquierdo(vertice), ancho(a), largo(l) {}

Punto Rectangulo::getVertice() const{
    return verticeInferiorIzquierdo;
}

double Rectangulo::getAncho() const{
    return ancho;
}

double Rectangulo::getLargo() const{
    return largo;
}

void Rectangulo::setVertice(const Punto &vertice){
    this->verticeInferiorIzquierdo = vertice;
}

void Rectangulo::setAncho(double a){
    this->ancho = a;
}

void Rectangulo::setLargo(double l){
    this->largo = l;
}

void Rectangulo::mostrar() const{
    cout << "   - Vertice inferior izquierdo: "; verticeInferiorIzquierdo.mostrar();
    cout << "   - Ancho: " << ancho << "\n   - Largo: " << largo << "\n" << endl;
}