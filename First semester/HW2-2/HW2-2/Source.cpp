#include <stdio.h>
#include <locale.h>

int degSlow(int num, int degree)
{
	int tmp = 1;

	for (int i = 0; i < degree; ++i)
		tmp = tmp * num;

	return tmp;
}

int degFast(int num, int degree)
{
	int tmp = 1;
	
	while (degree) 
	{
		if (degree % 2 == 0) 
		{
			degree /= 2;
			num *= num;
		}
		else
		{
			degree--;
			tmp *= num;
		}
	}

	return tmp;
}

int main()
{
	int n = 0;
	int deg = 0;
	setlocale(LC_ALL, "Russian");
	printf("¬ведите число\n");
	scanf("%d", &n);
	printf("¬ведите степень\n");
	scanf("%d", &deg);
	printf("%d", degFast(n, deg));
	scanf("%*s");
	return 0;
}