#ifndef MACHINE_H
#define MACHINE_H

#include "Cpu.h"
#include <fstream>
#include <sstream>

class Machine {
private:
    Memory memory;
    Cpu cpu;
    void displayMenu();
    void resetSystem();
    vector<string> loadProgramFromFile(const string& filename);
    vector<string> parseInstructions(const string& input);
    void displayFullState();

public:
    Machine() : cpu(memory) {}
    void run();

};

#endif //MACHINE_H
