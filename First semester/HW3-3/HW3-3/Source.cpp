#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

void insertSort(int a[], int left, int right)
{
	for (int i = left + 1; i < right + 1; ++i)
	{
		int tmp = a[i];
		int j = i - 1;

		while (j >= 1, a[j] > tmp)
		{
			a[j+1] = a[j];
			j = j - 1;
		}

		a[j + 1] = tmp;
	}
}

void superQuickSort(int a[], int left, int right)
{
	if (right - left < 10)
		insertSort(a, left, right);
	else
	{
		int i = left;
		int j = right;
		int base = a[(left + right) / 2];
		
		while (i <= j)
		{
			while (a[i] < base)
				i++;

			while (a[j] > base)
				j--;

			if (i <= j)
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				i++;
				j--;
			}
		}
	
	
		if (left < j)
			superQuickSort(a, left, j);

		if (i < right)
			superQuickSort(a, i, right);
	}
}

int search(int a[], int length)
{
	int maxEntries = 0;
	int result = 0;
	int entries = 0;
	int now = a[0];
	for (int i = 0; i < length; ++i)
	{
		if (a[i] == now)
		{
			++entries;

			if (entries > maxEntries)
			{
				maxEntries = entries;
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
	srand(time(NULL));
	int n = 0;
	int k = 0;
	printf("Введите кол-во элементов массива\n");
	scanf("%d", &n);
	int *arr = new int[n];
	printf("Данный массив: ");

	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 9;
		printf("%d", arr[i]);
		printf(" ");
	}

	superQuickSort(arr, 0, n - 1);
	printf("\nНаиболее всетречающийся элемент массива: %d" , search(arr, n));

	scanf("%*s");
}