#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define datalength 10000000
void merge(int arr[], int low, int mid, int high);
void mergesort(int arr[], int low, int high);
void printArray(int arr[], int size);
int main() {
    double start, end;
    srand(time(NULL));
    int arr[datalength];
    for (int i = 0; i < datalength; i++) arr[i] = rand() % 1000;
    int size = sizeof(arr) / sizeof(arr[0]);
    start = (double)clock() / CLOCKS_PER_SEC;
    mergesort(arr, 0, size - 1);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("time : %f", end - start);
    return 0;
}
void merge(int arr[], int low, int mid, int high) {
    int n = mid - low + 1;
    int m = high - mid;
    int left[n], right[m];
    for (int i = 0; i < n; i++) left[i] = arr[low + i];
    for (int j = 0; j < m; j++) right[j] = arr[mid + 1 + j];
    int a = 0, b = 0, c = low;

    while (a < n && b < m) {
        if (left[a] <= right[b]) {
            arr[c] = left[a];
            a++;
        }
        else {
            arr[c] = right[b];
            b++;
        }
        c++;
    }
    while (a < n) {
        arr[c] = left[a];
        a++;
        c++;
    }
    while (b < m) {
        arr[c] = right[b];
        b++;
        c++;
    }
}
void mergesort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
