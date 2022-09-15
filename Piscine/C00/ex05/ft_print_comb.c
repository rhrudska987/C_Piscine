/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:45:16 by kyko              #+#    #+#             */
/*   Updated: 2022/08/25 16:39:16 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

int	check_last(char a, char b, char c)
{
	if (a == '7' && b == '8' && c == '9')
	{
		return (0);
	}
	return (1);
}

void	print_number(char a, char b, char c)
{
	put_char(a);
	put_char(b);
	put_char(c);
	if (check_last(a, b, c))
	{
		put_char(',');
		put_char(' ');
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	b = '0';
	c = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				print_number(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
