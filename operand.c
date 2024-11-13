// Operand error 
#include<stdio.h>
#include<stdbool.h>

typedef struct {
    char opcode[10];
    int operand1;
    int operand2;

}Instruction;

bool hasOperandError(Instruction inst){
    return inst.operand1<0 || inst.operand2<0;
}

void raiseError(Instruction inst){
    printf("Operand error for opcode %s and for the operands %d %d : \n",inst.opcode,inst.operand1,inst.operand2);
}

void checkOperandError(Instruction job[],int jobSize){
    for(int i=0;i<jobSize;i++){
    if(hasOperandError(job[i])){
        raiseError(job[i]);
    }
    }
}
int main(){
    Instruction job[] = {
        {"ADD", 10, 20},
        {"SUB", -5, 15},      // Operand error
        {"MOV", 30, 40},
        {"MUL", 10, -1},      // Operand error
        {"DIV", 25, 5}
    };
    printf("Checking for oprand error : ");
    checkOperandError(job,5);
    return 0;