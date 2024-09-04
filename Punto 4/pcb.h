#include <string>
#include <vector>
#include <iostream>

#ifndef PCB_H 
#define PCB_H 

using namespace std;

class pcb{
    private:
        int acc = 0;   // Acumulator
        int pc = 100;
        int uc = 0;    // Control Unit
        int mar = 100;   // Memory Address Register
        int mdr = 0;   // Memory Data Register
        vector<string> icr;   // Instruction Counter Register
    public:
    pcb();


    int get_acc();
    int get_pc();
    int get_uc();
    int get_mar();
    int get_mdr();
    vector<string> get_icr();

    void set_acc(int _uc);
    void set_pc(int _pc);
    void set_uc(int _uc);
    void set_mar(int _mar);
    void set_mdr(int _mdr);
    void set_icr(vector<string> _icr);

    void imprimir_icr();
};

#endif // PCB_H 