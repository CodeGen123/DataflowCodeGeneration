#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define ZERO 0
int mainLoop(){
    static int Ramp_output = 0 - 1;
    int Scale_output = 0;
    Ramp_output += 1;
    Scale_output = Ramp_output * 2;
    printf("%d\n",Scale_output);
    return 0;
}
#define LOOP_COUNT 5
int main(){
    int i;
    for(i = 0;i<=LOOP_COUNT;i++){
        mainLoop();
    }
    return 0;
}
