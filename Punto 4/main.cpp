#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>  // Para manejar excepciones

#include "pcb.h"      // Incluir la clase pcb

using namespace std;

// Convierte una dirección en formato string a un entero
int int_address(string &address){
    if(address.size() > 1){
        address.erase(0, 1);  // Elimina el primer carácter si el tamaño es mayor a 1
    }
    int ans = stoi(address);  // Convierte el string a entero
    return ans;
}

// Imprime el contenido de la memoria (100 posiciones)
void print_memory(int (&memory2)[100]){
    for(int i = 0; i < 100;++i){
        cout << " Posicion en memoria: "<<  i  << "  " << "Dato: " << memory2[i] <<  endl; 
    }
}

// Divide una cadena de entrada en un vector de palabras utilizando espacios como delimitador
vector<string> split(const string &str) {
    vector<string> tokens;
    string token;
    size_t start = 0;
    size_t end = 0;

    // Encuentra cada espacio y divide la cadena
    while ((end = str.find(' ', start)) != string::npos) {
        token = str.substr(start, end - start);
        tokens.push_back(token);
        start = end + 1;
    }
    tokens.push_back(str.substr(start));  // Agrega el último token

    return tokens;
}

// Lee una línea de entrada desde la consola y la divide en parámetros
vector<string> read() {
    string instruction;
    getline(cin, instruction);
    vector<string> parameters = split(instruction);
    return parameters;
}

// Muestra el valor de un registro o posición de memoria dependiendo del parámetro dado
void shw(vector<string> parameters, pcb prueba, int (&memory2)[100]){
    if(parameters[1] == "ACC"){
        cout << "ACC: " << prueba.get_acc() << endl;
    }else if(parameters[1] == "ICR"){
        prueba.imprimir_icr();
    }else if(parameters[1] == "MAR"){
        cout << "MAR: " << prueba.get_mar() << endl;
    }else if(parameters[1] == "MDR"){
        cout << "MDR: " << prueba.get_mdr() << endl;
    }else if(parameters[1] == "UC"){    
        cout << "UC: " << prueba.get_uc() << endl;
    }else{
        int tmp1 = int_address(parameters[1]);
        cout << "En la direccion:  "<< parameters[1] << " esta: " << memory2[tmp1] << endl;
    }
}

// Suma el valor en la dirección dada al acumulador (ACC) o entre dos direcciones de memoria y almacena el resultado
void add (vector<string> parameters, pcb &prueba, int (&memory2)[100]){
    if(parameters[2] == "NULL" && parameters[3] == "NULL" && parameters[4] == "NULL"){
        int tmp1 = int_address(parameters[1]);  
        prueba.set_acc(prueba.get_acc() + memory2[tmp1]);
        prueba.set_mar(tmp1);
        prueba.set_mdr(memory2[tmp1]);
    }else if(parameters[3] == "NULL" && parameters[4] == "NULL"){
        int tmp1 = int_address(parameters[1]);  
        int tmp2 = int_address(parameters[2]);
        prueba.set_acc(memory2[tmp1]+ memory2[tmp2]);
        prueba.set_mar(tmp2);
        prueba.set_mdr(memory2[tmp2]);
    }else if(parameters[4] == "NULL"){
        int tmp1 = int_address(parameters[1]);  
        int tmp2 = int_address(parameters[2]);
        int tmp3 = int_address(parameters[3]);
        prueba.set_acc(memory2[tmp1]+ memory2[tmp2]);
        memory2[tmp3] = prueba.get_acc();
        prueba.set_acc(0);
        prueba.set_mar(tmp3);
        prueba.set_mdr(memory2[tmp3]);
    }
}

// Pausa la ejecución y muestra el estado actual de registros y memoria
void pause(pcb &prueba,int (&memory2)[100] ){
    cout << "ACC: " << prueba.get_acc() << endl;
    cout << "MAR: " << prueba.get_mar() << endl;
    cout << "MDR: " << prueba.get_mdr() << endl;
    cout << "ICR: ";
    prueba.imprimir_icr();
    cout << endl;
    print_memory(memory2);
}

int main() {
    pcb prueba;  // Crea un objeto PCB (Proceso Control Block)
    int memory2[100] = {0};  // Inicializa la memoria con 100 posiciones en 0
    vector<string> parameters = read();  // Lee la primera instrucción
    
    while(parameters[0] != "END"){  // Bucle hasta encontrar "END"
        
        string instruction = parameters[0];
        prueba.set_pc(prueba.get_pc() + 1);  // Incrementa el Program Counter (PC)
        
        if(instruction == "PAUSE"){
            prueba.set_uc(7);  // UC = 7 para PAUSE
            pause(prueba, memory2);
        }else{
            if(parameters.size() > 2){
                int mar = int_address(parameters[1]);
                prueba.set_mar(mar);
                prueba.set_icr(parameters);
            }

            // Decodifica e implementa la instrucción
            if(instruction == "SET"){
                prueba.set_uc(0);  // UC = 0 para SET
                prueba.set_mdr(stoi(parameters[2]));
                memory2[prueba.get_mar()] = prueba.get_mdr();

            } else if(instruction == "LDR"){
                prueba.set_uc(1);  // UC = 1 para LDR
                prueba.set_mdr(memory2[prueba.get_mar()]);
                prueba.set_acc(prueba.get_mdr());

            } else if(instruction == "ADD"){
                prueba.set_uc(2);  // UC = 2 para ADD
                add(parameters, prueba, memory2);

            } else if(instruction == "INC"){
                prueba.set_uc(3);  // UC = 3 para INC
                prueba.set_mdr(memory2[prueba.get_mar()] + 1);
                memory2[prueba.get_mar()] = prueba.get_mdr();

            } else if(instruction == "DEC"){
                prueba.set_uc(4);  // UC = 4 para DEC
                prueba.set_mdr(memory2[prueba.get_mar()] - 1);
                memory2[prueba.get_mar()] = prueba.get_mdr();

            } else if(instruction == "STR"){
                prueba.set_uc(5);  // UC = 5 para STR
                memory2[prueba.get_mar()] = prueba.get_acc();
                prueba.set_acc(0);

            } else if(instruction == "SHW"){
                prueba.set_uc(6);  // UC = 6 para SHW
                shw(parameters, prueba, memory2);
            }
        }
        vector<string> tmp = read();  // Lee la siguiente instrucción
        parameters = tmp;
    }

    return 0;
}
