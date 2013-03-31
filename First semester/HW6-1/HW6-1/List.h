#pragma once
#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Man
{
	int phoneNumber;
	char* name;
};

struct ListElement
{
	Man value;
	ListElement* next;
};

struct List
{
	ListElement* head;
	int quantity;
};

typedef ListElement*position;

// Загружает список из файла.
void loadFromFile(FILE*, List*);
// Созадает список.
List createList();
// Выводит список в консоль.
void printList(List);
// Добавляет элемент в список.
void addElement(List* , Man);
// Удаляет список.
void deleteList(List*);
// Возвращает последний элемент списка.
position end(List*);
// Возвращает элемент перед данным элементом.
position prev(position , List*);
// Сортировка списка слиянием.
List mergeSort(List*, char);
