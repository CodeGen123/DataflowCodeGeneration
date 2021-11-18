#include <stdio.h>
#include <stdlib.h>
#define ZERO 0
int mainLoop(){
    int DiscreteClock_output = 1;
    static int Ramp_output = 0 - 1;
    int Const2_output = 1;
    int AddSubtract_output = 0;
    int MultiplyDivide2_output = 1;
    int Const_output = 2;
    int MultiplyDivide_output = 1;
    Ramp_output += 1;
    AddSubtract_output = AddSubtract_output + Const2_output + Ramp_output ;
    MultiplyDivide2_output = MultiplyDivide2_output * AddSubtract_output * Ramp_output ;
    MultiplyDivide_output = MultiplyDivide_output * MultiplyDivide2_output / Const_output;
    printf("%d\n",MultiplyDivide_output);
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
