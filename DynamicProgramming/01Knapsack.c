#include <stdio.h>
#include <string.h>
#define MAX 105

struct Goods
{
	int value;
	int weight;
};

void _01Knapsack(int dp[][MAX],int path[][MAX],struct Goods *g,int n,int cap)
{
	int i,w;

	memset(path,0,sizeof(path));
	for(i = 0 ; i <= n; i++)
	{
		dp[0][i] = 0;
		dp[i][0] = 0;
	}
	
	for(i = 1; i <= n; i++)
	{
		for(w = 1; w <= cap; w++)
		{
			if(w >= g[i].weight && dp[i-1][w] < dp[i-1][w-g[i].weight]+g[i].value)
			{
				dp[i][w] = dp[i-1][w-g[i].weight]+g[i].value;
				path[i][w] = i;
			}else
			{
				dp[i][w] = dp[i-1][w];
				path[i][w] = i-1;
			}
		}
	}
}

void printPath(int path[][MAX],struct Goods *g,int i,int w)
{

	if(i > 0)
	{
		if(path[i][w] == i)
		{
			printPath(path,g,i-1,w-g[i].weight);
			printf("%d ",path[i][w]);
		}else
		{
			printPath(path,g,i-1,w);
		}
	}
}
int main()
{
	int dp[MAX][MAX];
	int path[MAX][MAX];
	int n,capacity;
	struct Goods goods[MAX];
	int i;

	while(scanf("%d %d",&n,&capacity) != EOF && n && capacity)
	{
		for(i = 1; i <= n; i++)
		{
			scanf("%d %d",&goods[i].weight,&goods[i].value);
		}
		_01Knapsack(dp,path,goods,n,capacity);
		printf("The max value is:%d\n",dp[n][capacity]);
		printPath(path,goods,n,capacity);
		printf("\n");
	}
	return 0;
}
