#include "List.h"
#include <stdio.h>
#include <locale.h>

List createList()
{
	List list;
	list.head = NULL;
	return list;
}

void printList(List list)
{
	if (list.head == NULL)
		printf("—писок пуст.");
	ListElement* tmp = list.head;		

	while(tmp != NULL)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}

	printf("\n");
}

void addElement(List* list, int value)
{
	ListElement* tmp = new ListElement;
	tmp->value = value;
	tmp->next = NULL;		

	if (list->head == NULL)
	{
		list->head = tmp;
		return;
	}

	if (list->head->value > value)
	{
		tmp->next = list->head;
		list->head = tmp;
		return;
	}

	if (list->head->next == NULL)
	{
		list->head->next = tmp;
		return;
	}

	ListElement* el = list->head;

	while ((el->next != NULL) && (value > el->next->value))
		el = el->next;
	
	tmp->next = el->next;
	el->next = tmp;
	return;
}

void deleteElement(List* list, int n)
{
	if (list->head == NULL)
	{
		printf("Ёлемента в списке нет.\n");
		return;
	}

	ListElement* el = list->head;

	if (el->value == n)
	{
		ListElement* tmp = list->head;
		list->head = el->next;
		delete tmp;
		printf("Ёлемент успешно удален из списка.\n");
		return;
	}

	while(el->next != NULL)
	{
		if (el->next->value == n)
		{
			ListElement* tmp = el->next;
			el->next = el->next->next;
			delete tmp;
			printf("Ёлемент успешно удален из списка.\n");
			return;
		}
		
		el = el->next;
	}

	printf("Ёлемента в списке нет.\n");
}

void deleteList(List* list)
{
	if (list->head == NULL)
		return;

	if (list->head->next == NULL)
	{
		delete list->head;
		return;
	}

	ListElement* el = list->head;

	while (el->next != NULL)
	{
		ListElement* tmp = el;
		el = el->next;
		delete tmp;
	}
}

Position end(List *l)
{
	if (l->head->next == NULL)
		return(l->head);

	ListElement*tmp = new ListElement;
	tmp = l -> head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return tmp;
}

Position prev(Position p, List *l)
{
	if (p == l->head)
		return NULL;

	ListElement*tmp = new ListElement;
	tmp = l->head;
	while (tmp->next != p)
		tmp = tmp->next;
	return tmp;
}

bool listEquals(List firstList, List secondList)
{
	ListElement* elementFirst = new ListElement;
	elementFirst = firstList.head;
	ListElement* elementSecond = new ListElement;
	elementSecond = secondList.head;

	while (elementFirst != NULL)
	{
		if (elementFirst->value != elementSecond->value)
			return false;
		else
		{
			elementFirst = elementFirst->next;
			elementSecond = elementSecond->next;
		}
	}
	return true;
}