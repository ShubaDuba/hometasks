#include <stdio.h>
#include <locale.h>

int main()
{
	int summ[28] = {0};
	
	for (int x = 0; x < 10; ++x)
	{
		for (int y = 0; y < 10; ++y)
		{
			for (int z = 0; z < 10; ++z)
			{
				++summ[x + y + z];
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 28; ++i)
	{
		result += summ[i] * summ[i];
	}

	setlocale(LC_ALL, "Russian");
	printf("—частливых билетов всего: ");
	printf("%d", result);
	scanf("%*s");
}