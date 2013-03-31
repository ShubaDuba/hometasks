#pragma once
#include <stdio.h>
#include <locale.h>

struct ListElement
{
	char value;
	ListElement* next;
};

struct List
{
	ListElement* head;
};

typedef ListElement*position;

// Создает список.
List createList();
// Выводит список в консоль.
void printList(List list);
// Добавляет элемент с значением value в список.
void addElement(List* list, char value);
// Удаляет элемент из списка по значению.
void deleteElement(List* list, char n);
// Удаляет список.
void deleteList(List* list);
// Возвращает последний элемент списка.
position end(List *l);
// Возвращает элемент перед элементом p в списке l.
position prev(position p, List *l);
// Проверяет равенство списков.
bool listEquals(List firstList, List secondList);
// Обнуляет весь список.
void listReset(List* list);