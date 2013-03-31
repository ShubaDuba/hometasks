#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int arr[10] = {2,3,4,5,0,1,2,4,5,0};

	int count = 0;

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
		if (arr[i] == 0)
			++count;
	}

	printf("\nКол-во нулевых эл-тов массива: \n");
	printf("%d", count);
	scanf("%*s");
	return 0;
}