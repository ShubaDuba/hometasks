#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[] = "(qwq(aasd)j)asdqwawd";
	int n = strlen(str);
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == '(')
			j = j + 1;
		if (str[i] == ')')
		{
			if (j == 0)
			{
				printf("Скобки стоят неправильно\n");
				j = j - 1;
				break;
			}
			else
				j = j - 1;
		}
	}
	if (j == 0)
		printf("Скобки расставлены правильно");
	if (j > 0)
		printf("Скобки стоят неправильно\n");
	scanf("%*s");
	return 0;
}