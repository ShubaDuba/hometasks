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
// Создает стэк.
Stack createStack(int);
// Добавляет элемент в стэк.
void push(Stack*, int);
// Снимает элемент с вершины стэка.
int pop(Stack*);
// Удаляет стэк.
void deleteStack(Stack*);