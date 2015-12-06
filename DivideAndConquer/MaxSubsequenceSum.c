#include <stdio.h>

#define MAX 105

int max(int a,int b,int c)
{
	int t;

	t = a > b ? a : b;
	t = t > c ? t : c;
	return t;
}

int MaxSubsequenceSum(int *num,int left,int right)
{
	int leftMax,rightMax;
	int mid,i;
	int leftBorderMax,leftBorderSum;
	int rightBorderMax,rightBorderSum;

	if(left == right)
	{
		if(num[left] > 0)
		{
			return num[left];
		}else
		{
			return 0;
		}
	}

	mid = (left + right) / 2;
	leftMax = MaxSubsequenceSum(num,left,mid);
	rightMax = MaxSubsequenceSum(num,mid+1,right);

	leftBorderMax = 0;
	leftBorderSum = 0;

	for(i = mid; i >= left; i--)
	{
		leftBorderSum += num[i];
		if(leftBorderSum > leftBorderMax)
		{
			leftBorderMax = leftBorderSum;
		}
	}

	rightBorderMax = 0;
	rightBorderSum = 0;

	for(i = mid+1; i <= right; i++)
	{
		rightBorderSum += num[i];

		if(rightBorderSum > rightBorderMax)
		{
			rightBorderMax = rightBorderSum;
		}
	}
	
	return max(leftMax,rightMax,leftBorderMax+rightBorderMax);
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

		printf("The sum of MaxSubSequence is %d\n",MaxSubsequenceSum(num,0,n-1));
	}
	return 0;
}
