#include <stdio.h>
#include <string.h>

#define MAX 105

int max(int a,int b)
{
	return a > b ? a : b;
}

int LongestCommonSubsequence(char *a,int aLen,char *b,int bLen)
{
	int i,j;
	int dp[MAX][MAX];

	for(i = 0 ; i < aLen; i++)
	{
		dp[i][0] = 0;
	}

	for(i = 0 ; i < bLen; i++)
	{
		dp[0][i] = 0;
	}

	for(i = 1; i <= aLen; i++)
	{
		for(j = 1; j <= bLen; j++)
		{
			if(a[i] == b[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	return dp[aLen][bLen];
}
int main()
{
	char a[MAX];
	char b[MAX];
	int aLen,bLen;
	int i;

	while(scanf("%s %s",a+1,b+1) != EOF)
	{
		aLen = strlen(a+1);
		bLen = strlen(b+1);
		printf("The number of Longest Common Subsequence is %d\n",LongestCommonSubsequence(a,aLen,b,bLen));
	}
	return 0;
}
