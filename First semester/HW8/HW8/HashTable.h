#pragma once
#include "List.h"
struct HashTable
{
	List** data;
	int size;
};

// Возвращает указатель на новую пустую таблицу.
HashTable* createHashTable(int);

// Добавляет элемент в таблицу.
void addToTable(HashTable*, char*);

// Удаляет элемент из таблицы.
void deleteFromTable(HashTable*, char*);

// Проверяет, содержится ли элемент в таблице.
bool existsInTable(HashTable*, char*);

// Удаляет таблицу.
void deleteTable(HashTable*);

// Выводит таблицу в консоль.
void printTable(HashTable*);