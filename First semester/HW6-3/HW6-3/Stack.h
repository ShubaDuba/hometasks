#pragma once

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
	char* data;
	int topElement;
};
// ������� ����.
Stack createStack(int);
// ��������� ������� � ����.
void push(Stack*, char);
// ������� ������� � ������� �����.
char pop(Stack*);
// ������� ����.
void deleteStack(Stack*);