#include <string.h>
#include <locale.h>
#include <stdio.h>

struct Man
{
	int phoneNumber;
	char* name;
};

struct PhoneBook
{
	Man* data;
	int amount;
};

void loadFromFile(FILE* f, PhoneBook* book)
{
	book->amount = 0;
	char* tmp = new char[100];
	book->data = new Man[100];
	if (f = fopen("PhoneBook.txt", "a+"))
	{
		rewind(f);
	
		while (!feof(f))
		{

			while (fscanf(f, "%s ", tmp) != -1)
			{
				book->data[book->amount].name = new char[20];
				strcpy(book->data[book->amount] . name, tmp);
				fscanf(f, "%d", &book->data[book->amount].phoneNumber);
				++book->amount;							
			}			
		}
	}
}

void show(PhoneBook tmp)
{
	for (int i = 0; i < tmp.amount; ++i)
	{
		printf("%s ", tmp.data[i].name);
		printf("%d\n", tmp.data[i].phoneNumber);
	}
}

void addRecordToBook(PhoneBook* tmp)
{
	printf("Введите имя\n");
	tmp->data[tmp->amount].name = new char[20];
	scanf("%s", tmp->data[tmp->amount].name);
	printf("Введите номер\n");
	scanf("%d", &tmp->data[tmp->amount].phoneNumber);
	tmp->amount = tmp->amount + 1;
}

void saveToFile(PhoneBook tmp, FILE* file)
{
	file = fopen("PhoneBook.txt", "w+");
	
	for (int i = 0; i < tmp.amount; ++i)
		fprintf(file, "\n%s %d", tmp.data[i].name, tmp.data[i].phoneNumber);
}

void searchPhoneNumberByName(PhoneBook tmp)
{
	char* name = new char[20];
	printf("Введите имя:\n");
	scanf("%s", name);

	printf("Найденные номера:\n");
	
	for (int i = 0; i < tmp.amount; ++i)
	{
		if (strcmp(tmp.data[i].name, name) == 0)
			printf("%d\n", tmp.data[i].phoneNumber);
	}
}

void searchNameByPhoneNumber(PhoneBook tmp)
{
	printf("Введите номер\n");
	int num = 0;
	scanf("%d", &num);
	printf("Найденые имена:\n");

	for (int i = 0; i < tmp.amount; ++i)
	{
		if (tmp.data[i].phoneNumber == num)
			printf("%s\n", tmp.data[i].name);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* file = fopen("PhoneBook.txt", "a+");
	PhoneBook phones;
	loadFromFile(file, &phones);
	char* str = new char[20];
	while (strcmp(str, "0") != 0)
	{
		scanf("%s", str);
		if (strcmp(str, "1") == 0)
			addRecordToBook(&phones);
		if (strcmp(str, "2") == 0)
			searchPhoneNumberByName(phones);
		if (strcmp(str, "3") == 0)
			searchNameByPhoneNumber(phones);
		if (strcmp(str, "4") == 0)
		{
			saveToFile(phones, file);
			show(phones);
		}
	}
	fclose(file);
	return 0;
}