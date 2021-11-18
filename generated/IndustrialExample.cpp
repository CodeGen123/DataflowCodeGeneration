#include <math.h>
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
struct Struct_g_jsf_one_app_info{
    int curValidCpuid;
    int initedCoreMask;
};
struct Struct_jobset_cfg{
    int thread_type;
    int thread_prio;
    int stack_size;
    int max_job_num;
    int min_pid;
    int max_pid;
};
struct Struct_m_jsf_init_cfg{
    int init_flag_mask;
    int max_jobset_num;
    int max_pipe_num;
    int run_level;
    int mem_va;
    int mem_len;
};
int coreId = 0xF;
int cpuid0 = 3L;
struct Struct_g_jsf_one_app_info g_jsf_one_app_info = {2L,0};
struct Struct_jobset_cfg jobset_cfg = {0,0,0,30,1,30};
struct Struct_m_jsf_init_cfg m_jsf_init_cfg = {0x1FFFF,0,0,0,0,0};
void FuncJsfCpuidApply(int trigger,int* cpuid){
    int Expression_output = 0;
    char* Expression2_output;
    int Expression3_output = 0;
    struct Struct_g_jsf_one_app_info Expression4_output;
    int Expression5_output = 0;
    int BooleanMultiplexor_output = 0;
    struct Struct_g_jsf_one_app_info RecordUpdater_output;
    Expression_output = g_jsf_one_app_info.curValidCpuid >= 30? true : false;
    if(Expression_output){
        Expression2_output = "[JsfCpuidApply] no available cpuid!";
        Expression5_output = 0xFFFFFFFF;
        if(Expression_output) BooleanMultiplexor_output = Expression5_output;
        else BooleanMultiplexor_output = ZERO;
        *cpuid = BooleanMultiplexor_output;
        printf("%s\n",Expression2_output);
    }
    else{
        Expression3_output = g_jsf_one_app_info.curValidCpuid + 1;
        Expression4_output = g_jsf_one_app_info;
        if(Expression_output) BooleanMultiplexor_output = ZERO;
        else BooleanMultiplexor_output = Expression3_output;
        *cpuid = BooleanMultiplexor_output;
        RecordUpdater_output = Expression4_output;
        RecordUpdater_output.curValidCpuid = Expression3_output;
        g_jsf_one_app_info = RecordUpdater_output;
    }
}
void FuncPrioritySC(int v,int offset,int* out){
    int Scale_output = 0;
    int AddSubtract_output = 0;
    Scale_output = v * 3;
    AddSubtract_output = AddSubtract_output + Scale_output - offset;
    *out = AddSubtract_output;
}
void FuncJsfCreateJobset(int cpu_id1,int core_mask1,struct Struct_jobset_cfg job_set_cfg,int* ret){
    int Expression_output = 0;
    struct Struct_g_jsf_one_app_info Expression17_output;
    int Expression18_output = 0;
    char* Expression2_output;
    int Expression3_output = 0;
    int Expression7_output = 0;
    struct Struct_g_jsf_one_app_info RecordUpdater4_output;
    int Const_output = 2;
    struct Struct_g_jsf_one_app_info Expression8_output;
    int Expression9_output = 0;
    static int Ramp_output = 0 - 5;
    int MultiplyDivide_output = 1;
    struct Struct_g_jsf_one_app_info RecordUpdater3_output;
    int PrioritySC_out = 0;
    struct Struct_g_jsf_one_app_info SetVariable3_output;
    int Expression10_output = 0;
    int BooleanMultiplexor2_output = 0;
    int BooleanMultiplexor_output = 0;
    Expression_output = (((m_jsf_init_cfg.init_flag_mask >> coreId) & 0x1) != 1)? true : false;
    if(Expression_output){
        Expression2_output = stringAdd(stringAdd(stringAdd("[JsfCreateJobset]init_flag_mask inv. init_flag_mask: ", intToString(m_jsf_init_cfg.init_flag_mask)), ", core_id: "), intToString(coreId));
        Expression7_output = -1;
        Expression17_output = g_jsf_one_app_info;
        Expression18_output = g_jsf_one_app_info.curValidCpuid - 1;
        printf("%s\n",Expression2_output);
        RecordUpdater4_output = Expression17_output;
        RecordUpdater4_output.curValidCpuid = Expression18_output;
        g_jsf_one_app_info = RecordUpdater4_output;
        if(Expression_output) BooleanMultiplexor_output = Expression7_output;
        else BooleanMultiplexor_output = ZERO;
        *ret = BooleanMultiplexor_output;
    }
    else{
        Expression3_output = (cpu_id1 >= 64 || core_mask1 == 0 || core_mask1 != (core_mask1 & g_jsf_one_app_info.initedCoreMask))? true : false;
        if(Expression3_output){
            Expression8_output = g_jsf_one_app_info;
            Expression9_output = g_jsf_one_app_info.curValidCpuid - 1;
            RecordUpdater3_output = Expression8_output;
            RecordUpdater3_output.curValidCpuid = Expression9_output;
            SetVariable3_output = RecordUpdater3_output;
            g_jsf_one_app_info = RecordUpdater3_output;
            Expression10_output = -1;
            if(Expression3_output) BooleanMultiplexor2_output = Expression10_output;
            else BooleanMultiplexor2_output = ZERO;
        }
        else{
            Ramp_output += 5;
            MultiplyDivide_output = MultiplyDivide_output * Ramp_output * Ramp_output / Const_output;
            FuncPrioritySC(MultiplyDivide_output,Const_output,&PrioritySC_out);
            if(Expression3_output) BooleanMultiplexor2_output = ZERO;
            else BooleanMultiplexor2_output = PrioritySC_out;
        }
        if(Expression_output) BooleanMultiplexor_output = ZERO;
        else BooleanMultiplexor_output = BooleanMultiplexor2_output;
        *ret = BooleanMultiplexor_output;
    }
}
void FuncufpSchGrpInit(int core_mask,int cpuid,int* ret){
    int Expression_output = 0;
    Expression_output = 0;
    *ret = Expression_output;
}
void FuncJsfDeployWg(int core_mask,long long* cpuid,long long* ret){
    int JsfCpuidApply_cpuid = 0;
    int Expression_output = 0;
    char* Expression2_output;
    int Expression7_output = 0;
    int Expression8_output = 0;
    struct Struct_jobset_cfg Expression9_output;
    int JsfCreateJobset_ret = 0;
    int Expression3_output = 0;
    int Expression10_output = 0;
    int Expression11_output = 0;
    char* Expression4_output;
    int ufpSchGrpInit_ret = 0;
    int BooleanMultiplexor2_output = 0;
    int Expression5_output = 0;
    int BooleanMultiplexor_output = 0;
    int Expression12_output = 0;
    char* Expression6_output;
    FuncJsfCpuidApply(core_mask,&JsfCpuidApply_cpuid);
    int Expression_in = JsfCpuidApply_cpuid;
    Expression_output = Expression_in == 0xFFFFFFFF? true : false;
    cpuid0 = JsfCpuidApply_cpuid;
    if(Expression_output){
        int Expression2_in = JsfCpuidApply_cpuid;
        Expression2_output = stringAdd("[JsfDeployWg]: JsfCpuidApply fail. ret= ", intToString(Expression2_in));
        printf("%s\n",Expression2_output);
        if(Expression_output) BooleanMultiplexor_output = JsfCpuidApply_cpuid;
        else BooleanMultiplexor_output = ZERO;
        *ret = BooleanMultiplexor_output;
    }
    else{
        Expression7_output = cpuid0;
        Expression8_output = core_mask;
        Expression9_output = jobset_cfg;
        FuncJsfCreateJobset(Expression7_output,Expression8_output,Expression9_output,&JsfCreateJobset_ret);
        int Expression3_in = JsfCreateJobset_ret;
        Expression3_output = Expression3_in != 0? true : false;
        if(Expression3_output){
            int Expression4_in = JsfCreateJobset_ret;
            Expression4_output = stringAdd("[JsfDeployWg]: JsfCreateJob fail. ret ", intToString(Expression4_in));
            printf("%s\n",Expression4_output);
            if(Expression3_output) BooleanMultiplexor2_output = JsfCreateJobset_ret;
            else BooleanMultiplexor2_output = ZERO;
        }
        else{
            Expression10_output = cpuid0;
            Expression11_output = core_mask;
            FuncufpSchGrpInit(Expression11_output,Expression10_output,&ufpSchGrpInit_ret);
            if(Expression3_output) BooleanMultiplexor2_output = ZERO;
            else BooleanMultiplexor2_output = ufpSchGrpInit_ret;
            int Expression5_in = ufpSchGrpInit_ret;
            Expression5_output = Expression5_in != 0? true : false;
            if(Expression5_output){
                int Expression6_in = ufpSchGrpInit_ret;
                Expression6_output = stringAdd("[JsfDeployWg]: ufpSchGrpInit fail. ret ", intToString(Expression6_in));
                printf("%s\n",Expression6_output);
            }
        }
        if(Expression_output) BooleanMultiplexor_output = ZERO;
        else BooleanMultiplexor_output = BooleanMultiplexor2_output;
        *ret = BooleanMultiplexor_output;
    }
    Expression12_output = cpuid0;
    *cpuid = Expression12_output;
}
int mainLoop(){
    int DiscreteClock_output = 1;
    int Expression_output = 0;
    long long JsfDeployWg_cpuid;
    long long JsfDeployWg_ret;
    Expression_output = 1;
    FuncJsfDeployWg(Expression_output,&JsfDeployWg_cpuid,&JsfDeployWg_ret);
    printf("%ld\n",JsfDeployWg_cpuid);
    printf("%ld\n",JsfDeployWg_ret);
    return 0;
}
#define LOOP_COUNT 6
int main(){
    int i;
    for(i = 0;i<=LOOP_COUNT;i++){
        mainLoop();
    }
    return 0;
}
