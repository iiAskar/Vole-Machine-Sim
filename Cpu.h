#ifndef CPU_H
#define CPU_H

#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include "Memory.h"
#include "Register.h"

using namespace std;

class Cpu {
private:
    Memory& memory;
    Register registers;
    int programCounter;
    bool halted;
    string instructionRegister;

    // Helper methods
    int hexToInt(const string& hex);
    string intToHex(int value);

public:
    explicit Cpu(Memory& mem);
    void setProgramCounter(int address) { programCounter = address; }
    void reset();
    bool isHalted() const;
    void executeInstruction();
    void displayState();
    Register& getRegisters();

    // Add the missing getter
    int getProgramCounter() const { return programCounter; }
};

#endif
