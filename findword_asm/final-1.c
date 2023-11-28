//#define _CRT_SECURE_NO_WARNINGS //sdl 검사 off
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define ASMfile "prog3.asm"
//#define MACRO_FIN "write.txt"
//#define INS_txt "instruction.txt"
//#define MACROCNT 5
//#define SYMBOLCNT 5
//#define SIZE 30
//
//int asmAcc();
//int prtASM();
//int txtAcc(char txtname[], FILE* fp);
//int ASMWordCnt = 0;
//char* MAClist[MACROCNT];    //1열에 매크로 이름 
//char* SYMlist[SYMBOLCNT][2];   //1열에 심볼 이름
//
//int main(void) {
//    asmAcc();
//    printf("\n");
//    getch();
//    prtASM();
//    return 0;
//}
//int asmAcc() {  //MACRO , SYMBOL process
//    char delimit[] = ".,\t\n :";
//    int maccnt = 0;
//    int symcnt = 0;
//    int symWordCnt = 0;
//    int chcnt = 0, numcnt = 0, blankcnt = 0, wordcnt = 0, linecnt = 0, order = 0;
//    char buffer1[1000], buffer2[1000], * cutp;
//    char* lineB = "";
//    int writeFlag = 0;
//    char macB[20] = { '\0' };
//    FILE* fpR = fopen(ASMfile, "r");
//    if (fpR == NULL) {
//        printf("open error");
//        return 0;
//    }
//    FILE* fpW = fopen(macB, "w");
//    while (fgets(buffer1, sizeof(buffer1), fpR) != NULL) {
//        strcpy(buffer2, buffer1);
//        lineB = strtok(buffer2, delimit);       //첫 번째 단어
//        lineB = strtok(NULL, delimit);          //두 번째 단어
//        if (lineB != NULL)if (writeFlag == 1 && strcmp(lineB, "ENDS") != 0) {
//            wordcnt--;
//            fputs(buffer1, fpW);
//        }
//        cutp = strtok(buffer1, delimit);        //순차적으로 들어오는 단어.
//
//        while (cutp != NULL) {
//            wordcnt++;
//            order++;
//            if (order == 1) {
//                for (int k = 0; k < strlen(cutp); k++) {
//                    macB[k] = cutp[k];
//                }
//            }
//            if (order == 2 && (strcmp(cutp, "DW") == 0 || strcmp(cutp, "DB") == 0)) {
//                SYMlist[symcnt][0] = (char*)malloc(sizeof(char));
//                strcpy(SYMlist[symcnt][0], macB);
//
//                SYMlist[symcnt][1] = (char*)malloc(sizeof(char));
//                char stringNum[10] = {'\0'};
//                sprintf(stringNum, "%d", wordcnt);
//                strcpy(SYMlist[symcnt][1], stringNum);
//                printf("Symbol[%d]:%s\n", symcnt, SYMlist[symcnt][0]);
//                symcnt++;
//            }
//            if (order == 2 && strcmp(cutp, "MACRO") == 0) {
//                wordcnt--;
//                
//                writeFlag = 1;
//                MAClist[maccnt] = (char*)malloc(sizeof(char));
//                strcpy(MAClist[maccnt], macB);
//                strcat(macB, ".txt");
//                fpW = fopen(macB, "w");
//                printf("MACRO[%d]:%s\n", maccnt, MAClist[maccnt]);
//                maccnt++;
//            }
//            if (order == 2 && strcmp(cutp, "ENDS") == 0 && writeFlag != 0) { writeFlag = 0; fclose(fpW); }
//            chcnt += strlen(cutp);
//            for (int k = 0; k < strlen(cutp); k++) {
//                if (isdigit(cutp[k])) numcnt++;
//            }
//            cutp = strtok(NULL, delimit);
//            blankcnt++;
//        }
//        blankcnt++;
//        linecnt++;
//        order = 0;
//        for (int k = 0; k < 20; k++) macB[k] = '\0';
//    }
//    fclose(fpR);
//    blankcnt -= linecnt;
//    printf("\nword :%d, line : %d, char : %d, blank : %d, num : %d", wordcnt, linecnt, chcnt, blankcnt - 1, numcnt);
//
//    return 0;
//}
//int prtASM() {
//    int wordCnt = 0;
//    char* seg[] = { "CS","DS","\0" };   //3
//    char* R16[] = { "AX","BX","CX","DX","\0" }; //5
//    char* R8[] = { "AL","AH","BL","BH","CL","CH","DL","DH","\0" };  //9
//    char* OP[] = { "MOV","ADD","SUB","AND","OR","INC","DEC","CMP","JMP","JA","JB","JE","JAE","JBE","DW","DB","\0" }; //17
//    char* instruction[] = { "ASSUME","SEGMENT","ENDS","END","\0" }; //5
//    char delimit[] = ".,\t\n :";
//    int maccnt = 0, order = 0, dwFlag = 0, MACnmFlag = 0, txtFlag = 0, labelTemp = 0, temp = 0, symflag = 0, symcnt = 0, numflag = 0;
//    char buffer1[1000], buffer2[1000], buffer3[1000], * cutp;
//    char* lineBa = "", lineBb[SIZE] = "";
//    FILE* fpR = fopen(ASMfile, "r");
//    if (fpR == NULL) {
//        printf("open error");
//        return 0;
//    }
//    FILE* Writefp = fopen(MACRO_FIN, "w");
//    while (fgets(buffer1, sizeof(buffer1), fpR) != NULL) {
//        strcpy(buffer2, buffer1);
//        strcpy(buffer3, buffer2);
//        lineBa = strtok(buffer2, delimit);   //줄의 첫 번째 단어 들고있음.
//
//
//        if (lineBa >= 'a') strcpy(lineBb, lineBa);
//        for (int k = 0; k < MACROCNT; k++) {
//            if (MAClist[k] != NULL) {
//                if (lineBa != NULL) if (strcmp(MAClist[k], lineBa) == 0) { MACnmFlag = 1; }
//            }
//        }
//        lineBa = strtok(NULL, delimit);     //줄의 두 번째 단어 들고있음.
//        if (lineBa != NULL) {
//            if (strcmp(lineBa, "MACRO") == 0) dwFlag = 1;
//        }
//        if (lineBa == NULL) txtFlag = 1;
//        if (txtFlag == 1 && lineBb != "\0") { txtAcc(lineBb, Writefp); }
//        if (!(MACnmFlag == 1 && dwFlag == 1) && txtFlag != 1) {
//            //printf("%s", buffer1); 
//            fputs(buffer1, Writefp);
//        }
//        if (lineBa != NULL)if (strcmp(lineBa, "ENDS") == 0) dwFlag = 0;
//        txtFlag = 0;
//        lineBa = '\0';
//        for (int k = 0; k < SIZE; k++) lineBb[k] = '\0';
//    }
//    fclose(fpR);
//    fclose(Writefp);
//    FILE* Final = fopen(MACRO_FIN, "r");
//    while (fgets(buffer3, sizeof(buffer3), Final) != NULL) {
//        printf("%s", buffer3);
//        cutp = strtok(buffer3, delimit);
//        while (cutp != NULL) {
//            wordCnt++;
//            //printf("%s\n", cutp);
//            int k = 0;
//            if (isdigit(cutp[0]) != 0) numflag = 1;
//            while (SYMlist[k][0] != NULL) {
//                if (strcmp(cutp, SYMlist[k][0]) == 0) {
//                    wordCnt--;
//                    symflag = 1;
//                    break;
//                }
//                k++;
//            }
//            while (seg[temp] != "\0") {
//                if (strcmp(cutp, seg[temp]) == 0)labelTemp--;
//                temp++;
//                labelTemp++;
//            }
//            temp = 0;
//            while (R16[temp] != "\0" && labelTemp >= 2) { // 2
//                if (strcmp(cutp, R16[temp]) == 0)labelTemp--;
//                temp++;
//                labelTemp++;
//            }
//            temp = 0;
//            while (R8[temp] != "\0" && labelTemp >= 6) { // 2+4
//                if (strcmp(cutp, R8[temp]) == 0)labelTemp--;
//                temp++;
//                labelTemp++;
//            }
//            temp = 0;
//            while (OP[temp] != "\0" && labelTemp >= 14) { //2+4+8
//                if (strcmp(cutp, OP[temp]) == 0)labelTemp--;
//                temp++;
//                labelTemp++;
//            }
//            temp = 0;
//            while (instruction[temp] != "\0" && labelTemp >= 30) { //2+4+8+16
//                if (strcmp(cutp, instruction[temp]) == 0)labelTemp--;
//                temp++;
//                labelTemp++;
//            }
//            temp = 0;
//            //printf("%d", labelTemp);
//            if (symflag == 1) {
//                printf("%s Symbol ",SYMlist[k][1]);
//            }
//            else if (numflag == 1) {
//                printf("%d Numb ", wordCnt);
//            }
//            else if (labelTemp < 2) {
//                printf("%d Seg ", wordCnt);
//            }
//            else if (labelTemp < 6) {
//                printf("%d Reg16 ", wordCnt);
//            }
//            else if (labelTemp < 14) {
//                printf("%d Reg08 ", wordCnt);
//            }
//            else if (labelTemp < 30) {
//                printf("%d Opcd ", wordCnt);
//            }
//            else if (labelTemp < 34) {
//                printf("%d Direc ", wordCnt);
//            }
//            else printf("%d label ", wordCnt);
//            cutp = strtok(NULL, delimit);
//            labelTemp = 0;
//            symflag = 0;
//            numflag = 0;
//        }
//        printf("\n");
//    }
//    return 0;
//}
//int txtAcc(char txtname[], FILE* fp) {
//    char* openTXTfile = strcat(txtname, ".txt");
//    char buffer1[1000];
//    FILE* fpR = fopen(openTXTfile, "r");
//    if (fpR == NULL) {
//        return 0;
//    }
//    while (fgets(buffer1, sizeof(buffer1), fpR) != NULL) {
//        //printf("%s", buffer1);
//        fputs(buffer1, fp);
//    }
//    return 0;
//}