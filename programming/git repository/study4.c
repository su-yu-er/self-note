#include<stdio.h>

void print2(int(*p)[3], int x, int y)
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			//printf("%d ", *(*(p + i) + j));
			//printf("%d ", (*(p + i))[j]);
			printf("%d ", *(p[i]+j));
			//printf("%d ", p[i][j]);


		}
		printf("\n");
	}
}

int main()
{
	int arr[3][3] = { {1,2,3},{2,3,4},{3,4,5} };
	print2(arr, 3, 3);
	return 0;
}
