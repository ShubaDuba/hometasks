#include <stdio.h>

int main()
{
	int x = 0;
	scanf("%d", &x);
	int square = x * x;
	int result = (square + x) * (square + 1);
	printf("%d", result);
	scanf("%*s");
	return 0;
}