#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
 
using namespace std;

bool stringIsEmpty(string tmp)
{
	for (unsigned int i = 0; i < tmp.length(); ++i)
	{
		if (tmp[i] != ' ' && tmp[i] != '\n')
			return false;
	}

	return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
	ifstream file("input.in");
 
    string line = "";
    int linesCount = 0;
    while (getline(file, line))
    {
        if (!stringIsEmpty(line))
			linesCount++;
    }
 
    printf("Непустых линий: %d", linesCount);
	scanf("%*s");
    return 0;
}