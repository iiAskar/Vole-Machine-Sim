
#ifndef MEMORY_H
#define MEMORY_H
#include <bits/stdc++.h>

using namespace std;

class Memory {
private:
    string memory[256];
    int size = 256;
public:
    Memory();
    string getCellAddress(int address);
    void setCellAddress(int address, string value);
    void displayMemory();
    int getSize() const { return size; }
};


#endif //MEMORY_H
