#include <stdio.h>

#define MAX 105
#define INF 0x7fffffff

int MatrixChainMultiplication(int *num,int n)
{
	int dp[MAX][MAX];
	int i,j,k,d;
	
	for(i = 1 ; i <= n; i++)
	{
		dp[i][i] = 0;
	}

	for(d = 1; d <= n-1; d++)
	{
		for(i = 1 ; i <= n-d; i++)
		{
			j = i + d;
			dp[i][j] = INF;
			for(k = i+1; k <= j; k++)
			{
				if(dp[i][j] > dp[i][k-1]+dp[k][j] + num[i]*num[k]*num[j+1])
				{
					dp[i][j] = dp[i][k-1]+dp[k][j] + num[i]*num[k]*num[j+1];
				}
			}
		}
	}

	return dp[1][n];

}

int main()
{
	int num[MAX];
	int n;
	int i;

	while(scanf("%d",&n) != EOF && n)
	{
		for(i = 1 ; i <= n+1; i++)
		{
			scanf("%d",&num[i]);
		}

		printf("The num of multiplication is %d\n",MatrixChainMultiplication(num,n));
	}
	return 0;
}
