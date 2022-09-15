/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:39:48 by kyko              #+#    #+#             */
/*   Updated: 2022/09/04 19:50:00 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	change_word(char *str, int d, int *first)
{
	if (str[d] >= 97 && str[d] <= 122)
	{
		if (*first == 1)
		{
			str[d] = str[d] - 32;
			*first = 0;
		}
	}
	else if (str[d] >= 65 && str[d] <= 90)
	{
		if (*first == 0)
			str[d] = str[d] + 32;
		else
			*first = 0;
	}
	else if (str[d] >= 48 && str[d] <= 57)
		*first = 0;
	else
		*first = 1;
}

char	*ft_strcapitalize(char *str)
{
	int	first;
	int	d;

	first = 0;
	d = 0;
	if ((str[d] >= 65 && str[d] <= 90) || (str[d] >= 97 && str[d] <= 122))
		first = 1;
	if (str[d] >= 48 && str[d] <= 57)
		first = 1;
	while (*(str + d))
	{
		change_word(str, d, &first);
		d++;
	}
	return (str);
}
