#include <stdio.h>

#define MAX 105
#define INF 0x7fffffff

void Floyd(int map[][MAX],int dis[][MAX],int pre[][MAX],int n)
{
	int i,j,k;

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			dis[i][j] = map[i][j];
			pre[i][j] = -1;
		}
	}

	for(k = 1; k <= n; k++)
	{
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				if(dis[i][k]+dis[k][j] < dis[i][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
					pre[i][j] = k;
				}
				printf("%d\n",dis[i][j]);
			}
		}
	}
}
int main()
{
	int map[MAX][MAX];//单边距离(权值)
	int dis[MAX][MAX];//节点间最短距离(权值)
	int pre[MAX][MAX];//前驱节点,记录最短距离路径
	int n;
	int i,j;

	while(scanf("%d",&n) != EOF && n)
	{
		for(i = 1 ; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		
		Floyd(map,dis,pre,n);

		printf("The matrix of dis:\n");
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				printf("%d ",dis[i][j]);
			}
			printf("\n");
		}
	}


	return 0;
}
