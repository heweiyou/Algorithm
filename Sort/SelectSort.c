#include <stdio.h>

#define MAX 105

void SelectSort(int *num,int n)
{
	int i,j,k;
	int tmp;
	for(i = 0 ; i < n; i++)
	{
		k = i;
		for(j = i+1 ; j < n; j++)
		{
			if(num[j] < num[k])
			{
				k = j;
			}
		}
		if(k != i)
		{
			tmp = num[k];
			num[k] = num[i];
			num[i] = tmp;
		}
	}
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

		SelectSort(num,n);

		for(i = 0 ; i < n; i++)
		{
			printf("%d ",num[i]);
		}
		printf("\n");
	}
	return 0;
}
