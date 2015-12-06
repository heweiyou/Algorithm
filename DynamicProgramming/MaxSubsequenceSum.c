#include <stdio.h>

#define MAX 105

int MaxSubsequenceSum(int *num,int n)
{
	int sum,max;
	int i;

	sum = 0;
	max = 0;

	for(i = 0 ; i < n; i++)
	{
		if(sum < 0)
		{
			sum = num[i];
		}else
		{
			sum += num[i];
		}

		if(max < sum)
		{
			max = sum;
		}
	}
	return max;
}

int main()
{
	int num[MAX];
	int i;
	int n;

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
