#include "HashTable.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	HashTable* hashTable = createHashTable(50);
	FILE* f = fopen("input.txt", "rt");

	while(!feof(f))
	{
		char* buffer = new char[10];
		if (fscanf(f, "%s ", buffer) != -1)
		{
			addToTable(hashTable, buffer);
		}
		delete[] buffer;
	}

	printTable(hashTable);
	deleteTable(hashTable);
	fcloseall();
	scanf("%*s");
	return 0;
}