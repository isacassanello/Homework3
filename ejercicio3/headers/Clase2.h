#pragma once
#include <iostream>
#include <string>
using namespace std;

// =========================== Clase 2 ===========================

class ConstruirJson {
    private:
        string doublesStr;
        string palabrasStr;
        string listasStr;

    public:
        void setVecDoubles(const string& vec);
        void setPalabras(const string& vec);
        void setListas(const string& vec);

        void imprimirJson() const;
};