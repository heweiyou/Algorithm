#include <stdio.h>

#define MAX 105

void InsertSort(int *num,int n)
{
	int i,j;
	int tmp;
	for(i = 1 ; i < n; i++)
	{
		tmp = num[i];
		j = i-1;

		while(j >= 0 && num[j] > tmp)
		{
			num[j+1] = num[j];
			j--;
		}
		num[j+1] = tmp;
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

		InsertSort(num,n);

		for(i = 0 ; i < n; i++)
		{
			printf("%d ",num[i]);
		}
		printf("\n");
	}
	return 0;
}
