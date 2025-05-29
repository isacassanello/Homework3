#include "Clase2.h"

// =========================== Clase 2 ===========================

void ConstruirJson::setVecDoubles(const string& vec){
    doublesStr = vec;
}

void ConstruirJson::setPalabras(const string& vec){
    palabrasStr= vec;
}

void ConstruirJson::setListas(const string& vec){
    listasStr = vec;
}

void ConstruirJson::imprimirJson() const {
    string json = "\n{";
    json += " \"vec_doubles\" : " + doublesStr + "\n";
    json += "  \"palabras\" : " + palabrasStr + "\n";
    json += "  \"listas\" : " + listasStr + "\n";
    json += "}";
    cout << json << endl;
}