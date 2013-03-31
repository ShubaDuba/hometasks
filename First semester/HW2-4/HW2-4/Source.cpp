#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int* part(int* a, int count)
{
	int tmp = a[0];
	int j = 0;

	for (int i = 0; i < count; ++i)
	{
		if (a[i] < tmp)
		{
			a[j] = a[i];
			a[i] = a[j + 1];
			a[j + 1] = tmp;
			j++;
		}
	}
	return a;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand((unsigned)(time(NULL)));
	int n = NULL;
	printf("Введите кол-во элементов массива\n");
	scanf("%d", &n);
	int* Arr = new int[n];
	
	printf("Изначальный массив:\n");
	for (int i = 0; i < n; ++i)
	{
		Arr[i] = rand()%100 - 1;
		printf("%d ", Arr[i]);
	}

	printf("\n");
	part(Arr, n);

	printf("Разделенный массив:\n");
	for (int i = 0; i < n; ++i)
		printf("%d ", Arr[i]);

	delete []Arr;
	scanf("%*s");
	return 0;
}