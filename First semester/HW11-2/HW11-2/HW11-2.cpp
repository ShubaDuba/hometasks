#include <stdio.h>
#include "List.h"

int symbol(char tmp)
{
	if (tmp == '/')
		return 0;
	if (tmp == '*')
		return 1;
	return 2;
}

int check(int state, List* list, int mas[5][3], char tmp)
{
	switch(state)
	{
	case 0:
		if (tmp != '/')
			listReset(list);
		else
			addElement(list, tmp);

		break;

	case 1:
		if (tmp != '*')
			listReset(list);
		else
			addElement(list, tmp);
		
		break;

	case 2:
		addElement(list, tmp);
		
		break;

	case 3:
		addElement(list , tmp);
		
		break;

	case 4:
		printList(*list);
		printf("\n");
		listReset(list);

		break;
	}
	
	state = mas[state][symbol(tmp)];
	return state;
}

int main()
{
	FILE* g = fopen("input.txt", "r");
	FILE* f = fopen("states.txt", "r");
	int arr[5][3];
	int i = 0;

	while (!feof(f))
	{
		for (int j = 0; j < 3; j++)
		{
			fscanf(f, "%d", &arr[i][j]);
		}

		++i;
	}

	int state = 0;
	char ch = 'n';
	List list = createList();
	printf("Comments are: \n");

	while (!feof(g))
	{
		ch = fgetc(g);
		state = check(state, &list, arr, ch);
	}

	fclose(f);
	fclose(g);
	deleteList(&list);
	scanf("%*s");
	return 0;
}