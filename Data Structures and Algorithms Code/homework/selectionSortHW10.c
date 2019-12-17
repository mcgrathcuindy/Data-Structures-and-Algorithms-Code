/*
Christopher McGrath
HW 10 selection Sort problem
12/6/19
*/
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int A[], int n) 
{
    int i = 0, j, smallest;
    for(i = 0; i < n; i++)
    {
        smallest = i;
        for(j = i+1; j < n; j++)
        {
            if(A[j] < A[smallest])
                smallest = j;
        }
        swap(&A[i],&A[smallest]);
    }
}

int main(void)
{
    int N = 0, i = 0, flag = 0, j = 0, k = 0;
    FILE *fin = fopen("input.txt", "r");
    fscanf(fin, "%d", &N);
    int evenNums[N];
    int oddNums[N];

    for(i = 0; i < N; i++)
    {
        fscanf(fin, "%d", &flag);
        if(flag % 2 == 0)
        {
            evenNums[j] = flag;
            j++;
        }
        else
        {
            oddNums[k] = flag;
            k++;
        }
    }
    selectionSort(evenNums, j);
    selectionSort(oddNums, k);
    int sum = 0;
    for(i = 0; i < j; i++)
    {
        sum += evenNums[i];
        printf("%d ", evenNums[i]);
    }
    printf("%d ", sum);
    sum = 0;
    for(i = 0; i < k; i++)
    {
        sum += oddNums[i];
        printf("%d ", oddNums[i]);
    }
    printf("%d\n", sum);
    fclose(fin);
    return 0;
}