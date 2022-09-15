#include <stdio.h>
#include <stdlib.h>

int find_min(int a, int b, int c)
{
	int min = a;
	int i = 1;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

int main(void)
{
	char lines = 10;
	char empty = '.';
	char obstacle = 'o';
	char full = 'x';
	char board[10][15] = { {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}, {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}, {'.','.','.','.','o','.','.','.','.','.','.','.','.','.','.'}, {'.','.','.','.','.','.','.','.','.','.','.','.','.','o','.'}
	,{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}, {'.','.','.','.','o','.','.','.','.','.','.','.','.','.','.'}, {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}, {'.','.','.','.','.','.','.','o','.','.','.','.','.','.','.'}, {'.','.','o','.','.','.','.','.','.','.','o','.','.','.','.'} };
	int **dp;
	dp = (int **)malloc(sizeof(int*) * (lines));
	int i = 0;
	int j;
	while (i < lines)
	{
		dp[i] = (int *)malloc(sizeof(int) * 15);
		j = 0;
		while (j < 15)
		{
			if (board[i][j]== empty)
			{
				dp[i][j] = 1;
			}
			else if (board[i][j] == obstacle)
			{
				dp[i][j] = 0;
			}
			else
			{
				break;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i != 10)
	{
		j = 1;
		while (j != 15)
		{
			if (dp[i][j] != 0 && dp[i - 1][j] != 0 && dp[i][j - 1] != 0 && dp[i - 1][j - 1] != 0)
			{
				dp[i][j] = find_min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
			}
			j++;
		}
		i++;
	}
	int max = 0;
	int max_point_x = 0;
	int max_point_y = 0;
	i = 0;
	while (i != 10)
	{
		j = 0;
		while (j != 15)
		{
			if (dp[i][j] > max)
			{
				max = dp[i][j];
				max_point_x = i;
				max_point_y = j;
			}
			j++;
		}
		i++;
	}
	int count = 0;
	while (max >= 0)
	{
		count = max;
		i = max_point_x;
		j = max_point_y;
		int k = 1;
		board[i][j] = 'x';
		while (k < count)
		{
			board[i - k][j] = 'x';
			board[i][j - k] = 'x';
			k++;
		}
		max_point_x--;
		max_point_y--;
		max--;
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 15; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

	return (0);

}
