//Let A[0..n − 1] be an array of n distinct real numbers. A pair (A[i], A[j])
//is said to be an inversion if these numbers are out of order, i.e., i < j
//but A[i] > A[j]. Design an O(n log n) algorithm for counting the number
//of inversions.

#include <stdio.h>
#define MAX 105

int Merge(int* num,int* a,int aLen,int* b,int bLen)
{
	int len,i,j;
	int cnt;
	len = 0;
	i = 0;
	j = 0;
	cnt = 0;
	while(i < aLen && j < bLen)
	{
		if(a[i] <= b[j])
		{
			num[len++] = a[i++];
		}else
		{
			num[len++] = b[j++];
			cnt = cnt + aLen - i;
		}
	}

	while(i < aLen) num[len++] = a[i++];
	while(j < bLen) num[len++] = b[j++];
	return cnt;
}
int MergeSort(int* num,int n)
{
	int a[MAX];
	int b[MAX];
	int i,aLen,bLen;
	int leftCnt,midCnt,rightCnt;
	if(n == 0 || n == 1) return 0;
	aLen = 0;
	bLen = 0;
	leftCnt = 0;
	midCnt = 0;
	rightCnt = 0;

	for(i = 0 ; i < n/2; i++ )
	{
		a[aLen++] = num[i];
	}

	for(i = n/2; i < n; i++)
	{
		b[bLen++] = num[i];
	}
	leftCnt = MergeSort(a,aLen);
	rightCnt = MergeSort(b,bLen);
	midCnt = Merge(num,a,aLen,b,bLen);
	return leftCnt + rightCnt + midCnt;
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

		printf("Inversion Number is %d\n",MergeSort(num,n));
		
	}
	return 0;
}
