/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:23:31 by kyko              #+#    #+#             */
/*   Updated: 2022/09/04 13:12:38 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	change_base(long long nbr, int base, char *str)
{
	if (!nbr)
		return ;
	change_base((nbr / base), base, str);
	write(1, &str[nbr % base], 1);
}

int	check_condition(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	printnbr_base(int nbr, char *base)
{
	long long	long_nbr;
	int			len;

	long_nbr = (long long)nbr;
	len = 0;
	while (base[len])
		len++;
	if (long_nbr < len && long_nbr >= 0)
		write(1, &base[long_nbr % len], 1);
	else
	{
		if (long_nbr < 0)
		{
			write(1, "-", 1);
			long_nbr *= -1;
		}
		change_base(long_nbr, len, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	check;

	check = check_condition(base);
	if (check)
		printnbr_base(nbr, base);
}
