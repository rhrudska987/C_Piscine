/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:30:35 by kyko              #+#    #+#             */
/*   Updated: 2022/09/01 20:45:01 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	dst_len(char *dest)
{
	unsigned int	len;

	len = 0;
	while (dest[len])
		len++;
	return (len);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = dst_len(dest);
	while (src[i] && (i < nb))
		dest[len++] = src[i++];
	dest[len] = '\0';
	return (dest);
}
