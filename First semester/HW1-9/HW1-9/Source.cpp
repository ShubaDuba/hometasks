#include <locale.h>
#include <stdio.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	printf("Введите целое число\n");
	scanf("%d", &n);
	bool *flag = new bool[n];

	for (int i = 0; i < n; ++i)
	{
		flag[i] = true;		
	}

	for (int i = 2; i < n; ++i)
	{
		if (flag[i])
		{
			for ( int j = i * i; j < n; j += i)
			{
				flag[j] = false;
			}
		}
	}

	printf("Простые числа, меньшие данного:\n");
	for (int i = 0; i < n; i++)
	{
		if (flag[i])
		{
			printf("%d", i);
			printf(" ");
		}
	}
	scanf("%*s");
	return 0;
}