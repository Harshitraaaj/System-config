/* #include <stdio.h>
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
#include <stdio.h>
int max_of_four(int a, int b, int c, int d)
 {
  
    int temp,max;
    int array[4]={a,b,c,d};
    for(int i=0;i<4;i++)
    {
        if(array[i]>array[i+1])
        {
            temp=array[i+1];
            array[i+1]=array[i];
            array[i]=temp;
            
        }
        max=array[i];
    }
    return max;
 }
 


int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}