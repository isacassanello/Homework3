#include "Punto.h"
#include "Circulo.h"
#include "Elipse.h"
#include "Rectangulo.h"
#include "ProcesadorFigura.h"
using namespace std;

int main(){
    cout << "-------------------------------------------------" << endl;

    // creo un circulo con centro (0,0) y radio 5
    Circulo c(Punto(0, 0), 5);
    cout << "\n=============== CIRCULO ===============" << endl;
    cout << "Informacion del circulo:" << endl;
    c.mostrar();
    cout << "Area del circulo: " << ProcesadorFigura<Circulo>::calcularArea(c) << "\n" << endl;

    // creo una elipse con centro (1,1), a = 4, b = 2
    Elipse e(Punto(1, 1), 4, 2);
    cout << "=============== ELIPSE ===============" << endl;
    cout << "Informacion del elipse:" << endl;
    e.mostrar();
    cout << "Area del elipse: " << ProcesadorFigura<Elipse>::calcularArea(e) << "\n" << endl;

    // creo un rectangulo con vertice inferior izquierdo (2,3), ancho = 6, largo = 8
    Rectangulo r(Punto(2, 3), 6, 8);
    cout << "=============== RECTANGULO ===============" << endl;
    cout << "Informacion del rectangulo:" << endl;
    r.mostrar();
    cout << "Area del rectangulo: " << ProcesadorFigura<Rectangulo>::calcularArea(r) << "\n" << endl;

    // creo un punto (34, 3)
    Punto p(Punto(34, 2));
    cout << "=============== PUNTO ===============" << endl;
    cout << "Informacion del punto: ";
    p.mostrar(); 
    try {
    cout << "\nArea del punto: " << ProcesadorFigura<Punto>::calcularArea(p) << endl;
    } catch (const std::logic_error& e) {
    cerr << "Error -> " << e.what() << endl;
    }
    cout << "\n";

    cout << "-------------------------------------------------" << endl;
}