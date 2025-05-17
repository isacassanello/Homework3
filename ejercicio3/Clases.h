#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

// =========================== Clase 1 ===========================

class JuntarDatos{
    private:
        using vecDoubles = pair<string, vector<double>>;
        using palabras = pair<string, vector<string>>;
        using listas = pair<string, vector<vector<int>>>;

        vecDoubles doubles;
        palabras strings;
        listas enteros;

    public:
        JuntarDatos(); // constructor que inicializa los nombres

        template<typename T>
        void agregar(const T& valor); // metodo template para agregar valores double o string

        // metodo para agregar listas de enteros
        void agregarLista(const vector<int>& fila);

        // getters
        const vecDoubles& getVecDoubles() const;
        const palabras& getPalabras() const;
        const listas& getListas() const;
};

// =========================== Clase 2 ===========================

class ConstruirJson {
    private:
        const JuntarDatos& datos;

    public:
        ConstruirJson(const JuntarDatos& juntarDatos);

        void imprimirJson() const;
};