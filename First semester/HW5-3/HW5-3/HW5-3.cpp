#include "List.h"
//Тесты: 100 1 = 100, 12 4 = 1, 1 100 = 1, 8 25 = 3.
int main()
{
	setlocale(LC_ALL, "Russian");
	List list = createList();
	int n = 0, m = 0;
	printf("Введите кол-во солдат и какого по счету воина будут убивать(оба числа больше 0)\n");
	scanf("%d", &n);
	scanf("%d", &m);

	ListElement* element = new ListElement;
	element->value = 1;
	list.head = element;
	list.head->next = list.head;
	if (n > 1)
		for (int i = 2; i < n + 1; ++i)
		{
			ListElement* tmp = new ListElement;
			tmp->value = i;
			tmp->next = list.head;
			end(&list)->next = tmp;
		}

	element = end(&list);

	while (list.head->next != list.head)
	{
		for (int i = 0; i < m - 1; ++i)
			element = element->next;
		deleteElement(&list, element->next->value);
	}

	
	printf("Место последнего оставшегося в живых воина: %d\n",list.head->value);
	deleteList(&list);
	scanf("%*s");
	return 0;
}