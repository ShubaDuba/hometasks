#pragma once
#include <stdio.h>
#include <locale.h>
#include <string.h>

struct ListElement
{
	int value;
	char* word;
	ListElement* next;
};

struct List
{
	ListElement* head;
};

typedef ListElement* Position;

// Возвращает указатель на пустой список.
List* createList();

// Выводит список в консоль.
void printList(List*);

// Добавляет элемент в список.
void addElement(List*, int, char*);

// Проверяет, содержится ли элемент в списке.
bool elementExists(List*, char*);

// Возвращает NULL или позицию элемента списка.
Position getPosition(List*, char*);

// Возвращает кол-во элементов списка.
int amount(List*);

// Удаляет элемент со значением value.
void deleteElement(List*, int);

// Удаляет список.
void deleteList(List*);