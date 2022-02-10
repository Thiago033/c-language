
#include <stdio.h>
int main()
{
	int x = 0, *p1;

	p1 = &x;
	printf("%p", p1);
	return 0;
}
