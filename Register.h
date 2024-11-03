
#ifndef REGISTER_H
#define REGISTER_H
#include <bits/stdc++.h>

using namespace std;

class Register {
private:
    string registers[16];  // 16 registers (0-F in hex)
    int size = 16;
public:
    Register();
    string getRegister(int reg);
    void setRegister(int reg, string value);
    void displayRegisters();
};


#endif //REGISTER_H
