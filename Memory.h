#ifndef MEMORY_H
#define MEMORY_H
#include<iostream>
#include<vector>
using namespace std;
class Memory{
private:
    long data [256];

public:
    long read(long address);
    void write(long address, long value);
};
#endif
