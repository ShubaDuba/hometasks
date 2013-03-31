#include "List.h"

List* createList()
{
	List* tmp = new List;
	tmp->head = NULL;
	return tmp;
}

Position next(List* list, Position pos)
{
	if (pos == NULL)
		return NULL;
	return pos->next;
}

void printList(List* list)
{
	Position tmp = list->head;
	while (tmp != NULL)
	{
		printf("Слово: %s Кол-во: %d\n", tmp->word, tmp->value);
		tmp = next(list, tmp);
	}
}

void addElement(List* list, int value, char* word)
{
	Position tmp = list->head;
	ListElement* element = new ListElement;
	element->next = NULL;
	element->value = value;
	element->word = new char[50];
	strcpy(element->word, word);

	if (tmp == NULL)
	{
		list->head = element;
		return;
	}

	while(next(list, tmp) != NULL)
	{
		tmp = next(list, tmp);
	}
	tmp->next = element;
}

bool elementExists(List* list, char* value)
{
	Position tmp = list->head;

	if (tmp == NULL)
		return false;

	while (tmp != NULL)
	{
		if (strcmp(tmp->word, value) == 0)
			return true;
		tmp = next(list, tmp);
	}

	return false;
}

Position getPosition(List* list, char* word)
{
	Position tmp = list->head;

	while(tmp != NULL)
	{
		if (strcmp(tmp->word, word) == 0)
			return tmp;
		tmp = next(list, tmp);
	}

	return NULL;
}

int amount(List* list)
{
	if (list == NULL || list->head == NULL)
		return 0;

	int result = 1;
	Position tmp = list->head;

	while(next(list, tmp) != NULL)
	{
		++result;
		tmp = next(list, tmp);
	}

	return result;
}

void deleteElement(List* list, int n)
{
	if (list->head == NULL)
	{
		printf("Список пуст!\n");
		return;
	}
	ListElement* element = list->head;

	if (element->value == n)
	{
		ListElement* tmp = list->head;
		list->head = element->next;
		delete tmp;
		return;
	}

	while(next(list, element) != NULL)
	{
		if (element->next->value == n)
		{
			ListElement* tmp  = next(list, element);
			element->next = next(list, next(list, element));
			delete tmp;
			return;
		}
		element = next(list, element);
	}

	printf("Элемента в списке нет!\n");
}

void deleteList(List* list)
{
	if (list->head == NULL)
		return;

	if (next(list, list->head) == NULL)
	{
		delete list->head;
		return;
	}

	Position element = list->head;
	while (element->next != NULL)
	{
		Position tmp = element;
		element = next(list, element);
		delete tmp;
	}
}