#include <stdio.h>

#define SIGN(X) (X > 0 ? 1 : -1)
#define ABS(X) (X > 0 ? X : -X)

int pow(int a,int n)
{
	int res;

	res = 1;

	while(n)
	{
		if(n % 2 == 1)
		{
			res *= a;
		}
		n = n>>1;
		a = a*a;
	}
}

int LargeIntegersMultiplication(int X,int Y,int n)
{
	int x,y;
	int sign;
	int XL,XR;
	int YL,YR;
	int XLYL,XRYR;
	int XLYRXRYL;
	sign = SIGN(X)*SIGN(Y);
	x = ABS(X);
	y = ABS(Y);

	if(0 == x || 0 == y) return 0;

	if(1 == n)
	{
		return x*y;
	}else
	{
		XL = x/pow(10,n/2);
		XR = x - XL*pow(10,n/2);
		YL = y/pow(10,n/2);
		YR = y - YL*pow(10,n/2);

		XLYL = LargeIntegersMultiplication(XL,YL,n/2);
		XRYR = LargeIntegersMultiplication(XR,YR,n-n/2);
		XLYRXRYL = (XL+XR)*(YL+YR) - LargeIntegersMultiplication(XL,YL,n/2) - LargeIntegersMultiplication(XR,YR,n-n/2);
		return sign*(XLYL*pow(10,n)+XLYRXRYL*pow(10,n/2)+XR*YR);
	}
}
int main()
{
	int X,Y,n;

	while(scanf("%d %d %d",&X,&Y,&n) != EOF && X && Y && n)
	{
		printf("The result is %d\n",LargeIntegersMultiplication(X,Y,n));
	}
	return 0;
}
