#include "Memory.h"

Memory::Memory() {
    // Initialize memory with "00"
    for(int i = 0; i < size; i++) {
        memory[i] = "0000";
    }
}

string Memory::getCellAddress(int address) {
    if (address >= 0 && address < size) {
        return memory[address];
    }
    return "0000";
}

void Memory::setCellAddress(int address, string value) {
    if (address >= 0 && address < size) {
        memory[address] = value;
    }
}

void Memory::displayMemory() {
    // Display column headers
    cout << "\n    ";
    for(int i = 0; i < 16; i++) {
        cout << hex << uppercase <<  setw(4) << '0'<<i ;
    }
    cout<<"\n------------------------------------------------------------------------------------";

    // Display memory contents with row headers
    for(int i = 0; i < size; i++) {
        if(i % 16 == 0) {
            cout << "\n" << hex << uppercase << setw(2)<< (i/16) << "0| ";
        }
        cout << memory[i] << " ";
    }
    cout << endl;
}