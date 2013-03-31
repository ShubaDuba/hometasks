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
// Добавляет элемент в стэк.
void push(Stack*, char);
// Снимает элемент с вершины стэка.
char pop(Stack*);
// Выводит значение вершины стэка.
char peek(Stack*);
// Удаляет стэк.
void deleteStack(Stack*);