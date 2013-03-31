#include <stdio.h>
#include <locale.h>
#include <string.h>
//Тесты: 1 = true, 123. = false, 123E = false, 123E1 = true, 123.321E+123 = true, 333.123E-228 = true, .123 = false.
bool check(char* string, int position, char state)
{
	switch (state)
	{
		case '0':
			if (string[position] >= '0' && string[position] <= '9')
				return check(string, ++position, '1');
			else
				return false;
		
		case '1':
			if (string[position] >= '0' && string[position] <= '9')
				return check(string, ++position, '1');			 
			else
				if (string[position] == '.')
					return check(string, ++position, '2');
				else
					if (string[position] == 'E')
						return check(string, ++position, '4');
					else
						if (string[position] == '\0')
							return check(string, position, '6');
						else
							return false;
		
		case '2':
			if (string[position] >= '0' && string[position] <= '9')
				return check(string, ++position, '3');
			else
				return false;
		
		case '3':
			if (string[position] >= '0' && string[position] <= '9')
				return check(string, ++position, '3');
			else
				if (string[position] == 'E')
					return check(string, ++position, '4');
				else
					if (string[position] == '\0')
						return check(string, position, '6');
					else
						return false;
		
		case '4':
			if (string[position] >= '0' && string[position] <= '9' || string[position] == '+' || string[position] == '-')
				return check(string, ++position, '5');
			else
				return false;

		case '5':
			if (string[position] >= '0' && string[position] <= '9')
				return check(string, ++position, '5');
			else
				if (string[position] == '\0')
					return check(string, position, '6');
				else
					return false;
		
		case '6':
			return true;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Введите строку\n");
	char* str = new char[100];
	scanf("%s", str);

	if (check(str, 0, '0'))
		printf("Строка является вещественным числом\n");
	else
		printf("Строка не является вещественным числом\n");
	
	delete[] str;
	scanf("%*s");
	return 0;
}