#pragma once
#include <iostream>
#include <string>
using namespace std;

// =========================== Clase 2 ===========================

// Esta clase permite construir un JSON combinando diferentes secciones:
// - numeros decimales (vec_doubles)
// - palabras (palabras)
// - listas de enteros (listas)
class ConstruirJson {
    private:
        // cadenas de texto que representan cada parte del JSON
        string doublesStr;
        string palabrasStr;
        string listasStr;

    public:
        // metodos para establecer el contenido de cada parte del JSON
        void setVecDoubles(const string& vec); // guarda el JSON parcial de vec_doubles
        void setPalabras(const string& vec); // guarda el JSON parcial de palabras
        void setListas(const string& vec); // guarda el JSON parcial de listas

        // metodo para imprimir el JSON completo en formato final
        void imprimirJson() const;
};