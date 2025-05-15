#include "Figuras.h"
#include <iostream>
using namespace std;

// ===================================== IMPLEMENTACION CLASE PUNTO =====================================

Punto::Punto(double x, double y) : coordenadaX(x), coordenadaY(y) {}

double Punto::getX() const{
    return coordenadaX;
}

double Punto::getY() const{
    return coordenadaY;
}

double Punto::setX(double x){
    this->coordenadaX = x;
}

double Punto::setY(double y){
    this->coordenadaY = y;
}

void Punto::mostrar() const{
    cout << "(" << coordenadaX << ", " << coordenadaY << ")" << endl;
}  

// ===================================== IMPLEMENTACION CLASE CIRCULO =====================================

Circulo::Circulo(const Punto &centro, double r) : centro(centro), radio(r) {}

Punto Circulo::getCentro(){
    return centro;
}
double Circulo::getRadio(){
    return radio;
}

double Circulo::setCentro(const Punto &c){
    this->centro = c;
}
double Circulo::setRadio(double r){
    this->radio = r;
}

void Circulo::mostrar() const{
    cout << "Centro del circulo: "; centro.mostrar();
    cout << "\nRadio del circulo: " << radio << endl;
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

double Elipse::setCentro(const Punto &c){
    this->centro = c;
}

double Elipse::setA(double a){
    this->a = a;
}

double Elipse::setB(double b){
    this->b = b;
}

void Elipse::mostrar() const{
    cout << "Centro del Elipse: "; centro.mostrar();
    cout << "\nSemieje mayor (a): " << a << "\nSemieje menor (b): " << b << endl;
}


// ===================================== IMPLEMENTACION CLASE CIRCULO =====================================

Rectangulo::Rectangulo(const Punto &vertice, double a, double l) 
    : verticeInferiorIzquierdo(vertice), ancho(a), largo(a) {}

Punto Rectangulo::getVertice() const{
    return verticeInferiorIzquierdo;
}

double Rectangulo::getAncho() const{
    return ancho;
}

double Rectangulo::getLargo() const{
    return largo;
}

double Rectangulo::setVertice(const Punto &vertice){
    this->verticeInferiorIzquierdo = vertice;
}

double Rectangulo::setAncho(double a){
    this->ancho = a;
}

double Rectangulo::setLargo(double l){
    this->largo = l;
}

void Rectangulo::mostrar() const{
    cout << "Vertice inferior izquierdo: "; verticeInferiorIzquierdo.mostrar();
    cout << "\nAncho del rectangulo: " << ancho << "\nLargo del rectangulo: " << largo << endl;
}


// ===================================== IMPLEMENTACION CLASE PROCESADOR FIGURA =====================================