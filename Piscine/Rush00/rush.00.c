/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:28 by kyko              #+#    #+#             */
/*   Updated: 2022/08/27 16:55:30 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	ft_putchar(char c);

void	print_edge(int point_x, int point_y, int x, int y)
{
	char	first_first;
	char	first_last;
	char	last_first;
	char	last_last;
	char	width;

	first_first = 'A';
	first_last = 'C';
	last_first = 'A';
	last_last = 'C';
	width = 'B';
	if (point_x == 0 && point_y == 0)
		ft_putchar(first_first);
	else if (point_x == x -1 && point_y == 0)
		ft_putchar(first_last);
	else if (point_x == 0 && point_y == y - 1)
		ft_putchar(last_first);
	else if (point_x == x - 1 && point_y == y - 1)
		ft_putchar(last_last);
	else
		ft_putchar(width);
}

void	print_line(int point_x, int point_y, int x, int y)
{
	char	height;

	height = 'B';
	if (point_x == 0 || point_x == x - 1)
		ft_putchar(height);
	else
		ft_putchar(' ');
}

int	check_error(int x, int y)
{
	if (x <= 0 || y <= 0)
		return (0);
	return (1);
}

void	rush(int x, int y)
{
	int		point_x;
	int		point_y;

	if (check_error(x, y))
	{
		point_x = 0;
		point_y = 0;
		while (point_y < y)
		{
			if (point_y == 0 || point_y == y - 1)
			{
				while (point_x < x)
					print_edge(point_x++, point_y, x, y);
			}
			else
			{
				while (point_x < x)
					print_line(point_x++, point_y, x, y);
			}
			ft_putchar('\n');
			point_x = 0;
			point_y++;
		}
	}
	else
		write(1, "E", 1);
}
