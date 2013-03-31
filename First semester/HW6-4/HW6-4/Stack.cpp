#include "Stack.h"

Stack createStack(int stackSize)
{
	Stack tmp;
	tmp.data = new char[stackSize];
	tmp.topElement = -1;
	return tmp;
}

void push(Stack* tmp, char value)
{
	tmp->data[++tmp->topElement] = value;
}

char pop(Stack* tmp)
{
	return tmp->data[tmp->topElement--];
}

char peek(Stack* stack)
{
	return stack->data[stack->topElement];
}

void deleteStack(Stack* tmp)
{
	delete[] tmp->data;
}