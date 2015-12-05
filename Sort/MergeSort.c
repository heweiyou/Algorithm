#include <stdio.h>
#define MAX 105

void Merge(int* num,int* a,int aLen,int* b,int bLen)
{
	int len,i,j;
	len = 0;
	i = 0;
	j = 0;
	while(i < aLen && j < bLen)
	{
		if(a[i] <= b[j])
		{
			num[len++] = a[i++];
		}else
		{
			num[len++] = b[j++];
		}
	}

	while(i < aLen) num[len++] = a[i++];
	while(j < bLen) num[len++] = b[j++];
}
void MergeSort(int* num,int n)
{
	int a[MAX];
	int b[MAX];
	int i,aLen,bLen;
	if(n == 0 || n == 1) return;
	aLen = 0;
	bLen = 0;
	for(i = 0 ; i < n/2; i++ )
	{
		a[aLen++] = num[i];
	}

	for(i = n/2; i < n; i++)
	{
		b[bLen++] = num[i];
	}
	MergeSort(a,aLen);
	MergeSort(b,bLen);
	Merge(num,a,aLen,b,bLen);
}

int main()
{
	int n;
	int num[MAX];
	int i;

	while(scanf("%d",&n) != EOF && n)
	{
		for(i = 0 ; i < n; i++)
		{
			scanf("%d",&num[i]);
		}

		MergeSort(num,n);
		printf("Sorted: ");
		for(i = 0 ; i < n; i++)
		{
			printf("%d ",num[i]);
		}
		printf("\n");
	}
	return 0;
}
