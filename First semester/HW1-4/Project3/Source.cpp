#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int a = 0;
	int b = 0;
	int quot = 0;
	setlocale(LC_ALL, "Russian");
	printf("Введите число a\n");
	scanf("%d", &a);
	printf("Введите число b\n");
	scanf("%d", &b);
	int sign = 0;
	
	if (a * b < 0)
		sign = -1;
	else
		sign = 1;
	
	a = abs(a);
	b = abs(b);
	
	while (a >= b)
	{
		a = a - b;
		quot++;
	}
	
	printf("Неполное частное: ");
	printf("%d", quot * sign);
    scanf("%*s");
	return 0;
}