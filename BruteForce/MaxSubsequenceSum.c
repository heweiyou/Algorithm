#include <stdio.h>

#define MAX 105 

int MaxSubsequenceSum(int *num,int n)
{
	int i,j,k;
	int sum,max;
/*	
	max = 0;
	for(i = 0 ; i < n ; i++)
	{

		for(j = i; j < n; j++)
		{
			sum = 0;
			for(k = i; k <= j; k++)
			{
				sum += num[k];
			}

			if(max < sum)
			{
				max = sum;
			}
		}
	}*/

	max = 0;
	for(i = 0 ; i < n; i++)
	{
		sum = 0;
		for(j = i ; j < n; j++)
		{
			sum += num[j];

			if(max < sum)
			{
				max = sum;
			}
		}
	}
	return max;
}

int main()
{
	int num[MAX];
	int n;
	int i;

	while(scanf("%d",&n) != EOF && n)
	{
		for(i = 0 ; i < n; i++)
		{
			scanf("%d",&num[i]);
		}

		printf("The sum of MaxSubsequenceSum is %d\n",MaxSubsequenceSum(num,n));
	}
	return 0;
}
