#pragma once
#include "List.h"
struct HashTable
{
	List** data;
	int size;
};

// ���������� ��������� �� ����� ������ �������.
HashTable* createHashTable(int);

// ��������� ������� � �������.
void addToTable(HashTable*, char*);

// ������� ������� �� �������.
void deleteFromTable(HashTable*, char*);

// ���������, ���������� �� ������� � �������.
bool existsInTable(HashTable*, char*);

// ������� �������.
void deleteTable(HashTable*);

// ������� ������� � �������.
void printTable(HashTable*);