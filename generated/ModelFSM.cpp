#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ZERO 0
char* intToString(int n){
    char* ret = (char*)malloc(12);
    sprintf(ret, "%d", n);
    return ret;
}
char* stringAdd(char* str1, char* str2){
    char* ret = (char*)malloc(strlen(str1)+strlen(str2)+1);
    strcpy(ret,str1);
    strcpy(ret+strlen(str1),str2);
    return ret;
}
char* stringCopy(char* str){
    char* ret = (char*)malloc(strlen(str)+1);
    strcpy(ret,str);
    return ret;
}
struct Struct_Thr{
    int High;
    int Low;
};
struct Struct_Thr Thr = {5,0};
int coolingRate = -1;
float heatOffThreshold = 22.0;
float heatOnThreshold = 18.0;
int heatingRate = 10;
void FuncFSMActor(int temperature,int* heat){
    static int FSMActor_nextstate;
    enum FSMActor_state{heating,cooling};
    switch(FSMActor_nextstate){
    case heating:
        if(temperature < heatOffThreshold){
            *heat = heatingRate;
            FSMActor_nextstate = heating;
        }
        else if(temperature >= heatOffThreshold){
            *heat = coolingRate;
            FSMActor_nextstate = cooling;
        }
        break;
    case cooling:
        if(temperature > heatOnThreshold){
            *heat = coolingRate;
            FSMActor_nextstate = cooling;
        }
        else if(temperature <= heatOnThreshold){
            *heat = heatingRate;
            FSMActor_nextstate = heating;
        }
        break;
    }
}
int mainLoop(){
    static int Ramp_output = 15 - 1;
    int FSMActor_heat = 0;
    int Expression_output = 0;
    char* StringConst_output = "heating:";
    char* StringConst2_output = "cooling:";
    char* Expression2_output;
    Ramp_output += 1;
    FuncFSMActor(Ramp_output,&FSMActor_heat);
    int Expression_in = FSMActor_heat;
    Expression_output = Expression_in > Thr.Low;
    if(Expression_output){
        char* Expression2_str = stringCopy(StringConst_output);
        int Expression2_val = FSMActor_heat;
        Expression2_output = stringAdd(Expression2_str, intToString(Expression2_val));
    }
    else{
        char* Expression2_str = stringCopy(StringConst2_output);
        int Expression2_val = FSMActor_heat;
        Expression2_output = stringAdd(Expression2_str, intToString(Expression2_val));
    }
    printf("%s\n",Expression2_output);
    return 0;
}
#define LOOP_COUNT 111
int main(){
    int i;
    for(i = 0;i<=LOOP_COUNT;i++){
        mainLoop();
    }
    return 0;
}
