#include "Cpu.h"

int Cpu::hexToInt(const string& hex) {
    try {
        return stoi(hex, nullptr, 16);
    } catch(const exception& e) {
        throw runtime_error("Invalid hex value: " + hex);
    }
}

string Cpu::intToHex(int value) {
    stringstream ss;
    ss << uppercase << hex << setw(2) << setfill('0') << (value & 0xFF);
    return ss.str();
}

Cpu::Cpu(Memory& mem) : memory(mem), programCounter(0), halted(false) {
    reset();
}
void Cpu::reset() {
    programCounter = 0;
    halted = false;
    instructionRegister = "0000";
    registers = Register();
}

bool Cpu::isHalted() const {
    return halted;
}

void Cpu::executeInstruction() {
    // Fetch
    try {
        instructionRegister = memory.getCellAddress(programCounter++);
    } catch(const exception& e) {
        throw runtime_error("Memory access error at address " + to_string(programCounter - 1));
    }

    // Decode
    if(instructionRegister.length() != 4) {
        throw runtime_error("Invalid instruction length: " + instructionRegister);
    }

    int opCode = hexToInt(instructionRegister.substr(0, 1));
    int R = hexToInt(instructionRegister.substr(1, 1));
    int X = hexToInt(instructionRegister.substr(2, 1));
    int Y = hexToInt(instructionRegister.substr(3, 1));
    int XY = hexToInt(instructionRegister.substr(2, 2));

    // Execute
    try {
        switch(opCode) {
            case 1: // LOAD from memory
                registers.setRegister(R, memory.getCellAddress(XY));
                break;

            case 2: // LOAD immediate
                registers.setRegister(R, instructionRegister.substr(2, 2));
                break;

            case 3: // STORE
                if (XY == 0) {
                    cout << "Output: " << registers.getRegister(R) << endl;
                } else {
                    memory.setCellAddress(XY, registers.getRegister(R));
                }
                break;

            case 4: // MOVE
                registers.setRegister(Y, registers.getRegister(R));
                break;

            case 5: { // ADD
                int val1 = hexToInt(registers.getRegister(X));
                int val2 = hexToInt(registers.getRegister(Y));
                registers.setRegister(R, intToHex((val1 + val2) & 0xFF));
                break;
            }

            case 0xB: // JUMP if register R equals register 0
                if(registers.getRegister(R) == registers.getRegister(0)) {
                    programCounter = XY;
                }
                break;

            case 0xC: // HALT
                halted = true;
                break;

            default:
                throw runtime_error("Invalid opcode: " + instructionRegister.substr(0, 1));
        }
    } catch(const exception& e) {
        throw runtime_error("Execution error: " + string(e.what()));
    }
}

void Cpu::displayState() {
    cout << "Program Counter: " << hex << uppercase << programCounter << endl;
    cout << "Instruction Register: " << instructionRegister << endl;
    registers.displayRegisters();
}

Register& Cpu::getRegisters() {
    return registers;
}
