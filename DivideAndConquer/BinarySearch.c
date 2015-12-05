#include <stdio.h>

#define MAX 105

int BinarySearch(int *num,int n,int target)
{
	int l,r,mid;

	l = 0;
	r = n-1;

	while(l <= r)
	{
		mid = (l + r) / 2;
		if(num[mid] == target) return mid;
		else if(num[mid] < target) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}
int main()
{
	int num[MAX];
	int n,target;
	int i,index;

	while(scanf("%d %d",&n,&target) != EOF && n )
	{
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d",&num[i]);
		}
		
		index = BinarySearch(num,n,target);
		printf("Position is %d\n",index);
	}
	return 0;
}
