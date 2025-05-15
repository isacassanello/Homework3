#pragma once
#include <string> 
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

        double setX(double x);
        double setY(double y);

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

        Punto getCentro();
        double getRadio();

        double setCentro(const Punto &c);
        double setRadio(double r);

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

        double setCentro(const Punto &c);
        double setA(double a);
        double setB(double b);

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

        double setVertice(const Punto &vertice);
        double setAncho(double a);
        double setLargo(double l);

        void mostrar() const;

        ~Rectangulo() = default;
};

// ===================================== CLASE PROCESADOR FIGURA =====================================