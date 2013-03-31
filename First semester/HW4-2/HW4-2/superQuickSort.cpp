#include "superQuickSort.h"

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