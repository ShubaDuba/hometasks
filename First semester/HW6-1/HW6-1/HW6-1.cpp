#include "list.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* file = fopen("Phonebook.txt", "a+");
	char option = '0';
	printf("�������� ������ ����������:\n 1 - ���������� ������ �� ������ ��������\n 2 - ���������� ������ �� �����\n");
	scanf("%c", &option);
	List list = createList();
	loadFromFile(file, &list);
	list = mergeSort(&list, option);
	printList(list);
	fcloseall();
	scanf("%*s");
	return 0;
}