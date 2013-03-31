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

// ���������� ��������� �� ������ ������.
List* createList();

// ������� ������ � �������.
void printList(List*);

// ��������� ������� � ������.
void addElement(List*, int, char*);

// ���������, ���������� �� ������� � ������.
bool elementExists(List*, char*);

// ���������� NULL ��� ������� �������� ������.
Position getPosition(List*, char*);

// ���������� ���-�� ��������� ������.
int amount(List*);

// ������� ������� �� ��������� value.
void deleteElement(List*, int);

// ������� ������.
void deleteList(List*);