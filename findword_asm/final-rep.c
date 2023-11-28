#define _CRT_SECURE_NO_WARNINGS //sdl 검사 off
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define ASMfile "prog.asm"
#define cp_ASMfile "prog3.asm"
#define MACRO_FIN "write.txt"
#define INS_txt "instruction.txt"
#define ins_MAX 30
#define REG_txt "register.txt"
#define reg_MAX 16
#define MACROCNT 5
#define SIZE 30

struct reg {
    char name[3];
    char bCode[4];
} reg[reg_MAX];
int regCnt = 0;

struct instruction {
    char name[6];
    char dType[2];
    char dest[2];
    char sour[2];
    char insLen[2];
    char xCode[3];
    char bCode[9];
    char etc[5];
} ins[ins_MAX];
int insCnt = 0;

struct symbol {
    char name[10];
    char dType[2];
    char data[5][9];
    int LCsave;
} sym[5];
int symCnt = 0;

struct sentence {
    char label[10];
    char instruction[6];
    char data[5][9];
} sen;
char *MACList[MACROCNT];

int init() {
    printf("start init.\n");
    printf("\ninstruction initialize.\n");
    FILE* fpins = fopen(INS_txt, "r");
    if (fpins == NULL) {
        printf("instruction file error");
        return 0;
    }
    while (!feof(fpins)) {
        fscanf(fpins, "%6s%2s%2s%2s%2s%3s%s\n",
            ins[insCnt].name, ins[insCnt].dType,
            ins[insCnt].dest, ins[insCnt].sour,
            ins[insCnt].insLen, ins[insCnt].xCode,
            ins[insCnt].bCode);
        printf("%s %s %s %s\n", ins[insCnt].name, ins[insCnt].dType, ins[insCnt].xCode, ins[insCnt].bCode);
        insCnt++;
    }
    fclose(fpins);

    printf("\nregister initialize.\n");
    FILE* fpreg = fopen(REG_txt, "r");
    if (fpreg == NULL) {
        printf("register file error");
        return 0;
    }
    while (!feof(fpreg)) {
        fscanf(fpreg, "%3s%s\n", reg[regCnt].name, reg[regCnt].bCode);
        printf("%s %s\n", reg[regCnt].name, reg[regCnt].bCode);
        regCnt++;
    }
    fclose(fpreg);
    printf("\n");
    return 0;
}
char line[100];

char* cutp;
int wflag = 0;
int sentenceProcess(char buffer[]) {
    int tempCnt = 0;
    strcpy(sen.label, "");
    strcpy(sen.instruction, "");
    for (int k = 0; k < 5; k++)strcpy(sen.data[k], "");
    strcpy(line, buffer);
    if(line[strlen(line) - 1] =='\n') line[strlen(line) - 1] = '\0'; //문장 끝 \n 제거f

    cutp = strtok(line, "\t :");
    if (line[0] == '\t') {         //label이 존재하지 않을 경우
    }
    else {                          //label이 존재
        strcpy(sen.label, cutp);
        cutp = strtok(NULL, ",\t ");
    }
    strcpy(sen.instruction, cutp);
    if (stricmp(sen.instruction, "assume") == 0) { wflag = 1; return -1; }
    if (stricmp(sen.instruction, "ENDS") == 0) wflag = 0;
    cutp = strtok(NULL, ",\t ");
    while (cutp != NULL) {
        if (tempCnt == 5) {
            printf("\nerror : to much data in this sentence\n");
            return 0;
        }
        strcpy(sen.data[tempCnt], cutp);
        tempCnt++;
        cutp = strtok(NULL, ",\t ");
    }

    return tempCnt; //return data cnt.
}
void macroProcess() {
    char buffer[51];
    int LineWordCnt = 0;
    FILE* fpM = fopen(ASMfile,"r");
    if (fpM == NULL) {
        printf("base ASM file error");
        return 0;
    }
    while (!feof(fpM)) {
        fgets(buffer, 51, fpM);
        sentenceProcess(buffer);
        LineWordCnt = 0;
    }
}
int passi() {
    char buffer[51];
    int LC = 0, select = 0;
    printf("start pass1\n");
    FILE* fpR = fopen(cp_ASMfile, "r");
    if (fpR == NULL) {
        printf("copy ASM file error.");
        return 0;
    }
    while (!feof(fpR)) {
        fgets(buffer, 51, fpR);
        int wordCnt = sentenceProcess(buffer);
        if (wordCnt == -1) continue;
        cutp = strtok(NULL, ",\t ");
        if (stricmp(sen.instruction, "dw")==0|| stricmp(sen.instruction, "db") == 0) {
            sym[symCnt].LCsave = LC;
            strcpy(sym[symCnt].name, sen.label);
            if (stricmp(sen.instruction, "dw") == 0) {
                strcpy(sym[symCnt].dType, "w");
            }
            else if(stricmp(sen.instruction, "db") == 0){
                strcpy(sym[symCnt].dType, "b");
            }
            //printf("\ndata type :%s, LC save :%.4x\n", sym[symCnt].dType, sym[symCnt].LCsave);
            for (int k = 0; k < wordCnt; k++) strcpy(sym[symCnt].data[k], sen.data[k]);
            symCnt++;
        }
        if (wflag == 1) {
            printf("LC:|%.4x|  %s %s ", LC,sen.label,sen.instruction);
            for (int k = 0; k < wordCnt; k++) printf("%s ", sen.data[k]);
            LC += atoi(ins[select].insLen);
        }
        printf("\n");

    }
    return 0;
}
int passii() {
    return 0;
}
int main(void) {
    //macroProcess();
    init();
    passi();
    return 0;
}