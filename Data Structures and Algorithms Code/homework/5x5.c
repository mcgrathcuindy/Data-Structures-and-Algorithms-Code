#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int inefficient_find_max_number_of_one(int r, int c, int a[][c]){
    int i = 0, j = 0,oneCount = 0,maxNum = 0;
    
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if(a[i][j] == 1)
                oneCount++;
        }
        if(oneCount > maxNum){
                maxNum = oneCount;
                oneCount = 0;
        } else  oneCount = 0;
    }
    return maxNum;
}

int efficient_find_max_number_of_one(int r, int c, int a[][c]){
    int i = 0,j = 0, oneCount = 0, maxNum = 0,k = 0;
    
    for(i = 0; i < r; i++){
        for(j = k; j < c; j++){
            if(a[i][j]==1)
                oneCount++;
            else {
                k = j;
                break;
            }
        }
        if((oneCount > maxNum)&&(oneCount <= c))
            maxNum = oneCount;
    }
    return maxNum;
}

    int main( )
{
    int a[5][5] = {
                        {1,0,0,0,0},
                        {0,0,0,0,0},
                        {1,1,1,0,0},
                        {1,1,0,0,0},
                        {1,1,1,1,1},
                        
                        } ;
    
    int r=5, c=5, i, result;
    clock_t time;
    double cpu_time_used;
    
    time = clock();
    for(i=0;i<100000000;i++)
    result=inefficient_find_max_number_of_one(r, c, a);
    time = clock() - time;
    cpu_time_used = ((double)time)/CLOCKS_PER_SEC;
    printf("It takes %lf seconds to use \"inefficient_find\" - Max no. of 1 for %d by %d matrix is %d \n\n",cpu_time_used, r,c,result);
    
    time = clock();
    for(i=0;i<100000000;i++)
    result=efficient_find_max_number_of_one(r, c, a);
    time = clock() - time;
    cpu_time_used = ((double)time)/CLOCKS_PER_SEC;
    printf("It takes %lf seconds to use \"efficient_find\"    - Max no. of 1 for %d by %d matrix is %d \n",cpu_time_used,r,c, result);
    
    return 0;
}