#include <stdio.h>
#include <stdlib.h>
#define ZERO 0
int mainLoop(){
    int DiscreteClock_output = 1;
    static int Ramp_output = 0 - 1;
    Ramp_output += 1;
    printf("%d\n",Ramp_output);
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
