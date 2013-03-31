#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* file = fopen("input.txt", "r");
	int n = 0;
	fscanf(file, "%d", &n);
	int** matrix = new int*[n];

	for (int i = 0; i < n; ++i)
		matrix[i] = new int[n];

	for (int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			fscanf(file, "%d", &matrix[i][j]);
	
	const int INF = 1000000000;

	bool* used = new bool[n];		
	int* minEdge = new int[n];
	int* endOfMinEdge = new int [n];
	
	for (int i = 0; i < n; ++i)
	{
		used[i] = 0;
		minEdge[i] = INF;
		endOfMinEdge[i] = -1;
	}
	
	minEdge[0] = 0;
	for (int i = 0; i < n; ++i) 
	{
		int vertex = -1;
		for (int j = 0; j < n; ++j)
			if (!used[j] && (vertex == -1 || minEdge[j] < minEdge[vertex]))
				vertex = j;
		
		if (minEdge[vertex] == INF)
			printf("Нет основного дерева, лол");
 
		used[vertex] = true;
		
		if (endOfMinEdge[vertex] != -1)
			printf("%d %d\n", vertex, endOfMinEdge[vertex]);
 
		for (int j = 0; j < n; ++j)
			if (matrix[vertex][j] < minEdge[j])
			{
				minEdge[j] = matrix[vertex][j];
				endOfMinEdge[j] = vertex;
			}
	}
	
	for (int i = 0; i < n; ++i)
		delete[] matrix[i];
	
	delete[] endOfMinEdge;
	delete[] matrix;
	delete[] minEdge;
	fcloseall();
	scanf("%*s");
	return 0;
}