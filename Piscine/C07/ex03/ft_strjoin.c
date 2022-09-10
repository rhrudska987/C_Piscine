/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 23:04:48 by kyko              #+#    #+#             */
/*   Updated: 2022/09/10 22:28:56 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long long	ft_strlen(char *str)
{
	long long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	return (dest);
}

char	*paste_tmp(char *tmp, char *sep, char **strs, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		tmp = ft_strcat(tmp, sep);
		tmp = ft_strcat(tmp, strs[i]);
		i++;
	}
	return (tmp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	long long	len;
	int			i;
	char		*ret;
	char		*tmp;

	if (!size)
	{
		ret = (char *)malloc(sizeof(char) * 1);
		if (!ret)
			return (0);
		ret[0] = 0;
		return (ret);
	}
	i = -1;
	len = 0;
	while (++i < size)
		len += ft_strlen(strs[i]);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(sep) * (size -1) + len + 1));
	if (!ret)
		return (0);
	tmp = ft_strcat(ret, strs[0]);
	tmp = paste_tmp(tmp, sep, strs, size);
	*tmp = 0;
	return (ret);
}
