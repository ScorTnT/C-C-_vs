#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

#define MEMSIZE 128
#define BLOCKSIZE 4
#define LINESIZE 4
#define MEMBLSIZE 32
#define CACHESIZE 32
#define CACHELINE 8

char CACHE[CACHESIZE][8];
int LRU[CACHESIZE]={0};
int ex[CACHESIZE]={0};

int totalLoads = 0;
int totalStores = 0;
int loadHits = 0;
int loadMisses = 0;
int storeHits = 0;
int storeMisses = 0;
int totalCycles = 0;
void cacheS(int oper, char *ad,int a) {
    printf("%d,%s\n", oper, ad);
    int exFlag = 0, temp = 0, cacheFlag = 0;
    for (temp = 0; temp < CACHESIZE; temp++)LRU[temp]++;
    temp = 0;
    while (temp<CACHESIZE) {
        if (strcmp(CACHE[temp], ad)==0) {    //캐시에 존재할경우
            cacheFlag = 1;
            printf("hit %d %s\n", oper,CACHE[temp]);
            LRU[temp] = 1;      //lru에 방금 접근했다고 알림
            exFlag = 1;         //존재flag 1로 변경
            break;
        }
        temp++;
    }
    if (exFlag == 0) {  //no exist > miss > 캐시에 적재해야함
        printf("miss %d %s\n", oper, ad);
        temp = 0;
        while (temp < CACHESIZE) {  
            //printf("%d", cacheFlag);
            if (ex[temp] == 0) {    //빈 캐시 발견
                cacheFlag = 1;      //캐시flag 1로 변경
                for (int k = 0; k < 8; k++) {   //캐시에 주소 적재
                    CACHE[temp][k] = ad[k];
                    ex[temp] = 1;
                }
                printf("%s,%d\n", CACHE[temp],temp);
                break;
            }
            temp++;
        }
        //printf("load succeed %s,%d\n", CACHE[temp],temp);
        if (cacheFlag == 0) {   //빈 캐시가 없을 경우 > LRU로 캐시에 주소 적재
            int index = 0,k;
            k=LRU[0];
            for (temp = 1;temp<CACHESIZE; temp++) {
                if (LRU[temp] > k) {
                    index = temp;
                    k = LRU[temp];
                }
            }
            for (int p = 0; p < 8; p++) {   //LRU 수치가 높은 캐시에 주소 적재
                CACHE[k][p] = ad[p];
            }
            //printf("%d,%d\n", index, k);
        }
        //printf("%d", cacheFlag);
        if (oper == 108) {  // oper==load
            loadMisses++;
            printf("%d\n", a);
        }
        if (oper == 115) {  // oper==store
            storeMisses++;
            printf("%d\n", a);
        }
    }
    else {  //exist > hit
        if (oper == 108) {  // oper==load
            loadHits++;
        }
        if (oper == 115) {  // oper==store
            storeHits++;
        }
    }
}
char* split(char* str, int start, int length) {
    int strLength = strlen(str);
    if (start >= strLength || length <= 0) {
        return NULL;
    }
    int end = start + length;
    if (end > strLength) {
        end = strLength;
    }
    char* result = (char *)malloc(length + 1);
    strncpy(result, str + start, length);
    result[length] = '\0';
    return result;
}
int main() {
    int temp = 0;
    int flag = 0;
    FILE* traceFile = fopen("memory.txt", "r");
    if (traceFile == NULL) {
        printf("Error: Failed to open trace file.\n");
        return 0;
    }
    char buffer[50];
    int oper;
    while (!feof(traceFile)) {
        oper = fgetc(traceFile);
        fgets(buffer, sizeof(buffer), traceFile);
        strtok(buffer, "\n");
        strtok(buffer, " ");
        char* cutStr = split(buffer, 3, strlen(buffer) - 3);
        if (cutStr != NULL) {
            if (oper == 108) {  // oper==load
                totalLoads++;
            }
            if (oper == 115) {  // oper==store
                totalStores++;
            }
            cacheS(oper, cutStr,temp);
            free(cutStr);
        }
        totalCycles++;
        temp++;
    }
    printf("Total loads: %d\n", totalLoads);
    printf("Total stores: %d\n", totalStores);
    printf("Load hits: %d\n", loadHits);
    printf("Load misses: %d\n", loadMisses);
    printf("Store hits: %d\n", storeHits);
    printf("Store misses: %d\n", storeMisses);
    printf("Total cycles: %d\n", totalCycles);
    fclose(traceFile);
    //for (int k = 0; k < CACHESIZE;k++)printf("%s\n\n", CACHE[k]);
    //for (int k = 0; k < CACHESIZE; k++)printf("lru [%d]:%d\n",k,LRU[k]);
    return 0;
}