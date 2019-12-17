#include <stdio.h> 
#include <stdlib.h>
#include <math.h>


void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) { 
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
        return; 
    } 
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod); 
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); 
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod); 
} 
int main() { 
    int n, moves;
    printf("Enter the # of disks you want to play with:");
    scanf("%d",&n);
    // Print out the # of moves required
    moves = pow(2,n)-1;
    printf("\nThe No of moves required is=%d \n",moves);
    // Initiate the recursion
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods 
    return 0; 
} 