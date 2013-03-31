#pragma once
#include <stdio.h>
#include <locale.h>

struct ListElement
{
	int value;
	ListElement* next;
};

struct List
{
	ListElement* head;
};

typedef ListElement* Position;

// Создает список.
List createList();
// Выводит список в консоль.
void printList(List list);
// Добавляет элемент с значением value в список.
void addElement(List* list, int value);
// Удаляет элемент из списка по значению.
void deleteElement(List* list, int n);
// Удаляет список.
void deleteList(List* list);
// Возвращает последний жлемент списка.
Position end(List *l);
// Возвращает элемент перед элементом p в списке l.
Position prev(Position p, List *l);
// Проверяет равенство списков.
bool listEquals(List firstList, List secondList);