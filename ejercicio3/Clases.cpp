#include "Clases.h"
#include <type_traits>

// =========================== Clase 1 ===========================

JuntarDatos::JuntarDatos() {
    doubles.first = "vec_doubles";
    strings.first = "palabras";
    enteros.first = "listas";
}

template<typename T>

void JuntarDatos::agregar(const T& valor){
    if constexpr (is_same_v<T, double>) {
        doubles.second.push_back(valor);
    } else if constexpr (is_same_v<T, string>) {
        strings.second.push_back(valor);
    } else {
        static_assert(is_same_v<T, double> || is_same_v<T, string>, "Tipo no soportado"); // sizeof(T) == 0 nunca es verdadera para ningún tipo válido.
    }
}

void JuntarDatos::agregarLista(const vector<int>& fila){
    enteros.second.push_back(fila);
}

const JuntarDatos::vecDoubles& JuntarDatos::getVecDoubles() const {
    return doubles;
}

const JuntarDatos::palabras& JuntarDatos::getPalabras() const {
    return strings;
}

const JuntarDatos::listas& JuntarDatos::getListas() const {
    return enteros;
}

// =========================== Clase 2 ===========================

ConstruirJson::ConstruirJson(const JuntarDatos& juntarDatos) : datos(juntarDatos) {}

void ConstruirJson::imprimirJson() const{
    cout << "{";

    // vec_doubles
    const auto& vec = datos.getVecDoubles(); // obtengo la referencia al par<string, vector<double>> que guarda los doubles
    cout << " \"" << vec.first << "\" : [";
    for (size_t i = 0; i < vec.second.size(); i++){
        cout << vec.second[i]; // imprimo cada numero del vector
        if (i != vec.second.size() - 1) cout << ", "; // imprimo coma si no es el último
    }
    cout << "],\n ";

    // palabras
    const auto& palabras = datos.getPalabras();
    cout << " \"" << palabras.first << "\" : [";
    for (size_t i = 0; i < palabras.second.size(); i++){
        cout << "\"" << palabras.second[i] << "\""; // imprimo cada string del vector
        if (i != palabras.second.size() - 1) cout << ", "; // imprimo coma si no es el último
    }
    cout << "],\n ";

    // listas
    const auto& listas = datos.getListas();
    cout << " \"" << listas.first << "\" : [\n";
    for (size_t i = 0; i < listas.second.size(); i++){
        cout << "       [";
        for (size_t j = 0; j < listas.second[i].size(); j++){
            cout << listas.second[i][j];
            if (j != listas.second[i].size() - 1) cout << ", "; // imprimo coma si no es el último
        }
        cout << "]";
        if (i != listas.second.size() - 1) cout << ",";
        cout << "\n";
    }
    cout << "      ]\n";
    cout << "}\n";
}

// instanciacion explicita de los tipos usados
template void JuntarDatos::agregar<double>(const double&);
template void JuntarDatos::agregar<string>(const string&);