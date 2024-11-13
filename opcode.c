// Opcode Error 
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

const char *validOpcodes[] = {"ADD","SUB","MULT","DIV","MOV"};
const int validOpcodeCount = 5;

bool isValidOpcode(char *opcode){
    for(int i=0 ; i<validOpcodeCount;i++){
        if(strcmp(opcode,validOpcodes[i])==0){
            return true;

        }
    }
    return false;
}

void raiseError(char *opcode){
    
        printf("opcode error for the opcode : %s\n", opcode);
    
}

void checkOpcodeErrors(char job[][10], int jobSize){
    for(int i=0 ; i<jobSize ; i++){
        if(!isValidOpcode(job[i])){
            raiseError(job[i]);
        }

    }
}
int main(){
char job[][10] = {
        "ADD",
        "MUL",
        "XYZ",  // Invalid opcode
        "MOV",
        "SUB"
    };

    printf("Checking for opcode error :\n");
    checkOpcodeErrors(job,5);
    return 0;