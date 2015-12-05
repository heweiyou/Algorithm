#include <stdio.h>

#define MAX 105

int Partition(int *num,int low,int high)
{
	int key;
	int i,j;

	key = num[low];
	i = low;
	j = high;

	while(i < j)
	{
		while(num[j] >= key && i < j) j--;
		num[i] = num[j];
		while(num[i] <= key && i < j) i++;
		num[j] = num[i];
	}
	num[i] = key;
	return i;
}

void QuickSort(int *num,int low,int high)
{
	int mid;

	if(low < high)
	{
		mid = Partition(num,low,high);
		QuickSort(num,low,mid-1);
		QuickSort(num,mid+1,high);
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

		QuickSort(num,0,n-1);

		for(i = 0 ; i < n ; i++)
		{
			printf("%d ",num[i]);
		}
		printf("\n");
	}
	return 0;
}
