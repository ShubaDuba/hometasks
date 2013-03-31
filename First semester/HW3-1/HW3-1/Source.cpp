#include <stdio.h>
#include <locale.h>

void insertSort(int a[], int left, int right)//сортировка вставками
{
	for (int i = left + 1; i < right + 1; ++i)
	{
		int tmp = a[i];
		int j = i - 1;
		while (j >= 1 && a[j] > tmp)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = tmp;
	}
}

void superQuickSort(int a[], int left, int right)//quick-sort для менее чем 10 эл-тов использует сортировку вставками
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

int main()
{
	setlocale(LC_CTYPE,"Russian");
	int num = 11;
	int arr[] = {1, 1, 2, 3, 123, 21312, 12, 41323, 213, 1, 12223};
	superQuickSort(arr, 0, num - 1);
	printf("Отсортированный массив:\n");
	for (int i = 0; i < num; i++)
	{
		printf("%d",arr[i]);
		printf(" ");
	}
	scanf("%*s");
	return 0;
}
