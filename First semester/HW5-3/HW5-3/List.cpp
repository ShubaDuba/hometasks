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
		printf("Список пуст");
	ListElement* tmp = list.head;		

	while (tmp != NULL)
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

	ListElement* el = list->head;
	
	while (el->next != NULL)
	{
		el = el->next;
	}
	
	el->next = tmp;
}

void deleteElement(List* list, int n)
{
	if (list->head == NULL)
		return;
	
	ListElement* el = list->head;

	if (el->value == n)
	{
		ListElement* tmp = list->head;
		end(list)->next = el->next;
		list->head = el->next;
		delete tmp;
		return;
	}

	while (el->next != list->head)
	{
		if (el->next->value == n)
		{
			ListElement* tmp = el->next;
			el->next = el->next->next;
			delete tmp;
			return;
		}
		
		el = el->next;
	}
}

void deleteList(List* list)
{
	if (list->head == NULL)
		return;

	if (list->head->next == list->head)
	{
		delete list->head;
		return;
	}

	ListElement* el = list->head;

	while (el->next != list->head)
	{
		ListElement* tmp = el;
		el = el->next;
		delete tmp;
	}
}

position end(List *l)
{
	if (l->head->next == l->head)
		return(l->head);

	ListElement*tmp = new ListElement;
	tmp = l->head;
	while (tmp->next != l->head)
		tmp = tmp->next;
	return tmp;
}

position prev(position p, List *l)
{
	if (p == l->head)
		return l->head;

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