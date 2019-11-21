#include <stdio.h>
#include <stdlib.h> 
void MergeSort(int* arr, int s, int m, int e, int n) {
 
    int *temp = (int *)malloc(sizeof(int) * n);
    int i;
    int lIdx = s, rIdx = m + 1, sIdx = s;
 
    for (i = 0; i < n; i++)
        temp[i] = arr[i];
 
    while (lIdx < m + 1 && rIdx < e + 1) {
 
        if (temp[lIdx] < temp[rIdx]) {
            arr[sIdx++] = temp[lIdx++];
        }
        else {
            arr[sIdx++] = temp[rIdx++];
        }
    }
 
    if (lIdx == m + 1) {
        for (i = rIdx; i < e + 1; i++)
            arr[sIdx++] = temp[i];
    }
 
    if (rIdx == e + 1) {
        for (i = lIdx; i < m + 1; i++)
            arr[sIdx++] = temp[i];
    }
    
    free(temp);
}
 
void Merge(int* arr, int s, int e, int n) {
 
    int m = (s + e) / 2;
 
    if (s < e) {
        Merge(arr, s, m, n);
        Merge(arr, m+1, e, n);
        MergeSort(arr, s, m, e, n);
    }
}
 
int main() {
 
    int N, K;
    int i, tmp, sum = 0;
    int sensor[10001] = { 0 };
    int distance[10000] = { 0 };
 
    scanf("%d", &N);
    scanf("%d", &K);
 
    for (i = 0; i < N; i++) {
        scanf("%d", &sensor[i]);
    }
 
    Merge(sensor, 0, N - 1, N); // ���� ����
    for (i = 0; i < N-1; i++) 
        distance[i] = sensor[i + 1] - sensor[i]; // �� �� ������ �Ÿ�
    
    Merge(distance, 0, N - 2, N - 1); // �Ÿ� ����
    
    for (i = 0; i < N - K; i++) // K-1�� ��ŭ �Ÿ��� ���� �� �� ���� -> �Ÿ��� ���� �������� -1�̱� ����
        sum += distance[i];
 
    printf("%d\n", sum);
 
    return 0;
}

