#include <iostream>
using namespace std ;
#include "Register.h"
Register :: Register() {
    Register_Container[0] = 0 ;
}
Register ::Register(long address, long value) {
    Register_Container[address] = value ;
}
void Register :: Set_Value(long address ,long value) {
  Register_Container[address] = value ;
}
long Register :: Get_Value(long address) {
    return Register_Container[address] ;
}
