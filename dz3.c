#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define S 101
#define C 200

int main()
{
    int n, i, j, count_v, count_r, c, u;
    int A[S][S];
    char m[C];
    count_v = 0;
    count_r = 0;
    c = 0;

    FILE* graph;
    graph = fopen("graph.txt", "r");
    fscanf(graph, "%с", &m[0]);
    
    for (i = 0; (m[i] = fgetc(graph)) != '\n'; i++) {
        if (m[i] != ' ' && m[i] != '\t')
        n++;
    }
    printf("razmer %d\n", n);
    //scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) {
            fscanf(graph, "%d", &A[i][j]);
        }
    }
  
    fclose(graph);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
                n++;
        }
    }
  
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] != 0 && i != j)
                count_r++;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] != 0 && A[j][i] != 0 && i < j)
                count_r--;
        }
    }
    printf("kol-vo reber %d", count_r+1);

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
    printf("\nkol-vo vershin: %d", count_v);

    u = (count_v - 1) * (count_v - 2) / 2;
    if (count_r+1 > u)
        printf("\n%d > %d\nGraf svyasny", count_r+1, u);
    else
        printf("\n%d <= %d\nGraf ne svyasny", count_r+1, u);
}
