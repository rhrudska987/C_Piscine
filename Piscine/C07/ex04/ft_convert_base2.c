/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:34:23 by kyko              #+#    #+#             */
/*   Updated: 2022/09/10 22:59:00 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern char	*ft_putnbr_base(long long nbr, char *base);
extern void	swap(char *s1, char *s2);
extern void	printnbr_base(char *ret, long long nbr, char *base);
extern int	check_base_to(char *base);
extern void	change_base_to(char *ret, long long nbr, int base, char *str);

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
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

long long	base_to_int(char *str, char *base, int *str_start, int *str_end)
{
	int			j;
	int			k;
	long long	result;
	int			base_len;

	j = -1;
	result = 1;
	base_len = 0;
	while (base[base_len])
		base_len++;
	while (base[++j])
	{
		if (str[*str_start] == base[j])
		{
			k = 0;
			while (k++ < *str_end - *str_start - 1)
				result *= base_len;
			if (0 == *str_end - *str_start - 1)
				return (j);
			result = j * result;
			return (result);
		}
	}
	return (0);
}

int	end_check(char *str, char *base, int str_end)
{
	int	i;
	int	flag;

	while (str[str_end])
	{
		i = 0;
		flag = 0;
		while (base[i])
		{
			if (str[str_end] == base[i])
			{
				flag = 1;
				break ;
			}
			i++;
		}
		if (flag == 0)
			break ;
		str_end++;
	}
	return (str_end);
}

long long	change_base_from(char *str, char *base, int *str_start)
{
	int			str_end;
	long long	answer;

	answer = 0;
	str_end = *str_start;
	str_end = end_check(str, base, str_end);
	while (*str_start < str_end)
	{
		answer += base_to_int(str, base, str_start, &str_end);
		*str_start = *str_start + 1;
	}
	return (answer);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	ret;
	int			start;
	int			sign;

	start = 0;
	sign = 1;
	if ((!check_base(base_from)) || (!check_base(base_to)))
		return (0);
	while (nbr[start] == ' ' || (nbr[start] >= 9 && nbr[start] <= 13))
		start++;
	while (nbr[start] == '-' || nbr[start] == '+')
	{
		if (nbr[start] == '-')
			sign *= -1;
		start++;
	}
	ret = change_base_from(nbr, base_from, &start) * sign;
	return (ft_putnbr_base(ret, base_to));
}
