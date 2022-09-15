/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:32:54 by kyko              #+#    #+#             */
/*   Updated: 2022/08/31 13:26:33 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr_non_printable(char *str)
{
	int				index;
	unsigned char	*s;

	s = (unsigned char *)str;
	index = 0;
	while (s[index])
	{
		if (s[index] >= 32 && s[index] <= 126)
			write(1, &s[index], 1);
		else
		{
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[s[index] / 16], 1);
			write(1, &"0123456789abcdef"[s[index] % 16], 1);
		}
		index++;
	}
}
