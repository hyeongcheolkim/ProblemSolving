//이차원배열을 동적할당으로 선언할경우, 정적할당으로 선언한 2차원배열과 달리 데이터들이 일직선상에 놓여있지 않게된다.

#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COLUMN 5 
int main()
{
	int** arr = (int**)malloc(sizeof(int*) * 3);
	for (int i = 0; i < ROW; i++)
		arr[i] = (int*)malloc(sizeof(int*) * COLUMN);

	for (int row = 0; row < ROW; row++)
		for (int column = 0; column < COLUMN; column++)
			arr[row][column] = row * 10 + column;

	for (int row = 0; row < ROW; row++)
	{
		for (int column = 0; column < COLUMN; column++)
			printf("%d\t", arr[row][column]);
		printf("\n");
	}

	for (int row = 0; row < ROW; row++)
	{
		for (int column = 0; column < COLUMN; column++)
			printf("%d\t", &arr[row][column]);
		printf("\n");
	}

	printf("arr:%d arr[0]:%d &arr[0]:%d &arr[0][0]:%d", arr, arr[0], &arr[0], &arr[0][0]);

	return 0;
}