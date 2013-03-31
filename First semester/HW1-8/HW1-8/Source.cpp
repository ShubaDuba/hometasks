#include <stdio.h>
#include <string.h>


int main()
{
	char* str = "Hello World lol";
	char* tmpstr = "lo";
	int count = 0;
	for (int i = 0; i < strlen(str); ++i)
	{
		if (str[i] == tmpstr[0])
		{
			bool tmp = true;
			for (int j = 0; j < strlen(tmpstr); ++j)
			{
				if (str[i + j] != tmpstr[j])
					tmp = false;
			}
			if (tmp)
				++count;
		}
	}

	printf("%d", count);
	scanf("%*s");
	return 0;
}