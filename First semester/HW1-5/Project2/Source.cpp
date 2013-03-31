#include <stdio.h>
#include <cstdlib>
#include <locale.h>

//Разворот части массива начиная с элемента ch + 1(ch > 0), count - кол-во разворачиваемых символов, включая символ ch
void arrReverse(int tempArr[], int ch, int count)		
{
	for (int i = ch - 1; i < ch - 1 + count / 2; ++i)		
	{
		int tmp = tempArr[i];
		tempArr[i] = tempArr[ch - 1 + ch - 1 + count - i - 1];
		tempArr[ch - 1 + ch - 1 + count - i - 1] = tmp;
	}
}

int main()
{
	int n = 0;
	int m = 0;
	setlocale(LC_ALL, "Russian");
	printf("Введите кол-во символов в начале массива\n");
	scanf("%d", &m);
	printf("Введите кол-во символов в конце массива\n");
	scanf("%d", &n);
	int* fullArr = new int[n + m];
	printf("Изначальный массив\n");
	
	//Заполнение массива случайными числами
	for (int i = 0; i < n + m; ++i)			
	{
		fullArr[i] = rand() % 99;
		printf("%d", fullArr[i]);
		printf(" ");
	}

	arrReverse(fullArr, 1, m);
	arrReverse(fullArr, m + 1, n);
	arrReverse(fullArr, 1, m + n);
	printf("\n");
	printf("Результат\n");

	//Вывод массива
	for (int i = 0;  i < n + m; ++i)		
	{
		printf("%d", fullArr[i]);
		printf(" ");
	}
	
	delete[] fullArr;
	scanf("%*s");
	return 0;
}