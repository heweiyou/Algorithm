#include <stdio.h>

#define MAX 105

void swap(int *a,int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void KthElement(int *num,int low,int high,int k)
{
	int i,j;
	int key;
	if(low < high)
	{
		i = low;
		key = num[low];
	
		for(j = low+1 ; j <= high; j++)
		{
			if(num[j] <= key)
			{
				i++;
				swap(&num[i],&num[j]);
			}
		}
		swap(&num[i],&num[low]);
		if(i-low+1 == k)
		{
			return ;
		}else if(i-low+1 < k)
		{
			KthElement(num,i+1,high,k-(i-low+1));		
		}else
		{
			KthElement(num,low,i-1,k);
		}
	}
}
int main()
{
	int num[MAX];
	int n,k;
	int i;

	while(scanf("%d %d",&n,&k) != EOF && n)
	{
		for(i = 1 ; i <= n; i++)
		{
			scanf("%d",&num[i]);		
		}
		
		KthElement(num,1,n,k);
		printf("The %dth Element is %d\n",k,num[k]);
	}
	return 0;
}
