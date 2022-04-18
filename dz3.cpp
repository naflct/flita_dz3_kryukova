#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main() 
{
    setlocale(LC_ALL, "Russian");
    int n, i, j, count_v, count_r, c, u;
    int A[101][101];
    count_v = 0;
    count_r = 0;
    c = 0;

    FILE* graph;
    graph = fopen("graph.txt", "r");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf(graph, "%d", &A[i][j]);
        }
    }
    fclose(graph);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] != 0 && i != j) {
                count_r++;
            }

        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] != 0 && A[j][i] != 0 && i < j) {
                count_r--;
            }
        }
    }
    printf("Количество рёбер: %d", count_r);

    for (i = 0; i < n; i++) 
    {
        c = 0;
        for (j = 0; j < n; j++) 
        {
            if (A[i][j] != 0) 
                c = 1;
            if (A[j][i] != 0)
                c = 1;
        }

        if (c != 0) 
            count_v++;
    }
    printf("\nКоличество вершин: %d", count_v);

    u = (count_v - 1) * (count_v - 2) / 2;
    if (count_r > u)
        printf("\n%d > %d\nГраф связный", count_r, u);
    else 
        printf("\n%d < %d\nГраф не связный", count_r, u);
}
