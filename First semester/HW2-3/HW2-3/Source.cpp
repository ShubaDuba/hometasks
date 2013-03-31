#include <stdio.h>
#include <locale.h>

void countSort(int Array[], int n)
{
    int min = Array[0];
	int max = Array[0];
    
	for (int i = 1; i < n; i++)
    {
        if (Array[i] < min)
            min = Array[i];
        else 
        if (Array[i] > max)
            max = Array[i];
    }
 
    int *countArray = new int[max - min + 1];
    int *tmpArray = new int[n];
 
    for (int i = 0; i < (max - min + 1); i++)
        countArray[i] = 0;
 
    for (int i = 0; i < n; i++)
        countArray[Array[i] - min]++;
 
    for (int i = 1; i < (max - min + 1); i++)
        countArray[i] += countArray[i - 1];
 
    for (int i = 0; i < n; i++)
        tmpArray[countArray[Array[i] - min]-- -1 ] = Array[i];
 
    for (int i = 0; i < n; i++)
        Array[i] = tmpArray[i];
    
    delete [] tmpArray;
    delete [] countArray;
}

void bubbleSort(int*A, int n)
{
	for (int i = n - 1; i > 0; --i)
	{
		for (int j = 0; j < i; j++)
		{
			if(A[j] > A[j + 1])
			{
				int tmp = A[j];
				A[j] = A[j + 1];
		        A[j + 1] = tmp;
			}
		}
	}
}
 
int main()
{
	setlocale(LC_ALL, "Russian");
    int Arr[6] = {5, 4, 3, 2, 1, 10};
 
    countSort(Arr, 6);
	bubbleSort(Arr, 6);
	printf("Отсортированный массив:\n");
    for (int i = 0; i < 6; i++)
		printf("%d ", Arr[i]);
    
    scanf("%*s");
	return 0;
}
