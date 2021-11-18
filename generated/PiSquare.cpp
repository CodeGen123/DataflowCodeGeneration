#include <stdio.h>
#include <stdlib.h>
#define ZERO 0
int mainLoop(){
    int DiscreteClock_output = 1;
    float Const_output = 6.0;
    static double Ramp_output = 1 - 1;
    double MultiplyDivide_output = 1;
    static double Accumulator_output = 0;
    Ramp_output += 1;
    MultiplyDivide_output = MultiplyDivide_output * Const_output / Ramp_output / Ramp_output;
    Accumulator_output += MultiplyDivide_output;
    printf("%lf\n",Accumulator_output);
    return 0;
}
#define LOOP_COUNT 101
int main(){
    int i;
    for(i = 0;i<=LOOP_COUNT;i++){
        mainLoop();
    }
    return 0;
}
