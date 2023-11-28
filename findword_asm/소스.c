/*#define _CRT_SECURE_NO_WARNINGS //sdl 검사 off
#include <stdio.h>
#include <string.h>

int txtfile(char *p, int flag);
int main(void) {
    char word[20];
    txtfile(NULL, 0);
    printf("\nfind word :");
    scanf("%s", word);
    printf("\n%s",word);
    txtfile(word, 1);
    return 0;
}
int txtfile(char *p, int flag) {
    int chcnt = 0, numcnt = 0, blankcnt = 0, wordcnt = 0, linecnt = 0;
    int order = 0;
    char buffer[1000], * cutp;
    FILE* fpR = fopen("sub.txt", "r");
    if (fpR == NULL) {
        printf("open error");
        return 0;
    }
    while (fscanf(fpR, "%[^\n] ", buffer) != EOF) {
        if(flag==0) printf("%s\n", buffer);
        cutp = strtok(buffer, " ");
        while (cutp != NULL) {
            order++;
            if(flag==1 && strcmp(cutp,p)==0) printf("(%d,%d)\n", linecnt+1,order);
            blankcnt++;
            wordcnt++;
            chcnt += strlen(cutp);
            for (int k = 0; k < strlen(cutp); k++) {
                if (isdigit(cutp[k])) numcnt++;
            }
            cutp = strtok(NULL, " ");
        }
        blankcnt++;
        linecnt++;
        order = 0;
    }
    blankcnt -= linecnt;
    if (flag == 0) printf("word :%d, line : %d, char : %d, blank : %d, num : %d", wordcnt, linecnt, chcnt, blankcnt - 1, numcnt);
    fclose(fpR);
}
*/
// 단어 문자 라인 공백 숫자