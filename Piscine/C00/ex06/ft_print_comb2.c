/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:50:19 by kyko              #+#    #+#             */
/*   Updated: 2022/08/28 12:46:44 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char a, char b)
{
	write(1, &a, 1);
	write(1, &b, 1);
}

void	int_to_char(int i, int max)
{
	char	first;
	char	second;

	if (i <= 9)
	{
		first = i + '0';
		put_char('0', first);
	}
	else if (i <= max)
	{
		first = (i / 10) + '0';
		second = (i % 10) + '0';
		put_char(first, second);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			int_to_char(i, 98);
			write(1, " ", 1);
			int_to_char(j, 99);
			if (i != 98 || j != 99)
				put_char(',', ' ');
			j++;
		}
		i++;
	}					
}
