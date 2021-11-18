#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define ZERO 0
void FuncState1(int in,int* out){
    int Scale_output = 0;
    Scale_output = in * 1;
    *out = Scale_output;
}
void FuncState2(int in,int* out){
    int Scale_output = 0;
    Scale_output = in * -1;
    *out = Scale_output;
}
void FuncModalModel(int in,int* out){
    static int ModalModel_nextstate;
    enum ModalModel_state{State1,State2};
    switch(ModalModel_nextstate){
    case State1:
        if(in%3 == 0){
            ModalModel_nextstate = State2;
        }
        FuncState1(in,out);
        break;
    case State2:
        if(in%2 == 0 ){
            ModalModel_nextstate = State1;
        }
        FuncState2(in,out);
        break;
    }
}
int mainLoop(){
    int DiscreteClock_output = 1;
    static int Ramp_output = 0 - 1;
    int ModalModel_out = 0;
    Ramp_output += 1;
    FuncModalModel(Ramp_output,&ModalModel_out);
    printf("%d\n",ModalModel_out);
    return 0;
}
#define LOOP_COUNT 11
int main(){
    int i;
    for(i = 0;i<=LOOP_COUNT;i++){
        mainLoop();
    }
    return 0;
}
