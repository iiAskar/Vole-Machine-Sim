#include "Memory.h"

Memory::Memory() {
    // Initialize memory with "00"
    for(int i = 0; i < size; i++) {
        memory[i] = "00";
    }
}

string Memory::getCellAddress(int address) {
    if (address >= 0 && address < size) {
        return memory[address];
    }
    return "00";
}

void Memory::setCellAddress(int address, string value) {
    if (address >= 0 && address < size) {
        memory[address] = value;
    }
}

void Memory::displayMemory() {
    cout << endl;
    for(int i = 0, j = 0 ; i < size; i++) {

        
        cout << setfill('0') << setw(2) << j++ << " |";
        cout << memory[i] << " " << memory[++i] << "| " << setfill('0') << setw(2) << j++;
        
        
        cout << endl;
    }
}
