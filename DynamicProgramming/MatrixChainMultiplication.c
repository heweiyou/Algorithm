#include <stdio.h>

#define MAX 105
#define INF 0x7fffffff

void printParentheses(int path[][MAX],int l,int r)
{
	int k;

	if(l == r)
	{
		printf("A%d",l);
		return ;
	}else if(r - l == 1)
	{
		printf("A%dA%d",l,r);
		return ;
	}else if(l > r)
	{
		return ;
	}
	
	k = path[l][r];
	if(l < k)
	{
		printf("(");
		printParentheses(path,l,k);
		printf(")");
	}else if(l == k)
	{
		printParentheses(path,l,k);
	}

	if(k+1 < r)
	{
		printf("(");
		printParentheses(path,k+1,r);
		printf(")");
	}else if(k+1 == r)
	{
		printParentheses(path,k+1,r);
	}
}

void MatrixChainMultiplication(int *num,int n,int dp[][MAX],int path[][MAX])
{
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
					path[i][j] = k-1;
				}
			}
		}
	}

}

int main()
{
	int num[MAX];
	int n;
	int i;
	int dp[MAX][MAX];
	int path[MAX][MAX];

	while(scanf("%d",&n) != EOF && n)
	{
		for(i = 1 ; i <= n+1; i++)
		{
			scanf("%d",&num[i]);
		}
		MatrixChainMultiplication(num,n,dp,path);
		printf("The num of multiplication is %d\n",dp[1][n]);
		printParentheses(path,1,n);
		printf("\n");
	}
	return 0;
}
