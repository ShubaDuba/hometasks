#include "List.h"
#include <stdio.h>
#include <locale.h>

List createList()
{
	List tmpList;
	tmpList.head = NULL;
	tmpList.quantity = 0;
	return tmpList;
}

bool check(int method, ListElement* elementFromFirstList, ListElement* elementFromSecondList)
{
	if ((elementFromFirstList->value.phoneNumber <= elementFromSecondList->value.phoneNumber) && (method == '1') || (method =='2') && (strcmp(elementFromFirstList->value.name, elementFromSecondList->value.name)<= 0))
		return true;
	else
		return false;
}

void printList(List list)
{
	if (list.head == NULL)
		printf("Список пуст");
	ListElement* tmp = list.head;		

	while(tmp != NULL)
	{
		printf("%s ", tmp->value.name);
		printf("%d\n", tmp->value.phoneNumber);
		tmp = tmp->next;
	}

	printf("\n");
}

void addElement(List* list, Man value)
{
	++list->quantity;
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

position end(List *l)
{
	if (l->head->next == NULL)
		return(l->head);

	ListElement*tmp = new ListElement;
	tmp = l->head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return tmp;
}

position prev(position p, List *l)
{
	if (p == l->head)
		return NULL;

	ListElement*tmp = new ListElement;
	tmp = l->head;
	while (tmp->next != p)
		tmp = tmp->next;
	return tmp;
}

List mergeLists(List* firstList, List* secondList, char method)
{
	List result = createList();
	ListElement* elementFromFirstList = firstList->head;
	ListElement* elementFromSecondList = secondList->head;
	while(elementFromFirstList != NULL || elementFromSecondList != NULL)
		if (elementFromFirstList == NULL)
		{
			addElement(&result, elementFromSecondList->value);
			elementFromSecondList = elementFromSecondList->next;
		}
		else
			if (elementFromSecondList == NULL)
			{
				addElement(&result, elementFromFirstList->value);
				elementFromFirstList = elementFromFirstList->next;
			}
			else
			{
				if (check(method, elementFromFirstList, elementFromSecondList))
				{
					addElement(&result, elementFromFirstList->value);
					elementFromFirstList = elementFromFirstList->next;
				}
				else
				{
					addElement(&result, elementFromSecondList->value);
					elementFromSecondList = elementFromSecondList->next;
				}
			}
	delete elementFromFirstList;
	delete elementFromSecondList;
	return result;
}

void loadFromFile(FILE* f, List* list)
{
	list->quantity = 0;
	char* buffer = new char[100];
	if (f = fopen("Phonebook.txt", "a+"))
	{
		rewind(f);
		while (!feof(f))
		{

			while (fscanf(f, "%s ", buffer) != -1)
			{
				Man record;
				record.name = new char[20];
				strcpy(record.name, buffer);
				fscanf(f, "%d", &record.phoneNumber);
				addElement(list, record);							
			}			
		}
	}
	delete buffer;
}

List splitLists(List* listTmp)
{
	int n = listTmp->quantity;
	
	if (n == 1)
		return *listTmp;
	
	List result = createList();
	n = n / 2;
	int counter = 1;
	ListElement* tmp = listTmp->head;
	
	while (counter != n)
	{
		tmp = tmp->next;
		++counter;
	}

	result.head = tmp->next;
	result.quantity = listTmp->quantity - n;
	listTmp->quantity = n;
	tmp->next = NULL;
	return result;
}

List mergeSort(List* list, char option)
{
	if (list->quantity == 1)
		return *list;
 	List result = createList();
	List tmp = splitLists(list);
	return result = mergeLists(&mergeSort(list, option), &mergeSort(&tmp, option), option);
}