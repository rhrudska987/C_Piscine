/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:43:18 by kyko              #+#    #+#             */
/*   Updated: 2022/09/04 19:16:34 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_condition(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' ')
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

int	base_to_int(char *str, char *base, int *str_start, int *str_end)
{
	int	j;
	int	k;
	int	result;
	int	base_len;

	j = 0;
	result = 1;
	base_len = 0;
	while (base[base_len])
		base_len++;
	while (base[j++])
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

int	change_base(char *str, char *base, int *str_start)
{
	int	str_end;
	int	answer;

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

int	ft_atoi_base(char *str, char *base)
{
	int	answer;
	int	start;
	int	sign;

	answer = 0;
	start = 0;
	sign = 1;
	if (!check_condition(base))
		return (0);
	while (str[start] == ' ' || (str[start] >= 9 && str[start] <= 13))
		start++;
	while (str[start] == '-' || str[start] == '+')
	{
		if (str[start] == '-')
			sign *= -1;
		start++;
	}
	answer = change_base(str, base, &start);
	return (answer * sign);
}
