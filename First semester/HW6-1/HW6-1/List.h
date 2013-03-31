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

// ��������� ������ �� �����.
void loadFromFile(FILE*, List*);
// �������� ������.
List createList();
// ������� ������ � �������.
void printList(List);
// ��������� ������� � ������.
void addElement(List* , Man);
// ������� ������.
void deleteList(List*);
// ���������� ��������� ������� ������.
position end(List*);
// ���������� ������� ����� ������ ���������.
position prev(position , List*);
// ���������� ������ ��������.
List mergeSort(List*, char);
