/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:20:58 by kyko              #+#    #+#             */
/*   Updated: 2022/09/13 22:28:27 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != 0 && *s2 != 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	word_count(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		count;
	char	*tmp;

	count = word_count(tab);
	i = count;
	while (--i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
	}
}
