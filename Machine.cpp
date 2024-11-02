#include <bits/stdc++.h>
#include "Machine.h"
#include "Register.h"
#include "Memory.h"
using namespace std;

Machine :: Machine() {
    counter = -1;
}
void Machine :: open(string file_name) {
    ifstream f(file_name);
    if (!f.is_open()) {
        cout << "Error opening file: " << file_name << endl;
        return;
    }
    string line;
    vector <string> v(3);
    while(getline(f,line)){
        counter++;
        int indx = 0;
        int c = 0;
        for(int i = 0; i < line.length(); i++){
            if(line[i] == ' '){
                v[c] = line.substr(indx,i-indx);
                indx = i+1;
                c++;
            }
            else if(i == line.length()-1){
                v[c] = line.substr(indx,i-indx+1);
            }
        }

        string s = v[0]+v[1].back();
        M.write(counter, convert(s));
        counter++;
        M.write(counter, convert(v[2]));
    }
    f.close();
    work();

}
void Machine :: work() {
    for(step = 0; step < counter; step++){
      //  cout << step << "*\n";
         op = M.read(step)/16;
         long val = M.read(step);
         r = val-(op*16);
         step++;
         operations(op,r, M.read(step));
    }
}
long Machine :: convert(string s) {
    return stol(s, nullptr, 16);
}
long Machine:: get_counter(){
    return counter;
}
void Machine :: Load(long address_of_R , long address_of_XY ){
    long val = R.Get_Value(address_of_XY) ;
    R.Set_Value(address_of_R , val) ;
}
void  Machine :: Move(long address_of_R , long address_of_S){
    long val = R.Get_Value(address_of_R) ;
    R.Set_Value(address_of_S , val) ;
 //   Reg.Remove_Register(address_of_R) ;
}

void Machine :: JUMP(long address_of_R , long address_of_XY ) {
    long value_Of_R0 = R.Get_Value(0);
    long value_of_R = R.Get_Value(address_of_R);
    if (value_of_R == value_Of_R0) {
       step = M.read(step+2);
       step--;
    }
}
long Machine :: Screen() {
    return M.read(0);
}
void Machine :: operations(long Instruction , long Register_address , long XY) {
    switch (Instruction) {
        case 1:{
            Load(Register_address , XY) ;
            break;
        }
        case 2:{
            R.Set_Value(Register_address,XY);
            break;
        }
        case 3:{
            long l = R.Get_Value(Register_address);
            M.write(XY,l);
            break;
        }
        case 4 : {
            long s = XY/16;
            long t = XY-(s*16);
            Move(s , t) ;
            break;
        }
        case 5 : {
            long s=XY/16;
            long t=XY-(s*16);
            long num1=R.Get_Value(s);
            long num2=R.Get_Value(t);
            long sum=num1+num2;
            R.Set_Value(Register_address,sum);
        }
        case 11:{
            JUMP(Register_address, XY);
            break;
        }
        case 12:{
            return;
        }
    }
}


