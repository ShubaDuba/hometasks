#include "Stack.h"
//Протестированы все случаи, в т.ч пустая строка и отсутствие закрытия скобок.
int main()
{
	setlocale(LC_ALL, "Russian");
	char* string = new char[50];
	printf("Введите сторку\n");
	scanf("%s", string);
	Stack stack = createStack(strlen(string));

	for (int i = 0; i < strlen(string); ++i)
	{
		if (string[i] == '[' || string[i] == '{' || string[i] == '(')
			push(&stack, string[i]);

		if (string[i] == ']' || string[i] == '}' || string[i] == ')')
		{
			if (stack.topElement == -1)
			{
				printf("Неправильно расставлены скобки\n");
				scanf("%*s");
				return 0;
			}
			
			char tmp = pop(&stack);

			if ((string[i] == ']' && tmp != '[') || (string[i] == '}' && tmp != '{') || (string[i] == ')' && tmp != '('))
			{
				printf("Неправильно расставлены скобки\n");
				scanf("%*s");
				return 0;
			}
		}
	}

	if (stack.topElement == -1)
		printf("Cкобки расставлены правильно\n");
	else
		printf("Неправильно расставлены скобки\n");
	deleteStack(&stack);
	delete[] string;
	scanf("%*s");
	return 0;
}