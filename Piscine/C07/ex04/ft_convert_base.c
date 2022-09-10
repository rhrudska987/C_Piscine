/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:52:46 by kyko              #+#    #+#             */
/*   Updated: 2022/09/10 22:57:36 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	change_base_to(char *ret, long long nbr, int base, char *str)
{
	if (!nbr)
	{
		*ret = 0;
		return ;
	}
	if (nbr < 0)
	{	
		*ret = '-';
		ret++;
		nbr *= -1;
	}
	change_base_to(ret + 1, (nbr / (long long)base), base, str);
	*ret = str[nbr % (long long)base];
}

void	printnbr_base(char *ret, long long nbr, char *base)
{
	int			len;
	int			flag;

	len = 0;
	flag = 0;
	while (base[len])
		len++;
	if (nbr < len && nbr >= 0)
	{
		ret[0] = base[nbr % len];
		ret[1] = 0;
	}
	else
		change_base_to(ret, nbr, len, base);
}

void	swap(char *s1, char *s2)
{
	char	temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

char	*ft_putnbr_base(long long nbr, char *base)
{
	char	*ret;
	char	*tmp;
	int		len;
	int		index;
	int		flag;

	len = 0;
	index = -1;
	flag = 0;
	ret = (char *)malloc(40);
	tmp = ret;
	if (!ret)
		return (0);
	if (nbr < 0)
		flag = 1;
	printnbr_base(ret, nbr, base);
	while (*tmp)
	{
		len++;
		tmp++;
	}
	index += flag;
	while (++index < len / 2 + flag)
		swap(&ret[index], &ret[len - 1 - index + flag]);
	return (ret);
}
