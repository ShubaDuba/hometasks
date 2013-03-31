#include <stdio.h>
#include <locale.h>
#include <string.h>

// Поиск подстроки в стороке по алгоритму Кнута - Морриса - Пратта.
int substringSeek (char s[], char sub[])
{ 
	int i = 0;
	int j = 0;
	int n = strlen(s); 
	int m = strlen(sub); 
	int* arr = new int[m];
	arr[0] = 0;

	for (i = 1, j = 0; i < m; i++)
	{
		while (j > 0 && sub[j] != sub[i]) 
			j = arr[j - 1];

		if (sub[j] == sub[i])
			j++;

		arr[i] = j;
	}

	for (i = 0, j = 0; i < n; i++)
	{
		while (j > 0 && sub[j] != s[i])
			j = arr[j - 1];

		if (sub[j] == s[i]) 
			j++;

		if (j == m)
		{
			delete[] arr;
			return i - j + 1;
		}
	}
	delete[] arr;
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* file = fopen("input.txt", "r");
	char* buffer = new char[1000];
	int position = 0;
	printf("Данный текст:\n");

	while (!feof(file))
	{
		char tmp = NULL;
		fscanf(file, "%c", &tmp);
		buffer[position++] = tmp;
		printf("%c", tmp);
	}

	char subString[30];
	printf("\nВведите искомую подстроку\n");
	scanf("%s", &subString);
	int tmp = substringSeek(buffer, subString);

	if (tmp == -1)
		printf("Искомая подстрока отсутствует\n");
	else
		printf("первое вхождение искомой подстроки: %d\n", tmp);

	delete[] buffer;
	fcloseall();
	scanf("%*s");
	return 0;
}