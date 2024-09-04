#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Función para aplicar la Criba de Eratóstenes
void criba_eratostenes(vector<bool>& es_primo, int max_valor) {
    es_primo[0] = es_primo[1] = false; // 0 y 1 no son primos
    for (int i = 2; i <= sqrt(max_valor); i++) {
        if (es_primo[i]) {
            for (int j = i * i; j <= max_valor; j += i) {
                es_primo[j] = false;
            }
        }
    }
}

int main() {
    string input;
    cout << "Ingrese los numeros en una sola linea, separados por espacios:\n";
    getline(cin, input);

    vector<int> numeros;
    int numero = 0;
    bool leyendo_numero = false;

    // Recorrer la cadena de entrada para extraer los números
    for (char c : input) {
        if (isdigit(c)) {
            numero = numero * 10 + (c - '0');
            leyendo_numero = true;
        } else if (leyendo_numero) {
            numeros.push_back(numero);
            numero = 0;
            leyendo_numero = false;
        }
    }
    
    // Añadir el último número si estaba siendo leído
    if (leyendo_numero) {
        numeros.push_back(numero);
    }

    // Encontrar el valor máximo en la lista
    int max_valor = *max_element(numeros.begin(), numeros.end());

    // Crear una tabla de booleanos para almacenar si un número es primo
    vector<bool> es_primo(max_valor + 1, true);

    // Aplicar la Criba de Eratóstenes
    criba_eratostenes(es_primo, max_valor);

    // Verificar y mostrar los números primos
    cout << "Números primos en la lista:\n";
    for (int num : numeros) {
        if (es_primo[num]) {
            cout << num << " es primo\n";
        } else {
            cout << num << " no es primo\n";
        }
    }

    return 0;
}
