#include <stdio.h>
int pot(int n, int e);


int main()
{
	int t = 10;
	printf("%d %d", t, pot(t, 2));
	return 0;
}

int pot(int n, int e)
{
	int total;
	total = n;
	for (; e > 1; e--)
		total = total * n;
	return (total);
}
