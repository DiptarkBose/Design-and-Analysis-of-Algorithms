#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, gcd=1, i;
	scanf("%d %d", &a, &b);
	for(i=2; i<=a; i++)
	{
		if(a%i==0 && b%i==0)
			gcd=i;
	}
	printf("%d\n", gcd);
}