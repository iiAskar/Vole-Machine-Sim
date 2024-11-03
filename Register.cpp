
#include "Register.h"
Register::Register() {
    // Initialize registers with "00"
    for(int i = 0; i < size; i++) {
        registers[i] = "00";
    }
}
string Register::getRegister(int reg) {
    if (reg >= 0 && reg < size) {
        return registers[reg];
    }
    return "00";
}
void Register::setRegister(int reg, string value) {
    if (reg >= 0 && reg < size) {
        registers[reg] = value;
    }
}

void Register::displayRegisters() {
    cout << "\nRegisters:" << endl;
    for(int i = 0; i < size; i++) {
        cout << hex << uppercase << i << ": " << registers[i] << " ";
        if((i + 1) % 4 == 0) cout << endl;
    }
}
