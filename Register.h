#include <iostream>
#include <map>
using namespace std ;
#ifndef VOLEMACHINELANGUAGESIMULATOR_REGISTER_H
#define VOLEMACHINELANGUAGESIMULATOR_REGISTER_H
    class Register {
    private:
        map < long , long > Register_Container ;
    public:
        Register() ;
        Register(long address , long value) ;
        void Set_Value (long address , long value) ;
        long Get_Value(long address) ;
    };


#endif //VOLEMACHINELANGUAGESIMULATOR_REGISTER_H
