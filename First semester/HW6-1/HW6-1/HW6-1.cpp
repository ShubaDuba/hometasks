#include "list.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* file = fopen("Phonebook.txt", "a+");
	char option = '0';
	printf("¬ыберите способ сортировки:\n 1 - сортировка списка по номеру телефона\n 2 - сортировка списка по имени\n");
	scanf("%c", &option);
	List list = createList();
	loadFromFile(file, &list);
	list = mergeSort(&list, option);
	printList(list);
	fcloseall();
	scanf("%*s");
	return 0;
}