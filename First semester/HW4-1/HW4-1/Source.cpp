#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int pow (int arg, int power)
{
	if (!power) 
		return 1;
	else 
		return arg * pow(arg ,power - 1);
}

void binarPrint(int bin[], int size)
{
	for (int i = size - 1; i >= 0; --i)
		printf("%d", bin[i]);
}

void binarConvertTo(int n, int bin[], int size)
{
	for (int i = size - 1; i >= 0; --i)
	{
		int tmp = n >> i & 1;
		bin[i] = tmp;
	}
}

int binarConvertFrom(int bin[], int size)
{
	int n = 0;
	for (int i = size - 1; i >= 0; --i)
		n += bin[i] * pow(2, i);
	return n;
}

void binarSum(int bin1[], int bin2[], int resBin[], int size)
{
	for (int i = 0; i < size; ++i)
		resBin[i] = 0;
	for (int i = 0; i < size; ++i)
	{
		resBin[i] += bin1[i] + bin2[i];
		if (resBin[i] > 1) 
		{
			resBin[i + 1] += resBin[i] / 2;
			resBin[i] = resBin[i] % 2;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int const sizeBin = 32;
	int* firstBin = new int[sizeBin];
	int* secondBin = new int[sizeBin];
	int* resultBin = new int[sizeBin];
	int input = 0;
	
	printf("Введите первое число\n");
	scanf("%d", &input);
	binarConvertTo(input, firstBin, sizeBin);
	
	printf("Введите второе число\n");
	scanf("%d", &input);
	binarConvertTo(input, secondBin, sizeBin);

	printf("Двоичная запись данных чисел:\n");
	printf("\nПервое число: ");
	binarPrint(firstBin, sizeBin);
	printf("\nВторое число: ");
	binarPrint(secondBin, sizeBin);
	
	printf("\nДвоич. сумма: ");
	binarSum(firstBin, secondBin, resultBin, sizeBin);
	binarPrint(resultBin, sizeBin);

	int decResult = binarConvertFrom(resultBin, sizeBin);
	printf("\nДесятичное представление суммы: ");
	printf("%d\n", decResult);

	scanf("%*s");
	return 0;
}