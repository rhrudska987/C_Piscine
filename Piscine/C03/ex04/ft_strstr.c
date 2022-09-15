/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:50:35 by kyko              #+#    #+#             */
/*   Updated: 2022/09/01 20:45:09 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	to_find_len(char *to_find)
{
	int	len;

	len = 0;
	while (to_find[len])
		len++;
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = to_find_len(to_find);
	if (to_find[0] == 0)
		return (&str[0]);
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (++j < len)
			{
				if (str[i + j] != to_find[j])
					break ;
			}
			if (j == len)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
