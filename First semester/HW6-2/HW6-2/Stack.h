#pragma once

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
	int* data;
	int topElement;
};
// ������� ����.
Stack createStack(int);
// ��������� ������� � ����.
void push(Stack*, int);
// ������� ������� � ������� �����.
int pop(Stack*);
// ������� ����.
void deleteStack(Stack*);