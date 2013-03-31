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

// ������� ������.
List createList();
// ������� ������ � �������.
void printList(List list);
// ��������� ������� � ��������� value � ������.
void addElement(List* list, char value);
// ������� ������� �� ������ �� ��������.
void deleteElement(List* list, char n);
// ������� ������.
void deleteList(List* list);
// ���������� ��������� ������� ������.
position end(List *l);
// ���������� ������� ����� ��������� p � ������ l.
position prev(position p, List *l);
// ��������� ��������� �������.
bool listEquals(List firstList, List secondList);
// �������� ���� ������.
void listReset(List* list);