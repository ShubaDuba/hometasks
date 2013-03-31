#include "Stack.h"
//�������������� ��� ������, � �.� ������ ������ � ���������� �������� ������.
int main()
{
	setlocale(LC_ALL, "Russian");
	char* string = new char[50];
	printf("������� ������\n");
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
				printf("����������� ����������� ������\n");
				scanf("%*s");
				return 0;
			}
			
			char tmp = pop(&stack);

			if ((string[i] == ']' && tmp != '[') || (string[i] == '}' && tmp != '{') || (string[i] == ')' && tmp != '('))
			{
				printf("����������� ����������� ������\n");
				scanf("%*s");
				return 0;
			}
		}
	}

	if (stack.topElement == -1)
		printf("C����� ����������� ���������\n");
	else
		printf("����������� ����������� ������\n");
	deleteStack(&stack);
	delete[] string;
	scanf("%*s");
	return 0;
}