#include "Rectangulo.h"

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