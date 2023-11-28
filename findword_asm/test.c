//#define _CRT_SECURE_NO_WARNINGS //sdl 검사 off
//#include <stdio.h>
//#include <string.h>
//
//int fileAcc(char* p, int flag);
//int main(void) {
//    char word[20];
//    fileAcc(NULL, 0);
//    //printf("\nfind word :");
//    //scanf("%s", word);
//    //txtfile(word, 1);
//    return 0;
//}
//int fileAcc(char* p, int flag) {
//    char *cmd[] = {"MOV","INC","ADD","SUB","CMP","JBE","\n"};
//    char *pcmd[] = {"SEGMENT","ASSUME","ENDS","END","DW","\n"};
//    char* seg[] = {"CS","DS","\n"};
//    char* R16[] = {"AX","BX","CX","DX","\n"};
//    char* R8[] = {"AL","AH","BL","BH","CL","CH","DL","DH","\n"};
//    char delimit[] = ".,\t\n :";
//    int chcnt = 0, numcnt = 0, blankcnt = 0, wordcnt = 0, linecnt = 0;
//    int order = 0;
//    char buffer[1000], * cutp;
//    char wdlist[200][20] = { NULL };
//    char wdtemp[20] = { NULL };
//    int temp = 0, labFlag = 0;
//    FILE* fpR = fopen("prog3.asm", "r");
//    if (fpR == NULL) {
//        printf("open error");
//        return 0;
//    }
//    while (fgets(buffer, sizeof(buffer), fpR) != NULL) {
//        if (flag == 0) printf("%s", buffer);
//        cutp = strtok(buffer, delimit);
//
//        while (cutp != NULL) {
//            order++;
//            if (flag == 1 && strcmp(cutp, p) == 0) printf("(%d,%d)\n", linecnt+1, order);
//            blankcnt++;
//            wordcnt++;
//            if (flag == 1) {
//                for (int k = 0; k<strlen(cutp); k++) {
//                    if(cutp[k]==',' || cutp[k]=='.' || cutp[k]==' ') {}
//                    else wdlist[wordcnt - 1][k] = cutp[k];
//                }
//            }
//            while (cmd[temp] != "\n")
//            {   
//                if (strcmp(cmd[temp], cutp) == 0) labFlag--;
//                labFlag++;
//                temp++;
//            }
//            temp = 0;
//            while (pcmd[temp] != "\n" &&labFlag>=6)
//            {
//                if (strcmp(pcmd[temp], cutp) == 0) labFlag--;
//                labFlag++;
//                temp++;
//            }
//            temp = 0;
//            while (seg[temp] != "\n" && labFlag >= 11)
//            {
//                if (strcmp(seg[temp], cutp) == 0) labFlag--;
//                labFlag++;
//                temp++;
//            }
//            temp = 0;
//            while (R16[temp] !="\n" && labFlag >= 13)
//            {
//                if (strcmp(R16[temp], cutp) == 0) labFlag--;
//                labFlag++;
//                temp++;
//            }
//            temp = 0;
//            while (R8[temp] != "\n" && labFlag >= 17)
//            {
//                if (strcmp(R8[temp], cutp) == 0) labFlag--;
//                labFlag++;
//                temp++;
//            }
//            if (labFlag < 6) {
//                printf("cmd ");
//            }
//            else if (labFlag < 11) {
//                printf("pcmd ");
//            }
//            else if (labFlag < 13) {
//                printf("seg ");
//            }
//            else if (labFlag < 17) {
//                printf("R16 ");
//            }
//            else if (labFlag < 25) {
//                printf("R8 ");
//            }
//            else printf("label ");
//            chcnt += strlen(cutp);
//            for (int k = 0; k < strlen(cutp); k++) {
//                if (isdigit(cutp[k])) numcnt++;
//            }
//            cutp = strtok(NULL, delimit);
//            temp = 0;
//            labFlag = 0;
//        }
//        printf("\n");
//        blankcnt++;
//        linecnt++;
//        order = 0;
//    }
//    fclose(fpR);
//    if (flag == 1) {
//        for (int temp = 0; temp < wordcnt-1; temp++) {
//            for (int i = temp+1; i < wordcnt; i++) {
//                if (strcmp(wdlist[temp], wdlist[i])>0) {
//                    strcpy(wdtemp, wdlist[temp]);
//                    strcpy(wdlist[temp], wdlist[i]);
//                    strcpy(wdlist[i], wdtemp);
//                }
//            }
//        }
//        for (int p = 0; p < wordcnt; p++) {
//            for (int k = 0; wdlist[p][k] != NULL; k++) printf("%c", wdlist[p][k]);
//            printf("\n");
//        }
//        int low = 0;
//        int high = wordcnt;
//        int temp = high / 2;
//        for (temp;;temp=(low+high)/2) {
//            if (strcmp(p, wdlist[temp]) > 0) {
//                low = temp;
//            }
//            else if (strcmp(p, wdlist[temp]) < 0) {
//                high = temp;
//            }
//            else if (strcmp(p, wdlist[temp]) == 0) {
//                break;
//            }
//        }
//        for (low = temp; strcmp(wdlist[low], wdlist[low - 1]) == 0; low--) printf("--\n");
//        for (low; strcmp(p, wdlist[low]) == 0; low++) printf("\n%d번째", low+1);
//    }
//    blankcnt -= linecnt;
//    if (flag == 0) printf("\nword :%d, line : %d, char : %d, blank : %d, num : %d", wordcnt, linecnt, chcnt, blankcnt - 1, numcnt);
//    return 0;
//}