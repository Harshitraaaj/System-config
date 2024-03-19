#include<stdio.h> 
void towerOfHanoi(int n, char from_rod,char to_rod, char aux_rod)   
{   
    if (n == 1)   
    {   
        printf("Move disk %d from rod %c to rod %c\n" ,n,from_rod ,to_rod);   
        return;   
    } 
    // Push all values of n, from_rod, aux_rod, to_rod stack 
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);   
    // Pop all values of n, from_rod, aux_rod, to_rod stack 
    printf("Move disk %d from rod %c to rod %c\n" , n,from_rod,to_rod);   
     // Push all values of n, from_rod, aux_rod, to_rod stack 
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);   
     // Pop all values of n, from_rod, aux_rod, to_rod stack 
}   
   
// Driver code  
int main()   
{   
    int n ; 
    printf("Enter the no. of disks : ");
    scanf("%d",&n);  
    printf("\nThe sequence of moves involved in the tower of hanoi are \n");
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods   
    return 0;   
}   

/*#include <stdio.h>
#include <math.h>
void tower(int,int,int,int);
void tower(int n,int source,int temp,int destination)
{
	if(n==0)
	return;
	tower(n-1,source,destination,temp);
	printf("\n move disk %d from %c to %c",n,source,destination);
	tower(n-1,temp,source,destination);
}
void main()
{
	int n;
	printf("\n Enter the number of disks:\n\n");
	scanf("%d",&n);
	printf("\n The sequence of moves involved in the tower of hanoi are \n");
	tower(n,'A','B','C');
	printf("\n\n Total no. of moves are %d\n",(int)pow(2,n)-1);
}
*/