#include <locale.h>
#include <stdio.h>
#include "superQuickSort.h"

int search(int a[], int length)
{
	int maxentries = 0;
	int result = 0;
	int entries = 0;
	int now = a[0];
	for (int i = 0; i < length; ++i)
	{
		if (a[i] == now)
		{
			++entries;

			if (entries > maxentries)
				{
					maxentries = entries;
					result = a[i];
				}
		}
		else
		{
			entries = 1;
			now = a[i];
		}
	}
	return result;
}

int main()
{
	setlocale(LC_ALL , "Russian");
	const int n = 24;
	FILE* file = fopen("input.txt", "r");
	int* arr = new int[n];
	printf("Заданный массив:\n");

	for (int i = 0; i < n; ++i)
	{
		fscanf(file, "%d", &arr[i]);
		printf("%d ", arr[i]);
	}
	fclose(file);
	superQuickSort(arr, 0, n - 1);
	printf("\nНаиболее часто встречающийся элемент массива:\n%d" , search(arr, n));
	
	scanf("%*s");
}