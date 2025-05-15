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