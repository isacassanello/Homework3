#include "Figuras.h"
#define PI 3.141592653589793 // para calculas las areas

// plantilla genérica
template <typename T>
class ProcesadorFigura {
    public:
        static double calcularArea(const T& figura){
            throw logic_error("No se puede calcular el area para este tipo de figura");
        }
};

// especializacion para circulo
template <>
class ProcesadorFigura<Circulo> {
    public:
        static double calcularArea(const Circulo& c){
            return PI * c.getRadio() * c.getRadio();
        }
};

// especializacion para elipse
template <>
class ProcesadorFigura<Elipse> {
    public:
        static double calcularArea(const Elipse& e){
            return PI * e.getA() * e.getB();
        }
};

// especializacion para rectangulo
template <>
class ProcesadorFigura<Rectangulo> {
public:
    static double calcularArea(const Rectangulo& r) {
        return r.getAncho() * r.getLargo();
    }
};