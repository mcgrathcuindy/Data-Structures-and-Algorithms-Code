/*
Christopher McGrath
HW10 Midichlorians problem
12/6/19
*/
#include <stdio.h>
#include <stdlib.h>

// Swaps the integers pointed to by a and b.
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int A[], int n)
{
    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-1; j++)
        {
            if(A[j] > A[j+1])
                swap(&A[j], &A[j+1]);
        }
    }
}


int main(void)
{
    int N = 0, i = 0, flag = 0;
    FILE *fin = fopen("in.txt", "r");
    fscanf(fin, "%d", &N);
    int arrayVaccineStrength[N];
    int arrayPatientsMidichlorians[N];
    
    
    for(i = 0; i < N; ++i)
        fscanf(fin, "%d", &arrayVaccineStrength[i]);
    for(i = 0; i < N; ++i)
        fscanf(fin, "%d", &arrayPatientsMidichlorians[i]);
    
    bubbleSort(arrayVaccineStrength, N);
    bubbleSort(arrayPatientsMidichlorians, N);
    
    for(i = 0; i < N; i++)
    {
        if(arrayVaccineStrength[i] > arrayPatientsMidichlorians[i])
            flag++;
    }
    if(flag == N-1)
        puts("Yes");
    else
        puts("No");
        
    fclose(fin);
    return 0;
}