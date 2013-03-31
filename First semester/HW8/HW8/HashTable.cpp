#include "HashTable.h"

int hash(char* str, int size)
{
	int result = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		result += str[i++];
	}
	return result % size;
}

HashTable* createHashTable(int size)
{
	HashTable* table = new HashTable;
	table->data = new List*[size];

	for (int i = 0; i < size; ++i)
	{
		table->data[i] = createList();
	}

	table->size = size;
	return table;
}

void addToTable(HashTable* table, char* word)
{
	int index = hash(word, table->size);
	if (!elementExists(table->data[index], word))
		addElement(table->data[index], 1, word);
	else
	{
		Position p = getPosition(table->data[index], word);
		++p->value;
	}
}

void deleteFromTable(HashTable* table, char* word)
{
	int index = hash(word, table->size);
	if (elementExists(table->data[index], word))
	{
		Position p = getPosition(table->data[index], word);
		if (--p->value == 0)
			deleteElement(table->data[index], 0);
	}

}

bool search(HashTable* table, char* word)
{
	int index = hash(word, table->size);
	if (elementExists(table->data[index], word))
		return true;
	return false;
}

void deleteTable(HashTable* table)
{
	for(int i = 0; i < table->size; ++i)	
	{
		deleteList(table->data[i]);
	}
}

void printTable(HashTable* table)
{
	for(int i = 0; i < table->size; ++i)
		printList(table->data[i]);
}