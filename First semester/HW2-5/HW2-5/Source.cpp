#include <stdio.h>
#include <locale.h>
const int n = 6;
int main()
{
	setlocale(LC_ALL, "Russian");
	int Arr[n];
	printf("Введите коэфф. многочлена степени %d, начиная со старшего.\n", n - 1);

	for (int i = 0; i < n; ++i)
		scanf("%d", &Arr[i]);
	
	for (int i = 0; i < n; ++i)
	{
		if (Arr[i] != NULL){
			if (i > 0 && Arr[i] > 0)
				printf("+");
			if (Arr[i] != 1)
				printf("%d", Arr[i]);
			if (i != n - 1)
				printf("x");
			if (n - i > 2)
			{
				printf("^");
				printf("%d", n - i - 1);
			}
			printf(" ");
		}
	}

	scanf("%*s");
}