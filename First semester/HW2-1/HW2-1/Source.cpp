#include <stdio.h>
#include <locale.h>

int fibRec(int n)//число фибоначчи рекурсивно
{
	if (n <= 1)
		return 1;
	else
		return fibRec(n - 2) + fibRec(n - 1);
}

int fibIter(int n)
{
	int f0 = 1, f1 = 1,  fRes;
	
	if (n <= 1) 
		return 1;

	for(int k = 2; k <= n; k++)
    {
      fRes = f0 + f1;
      f1 = f0;
      f0 = fRes;
    }

  return fRes;
}

int main()
{
	int num = 0;
	setlocale(LC_ALL, "Russian");
	printf("Введите номер числа фибоначчи\n");
	scanf("%d", &num);
	int result = fibIter(num);
	printf("%d", result);
	
	scanf("%*s");
	return 0;
}