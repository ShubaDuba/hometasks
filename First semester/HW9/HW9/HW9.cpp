#include <stdio.h>
#include <locale.h>

bool allOwned(bool a[], int n)
{
	for (int h = 0; h < n; ++h)
	{
		if (a[h] == false)
			return false;
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* file = fopen("input.txt", "r");
	int n = 0;
	int m = 0;
	fscanf(file, "%d", &n);
	fscanf(file, "%d", &m);
	
	int** roadLengths = new int*[n];

	for (int i = 0; i < n; ++i)
		roadLengths[i] = new int[n];
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			roadLengths[i][j] = 0;
	}
	
	int maxLength = 0;
	
	for (int p = 0; p < m; ++p)
	{
		int i = 0;
		int j = 0;
		int length = 0;
		fscanf(file, "%d", &i);
		fscanf(file, "%d", &j);
		fscanf(file, "%d", &length);
		roadLengths[i][j] = length;
		roadLengths[j][i] = length;

		if (roadLengths[i][j] > maxLength)
			maxLength = roadLengths[i][j];
	}
	
	bool* cityOwned = new bool[n];
	
	for (int p = 0; p < n; ++p)
		cityOwned[p] = false;

	int k = 0;
	fscanf(file, "%d", &k);
	int** countries = new int*[k];
	
	for (int p = 0; p < n; ++p)
		countries[p] = new int[n];
	
	for (int p = 0; p < k; ++p)
	{
		for (int s = 0; s < n; ++s)
			countries[p][s] = -1;
	}
	
	for (int p = 0; p < k; ++p)
	{
		int tmp = 0;
		fscanf(file, "%d", &tmp);
		cityOwned[tmp] = true;
		countries[p][0] = tmp;
	}	
	
	while (!allOwned(cityOwned, n))
	{
		for (int i = 0; i < k; ++i)
		{
			int minRoad = maxLength + 1;
		    int tmp = 0;
			int cityNumber = -1;

			while (countries[i][tmp] != -1)
			{
				for (int j = 0; j < n; ++j)
					if ((roadLengths[j][countries[i][tmp]] < minRoad) && (roadLengths[j][countries[i][tmp]] != 0) && (!cityOwned[j]))
					{
						minRoad = roadLengths[j][countries[i][tmp]];
						cityNumber = j;
					}
				++tmp;
			}

			tmp = 0;
			
			if (cityNumber != -1)
			{
				while (countries[i][tmp] != -1)
					++tmp;
				
				countries[i][tmp] = cityNumber;
				cityOwned[cityNumber] = true;
			}

			if (allOwned(cityOwned, n))
				break;//... PROFIT!
		}
	}

	for (int i = 0; i < k; ++i)
	{
		printf("%d", i + 1);
		printf("ая страна: ");

		for (int j = 0; j < n; ++j)
		{
			if (countries[i][j] != -1)
				printf("%d ", countries[i][j]);
		}

		printf("\n");
	}

	for (int i = 0; i < n; i++)
		delete[] roadLengths[i];

	delete[] roadLengths;

	for (int i = 0; i < k; i++)
        delete[] countries[i];

	delete[] cityOwned;
	fcloseall();
	scanf("%*s");
	return 0;
}