//Write a pseudocode for a divide-and-conquer algorithm for finding the
//position of the largest element in an array of n numbers.
#include <stdio.h>
#define MAX 105

int MaxIndex(int *num,int l,int r)
{
	int a,b;
	if(l == r)
	{
		return l;
	}else
	{
		a = MaxIndex(num,l,(l+r)/2);
		b = MaxIndex(num,(l+r)/2+1,r);
		return num[a] >= num[b] ? a : b;
	}
}
int main()
{
	int n;
	int num[MAX];
	int i;
	while(scanf("%d",&n) != EOF && n > 0)
	{
		for(i = 0 ; i < n; i++)
		{
			scanf("%d",&num[i]);
		}
		printf("Max Index is %d\n",MaxIndex(num,0,n-1));
	}
	return 0;
}
