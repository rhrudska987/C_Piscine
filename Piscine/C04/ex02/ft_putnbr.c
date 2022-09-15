/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:45:05 by kyko              #+#    #+#             */
/*   Updated: 2022/09/01 19:48:51 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	number_length(int nb)
{
	int	count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

void	positive(int nb)
{
	int		len;
	int		digit;
	int		share;
	char	c;

	len = number_length(nb);
	digit = 1;
	while (len > 1)
	{
		digit *= 10;
		len--;
	}
	while (digit > 0)
	{
		share = nb / digit;
		nb %= digit;
		c = share + 48;
		write(1, &c, 1);
		digit /= 10;
	}
}

void	negative(int nb)
{
	int		len;
	int		digit;
	int		share;
	char	c;

	write(1, "-", 1);
	len = number_length(nb);
	digit = 1;
	while (len > 1)
	{
		digit *= 10;
		len--;
	}
	while (digit > 0)
	{
		share = nb / digit;
		nb %= digit;
		c = share + 48;
		write(1, &c, 1);
		digit /= 10;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		nb = nb * -1;
		negative(nb);
	}
	else if (nb > 0)
	{
		positive(nb);
	}
	else
	{
		write(1, "0", 1);
	}
}
