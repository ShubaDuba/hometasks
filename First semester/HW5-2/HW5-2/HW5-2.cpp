#include "List.h"
/*
���������������� ��������: ���������� � ������ ������, ���������� �������� �������� head, ���������� � ������, ���������� ������
head, ����� �� ����� ���� �������, �������� ��������, ������������� � ������, � ���.
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	List list = createList();
	char option = '4';
	printf("�������� ��������:\n 0 - �����\n 1 - �������� �������� � ������������� ������\n 2 - ������� �������� �� ������\n 3 - ����������� ������\n");
	while (option != '0')
	{
		scanf("%c", &option);
		if (option == '1')
		{
			int value = 0;
			printf("������� ��������, ������� �� ������ ��������.\n");
			scanf("%d", &value);
			addElement(&list, value);
		}
		
		if (option == '2')
		{
			int value = 0;
			printf("������� ��������, ������� �� ������ �������.\n");
			scanf("%d", &value);
			deleteElement(&list, value);
		}

		if (option == '3')
			printList(list);
	}
	deleteList(&list);
	return 0;
}