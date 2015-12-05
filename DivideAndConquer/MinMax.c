//Write a pseudocode for a divide-and-conquer algorithm for finding val-
//ues of both the largest and smallest elements in an array of n numbers.
#include <stdio.h>
#define MAX 105

void MinMax(int* num,int l,int r,int* min,int* max)
{
	int minTemp,maxTemp;
	if(l == r)
	{
		*min = num[l];
		*max = num[r];
	}else if(r -l == 1)
	{
		if(num[l] <= num[r])
		{
			*min = num[l];
			*max = num[r];
		}else
		{
			*min = num[r];
			*max = num[l];
		}
	}else
	{
		MinMax(num,l,(l+r)/2,min,max);
		MinMax(num,(l+r)/2+1,r,&minTemp,&maxTemp);

		if(*min > minTemp) *min = minTemp;
		if(*max < maxTemp) *max = maxTemp;
	}
}
int main()
{
	int n;
	int num[MAX];
	int min,max;
	int i;

	while(scanf("%d",&n) != EOF && n > 0)
	{
		for(i = 0 ; i < n; i++)
		{
			scanf("%d",&num[i]);
		}

		MinMax(num,0,n-1,&min,&max);

		printf("Min number is %d,Max number is %d\n",min,max);
	}
	return 0;
}
