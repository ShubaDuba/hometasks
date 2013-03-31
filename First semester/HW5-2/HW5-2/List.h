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

// ������� ������.
List createList();
// ������� ������ � �������.
void printList(List list);
// ��������� ������� � ��������� value � ������.
void addElement(List* list, int value);
// ������� ������� �� ������ �� ��������.
void deleteElement(List* list, int n);
// ������� ������.
void deleteList(List* list);
// ���������� ��������� ������� ������.
Position end(List *l);
// ���������� ������� ����� ��������� p � ������ l.
Position prev(Position p, List *l);
// ��������� ��������� �������.
bool listEquals(List firstList, List secondList);