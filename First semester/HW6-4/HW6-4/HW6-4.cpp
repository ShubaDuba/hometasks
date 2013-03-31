#include "Stack.h"

bool operatorComparison(char op1, char op2)
{
	if ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/'))
		return true;
	if ((op1 == '*' || op1 == '/') && (op2 == '*' || op2 == '/'))
		return true;

	return false;
}

bool isOperator(char op)
{
	return (op == '-' || op == '+' || op == '*' || op == '/');
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char* string = new char[50];
	scanf("%s", string);
	char* result = new char[50];
	strcpy(result, "");
	Stack stack = createStack(strlen(string));

	for (int i = 0; i < strlen(string); ++i)
	{
		if (string[i] >= '0' && string[i] <= '9')
		{
			int tmp = strlen(result);
			result[tmp] = string[i];
			result[tmp + 1] = '\0';
		}

		if (string[i] == '(')
			push(&stack, string[i]);

		if (string[i] == ')')
		{
			char tmp = pop(&stack);
			while (tmp != '(')
			{
				int tmp1 = strlen(result);
				result[tmp1] = tmp;
				if (stack.topElement != -1)
				{
					tmp = pop(&stack);
					++tmp1;
				}
				result[tmp1] = '\0';
			}
		}

		if (isOperator(string[i]))
		{
			if (stack.topElement == -1)
				push(&stack, string[i]);
			else
			{
				char tmp = peek(&stack);

				if (operatorComparison(string[i], tmp))
				{
					tmp = pop(&stack);
					result[strlen(result)] = tmp;
					push(&stack, string[i]);
				}
				else
				{
					push(&stack, string[i]);
				}
				
			}
		}		
	}

	while (stack.topElement != -1)
	{
		int tmp = strlen(result);
		result[tmp] = pop(&stack);
		result[tmp + 1] = '\0';
	}

	deleteStack(&stack);
	delete[] string;
	printf("%s", result);
	scanf("%*s");
	return 0;
}