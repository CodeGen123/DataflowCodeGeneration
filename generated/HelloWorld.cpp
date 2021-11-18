#include <stdio.h>
#include <stdlib.h>
#define ZERO 0
int mainLoop(){
    char* Const_output = "Hello world!";
    printf("%s\n",Const_output);
    return 0;
}
#define LOOP_COUNT 2
int main(){
    int i;
    for(i = 0;i<=LOOP_COUNT;i++){
        mainLoop();
    }
    return 0;
}
