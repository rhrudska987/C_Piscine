/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:49:05 by kyko              #+#    #+#             */
/*   Updated: 2022/09/01 20:44:55 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	destination_len(char *dest)
{
	int	len;

	len = 0;
	while (dest[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	len = destination_len(dest);
	i = 0;
	while (src[i])
		dest[len++] = src[i++];
	dest[len] = '\0';
	return (dest);
}
