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

bool binSearch(int element, int length, int* arr)
{
	int left = 0;
	int right = length - 1;	

	while (left < right)
	{
		int mid = left + (right - left) / 2;
		int tmp = arr[mid];

		if (tmp == element)
			return true;
		else
		{
			if (tmp > element)
				right = mid;
			else
				left = mid + 1;
		}
					
	}

	return false;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_CTYPE,"Russian");
	int n = 0;
	int k = 0;
	printf("Введите кол-во элементов массива(до 5000)\n");
	scanf("%d",&n);
	int *arr = new int[n];
	printf("Данный массив ");

	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 999999999;
		printf("%d", arr[i]);
		printf(" ");
	}
	
	printf("\n");
	superQuickSort(arr, 0, n - 1);
	printf("Введите кол-во целых чисел(до 300000)\n");
	scanf("%d",&k);

	for (int i = 0; i < k; ++i)
	{
		int tmp = rand() % 999999999; 
		printf("%d", tmp);
		printf(" ");
		if (binSearch(tmp, n, arr))
			printf(" содержится\n");
		else
			printf(" не содержится\n");
	}

	delete []arr;
	scanf("%*s");
	return 0;
}