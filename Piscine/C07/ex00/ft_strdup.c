/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:44:32 by kyko              #+#    #+#             */
/*   Updated: 2022/09/09 21:43:52 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	long long	len;
	char		*str;

	len = 0;
	while (src[len])
		len++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = 0;
	while (--len >= 0)
		str[len] = src[len];
	return (str);
}
