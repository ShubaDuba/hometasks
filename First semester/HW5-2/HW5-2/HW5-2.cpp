#include "List.h"
/*
Протестированные ситуации: добавление в пустой список, добавление элемента меньшего head, добавление в список, содержащий только
head, вывод на экран всех случаев, удаление элемента, содержащегося в списке, и нет.
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	List list = createList();
	char option = '4';
	printf("Выберите операцию:\n 0 - выход\n 1 - добавить значение в сортированный список\n 2 - удалить значение из списка\n 3 - распечатать список\n");
	while (option != '0')
	{
		scanf("%c", &option);
		if (option == '1')
		{
			int value = 0;
			printf("Введите значение, которое вы хотите добавить.\n");
			scanf("%d", &value);
			addElement(&list, value);
		}
		
		if (option == '2')
		{
			int value = 0;
			printf("Введите значение, которое вы хотите удалить.\n");
			scanf("%d", &value);
			deleteElement(&list, value);
		}

		if (option == '3')
			printList(list);
	}
	deleteList(&list);
	return 0;
}