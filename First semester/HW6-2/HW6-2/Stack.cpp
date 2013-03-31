#include "Stack.h"

Stack createStack(int stackSize)
{
	Stack tmp;
	tmp.data = new int[stackSize];
	tmp.topElement = -1;
	return tmp;
}

void push(Stack* tmp, int value)
{
	tmp->data[++tmp->topElement] = value;
}

int pop(Stack* tmp)
{
	return tmp->data[tmp->topElement--];
}

void deleteStack(Stack* tmp)
{
	delete[] tmp->data;
}