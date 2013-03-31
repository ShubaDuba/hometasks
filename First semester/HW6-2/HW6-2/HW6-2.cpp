#include "Stack.h"
//тесты: 12+12+*=9, 24/21*+=4,12*2*2*2/=4;
int main()
{
	setlocale(LC_ALL, "Russian");
	char* string = new char[50];
	printf("¬ведите выражение в постфиксной форме\n");
	scanf("%s", string);
	Stack stack = createStack(strlen(string));

	for (int i = 0; i < strlen(string); ++i)
	{
		if (string[i] >= '0' && string[i] <= '9')
			push(&stack, string[i] - '0');

		if (string[i] == '+')
			push(&stack, pop(&stack) + pop(&stack));
		
		if (string[i] == '-')
		{	
			int tmp = pop(&stack);
			push(&stack, pop(&stack) - tmp);
		}

		if (string[i] == '*')
			push(&stack, pop(&stack) * pop(&stack));
		
		if (string[i] == '/')
		{
			int tmp = pop(&stack);
			push(&stack, pop(&stack) / tmp);
		}
	}

	printf("%d", pop(&stack));
	delete[] string;
	deleteStack(&stack);
	scanf("%*s");
	return 0;
}