#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <type_traits>
using namespace std;

// =========================== Clase 1 ===========================

template <typename T>
class JuntarDatos{
    private:
        vector<T> datos;

    public:
        void agregar(const T& valor){
            datos.push_back(valor);
        }

        string procesar() const{
            string resultado;

            // vec_doubles
            if constexpr(is_same_v<T, double>){
                resultado += "["
                for (size_t i = 0; i < datos.size(); i++){
                    resultado += to_string(datos[i]); // imprimo cada numero del vector
                    if (i != datos.size() - 1) resultado += ", "; // imprimo coma si no es el último
                }
                resultado += "],\n ";
            }

            // palabras
            else if constexpr(is_same_v<T, string>){
                resultado += "["
                for (size_t i = 0; i < datos.size(); i++){
                    resultado += "\"" + datos[i] + "\"";
                    if (i != datos.size() - 1) resultado += ", ";
                }
                resultado += "],\n ";
            }

            // listas
            else if constexpr(is_same_v<T, string>){
                resultado += "[\n";
                for (size_t i = 0; i < datos.size(); i++){
                    resultado += "       [";
                    for (size_t j = 0; j < datos[i].size(); j++){
                        resultado += to_string(datos[i][j]);
                        if (j != datos[i].size() - 1) cout << ", "; // imprimo coma si no es el último
                    }
                    resultado += "]"
                    if (i != datos.size() - 1) cout << ",";
                    resultado += "\n";
                }
                resultado += "      ]\n";
                resultado += "}\n";
            }

            else {
                resultado = "Tipo no soportado";
            }

            return resultado;
        }
};

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