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
// Создает стэк.
Stack createStack(int);
// добавляет элемент в стэк.
void push(Stack*, char);
// Снимает элемент с вершины стэка.
char pop(Stack*);
// Удаляет стэк.
void deleteStack(Stack*);