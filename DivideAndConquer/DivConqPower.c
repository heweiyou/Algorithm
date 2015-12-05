//Write a pseudocode for a divide-and-conquer algorithm for the ex-
//ponentiation problem of computing an where a > 0 and n is a positive
//integer.
#include <stdio.h>
#define MAX 105

int DivConqPower(int a,int n)
{
	if(n == 0) return 1;
	if(n == 1) return a;
	if(n%2 == 0)
	{
		return DivConqPower(a,n/2)*DivConqPower(a,n/2);
	}else
	{
		return DivConqPower(a,n/2)*DivConqPower(a,n/2+1);
	}
}
int main()
{
	int a,n;

	while(scanf("%d %d",&a,&n) != EOF && n && a)
	{
		printf("The Result is %d\n",DivConqPower(a,n));
	}
}
