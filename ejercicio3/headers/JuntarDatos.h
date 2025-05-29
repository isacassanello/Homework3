#pragma once
#include <string>
#include <vector>
#include <type_traits>
using namespace std;

// =========================== Clase 1 ===========================

// Clase plantilla que permite guardar elementos de cualquier tipo T y luego procesarlos devolviendo su representacion en formato JSON
template <typename T>
class JuntarDatos{
    private:
        vector<T> datos; // contenedor para los datos de tipo T

    public:
        // metodo para agregar un nuevo dato al vector
        void agregar(const T& valor){
            datos.push_back(valor);
        }

        // metodo que convierte los datos almacenados en un string con formato JSON
        string procesar() const{
            string resultado;

            // si el tipo es double, se construye un array JSON de decimales
            if constexpr(is_same_v<T, double>){
                resultado += "[";
                for (size_t i = 0; i < datos.size(); i++){
                    string valor = to_string(datos[i]);
                    valor.erase(valor.find_last_not_of('0') + 1); // elimina ceros finales innecesarios
                    resultado += valor; 
                    if (i != datos.size() - 1) resultado += ", "; // agrego una coma si no es el 'i' no esta en la ultima posicion del vector
                }
                resultado += "],";
            }

            // si el tipo es string, se construye un array JSON de strings
            else if constexpr(is_same_v<T, string>){
                resultado += "[";
                for (size_t i = 0; i < datos.size(); i++){
                    resultado += "\"" + datos[i] + "\""; // agrega comillas a cada string
                    if (i != datos.size() - 1) resultado += ", ";
                }
                resultado += "],";
            }

            // si el tipo es vector<int>, se construye un array JSON de arrays de enteros
            else if constexpr(is_same_v<T, vector<int>>){
                resultado += "[\n"; // comienzo del array de arrays
                for (size_t i = 0; i < datos.size(); i++){
                    resultado += "            [";
                    for (size_t j = 0; j < datos[i].size(); j++){
                        resultado += to_string(datos[i][j]); // agrega cada numero
                        if (j != datos[i].size() - 1) resultado += ", "; 
                    }
                    resultado += "]"; // cierra el array interno
                    if (i != datos.size() - 1) resultado += ",\n"; // coma y salto si no es el ultimo
                }
                resultado += "\n           ]"; // cierre del array externo
            }

            // si se intenta usar con un tipo no soportado, se indica en el string
            else {
                resultado = "Tipo no soportado";
            }

            return resultado;
        }
};