/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:49:38 by kyko              #+#    #+#             */
/*   Updated: 2022/09/06 14:12:16 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_queens(int pos_row[][10])
{
	int			i;
	char		c;

	i = 0;
	while (i < 10)
	{
		c = pos_row[0][i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	counting(int *count, int pos_row[][10])
{
	*count = *count + 1;
	print_queens(pos_row);
}

int	ten_queens(int i, int *count, int pos_row[][10], int diagonal[][19])
{
	int			j;

	j = 0;
	while (j < 10)
	{
		if (!pos_row[1][j] && !diagonal[0][i + j] && !diagonal[1][i - j + 9])
		{
			pos_row[0][i] = j;
			if (i == 9)
				counting(count, pos_row);
			else
			{
				pos_row[1][j] = 1;
				diagonal[0][i + j] = 1;
				diagonal[1][i - j + 9] = 1;
				ten_queens(i + 1, count, pos_row, diagonal);
				pos_row[1][j] = 0;
				diagonal[0][i + j] = 0;
				diagonal[1][i - j + 9] = 0;
			}
		}
		j++;
	}
	return (*count);
}

int	ft_ten_queens_puzzle(void)
{
	int	pos_row[2][10];
	int	diagonal[2][19];
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 10)
	{
		pos_row[0][i] = 0;
		pos_row[1][i] = 0;
		i++;
	}
	i = 0;
	while (i < 19)
	{
		diagonal[0][i] = 0;
		diagonal[1][i] = 0;
		i++;
	}
	return (ten_queens(0, &count, pos_row, diagonal));
}
