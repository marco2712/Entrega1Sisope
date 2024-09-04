#include "pcb.h"

pcb::pcb() {
}



int pcb::get_uc() {
    return this->uc;
}

int pcb::get_pc() {
    return this->pc;
}

int pcb::get_acc() {
    return this->acc;
}


int pcb::get_mar() {
    return this->mar;
}

int pcb::get_mdr() {
    return this->mdr;
}

vector<string> pcb::get_icr() {
    return this->icr;
}

void pcb::set_acc(int _acc) {
    this->acc = _acc;
}


void pcb::set_pc(int _pc) {
    this->pc = _pc;
}


void pcb::set_uc(int _uc) {
    this->uc = _uc;
}

void pcb::set_mar(int _mar) {
    this->mar = _mar;
}

void pcb::set_mdr(int _mdr) {
    this->mdr = _mdr;
}

void pcb::set_icr(vector<string> _icr) {
    this->icr = _icr;
}


void pcb::imprimir_icr(){
    for(int i = 0; i < this->icr.size(); i++){
        cout << icr[i] << " ";
    }
    cout << endl;
}