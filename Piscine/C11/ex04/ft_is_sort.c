/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 04:55:35 by kyko              #+#    #+#             */
/*   Updated: 2022/09/14 15:53:29 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_sorting1(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	count;
	int	sorting;

	i = -1;
	sorting = 1;
	while (++i < length - 1)
	{
		count = 0;
		j = i;
		while (++j < length)
		{
			if ((*f)(tab[i], tab[j]) >= 0)
				count++;
		}
		if (count != length - 1 - i)
		{
			sorting = 0;
			break ;
		}
	}
	if (sorting)
		return (1);
	return (0);
}

int	check_sorting2(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	count;
	int	sorting;

	i = -1;
	sorting = 1;
	while (++i < length - 1)
	{
		count = 0;
		j = i;
		while (++j < length)
		{
			if ((*f)(tab[i], tab[j]) <= 0)
				count++;
		}
		if (count != length - 1 - i)
		{
			sorting = 0;
			break ;
		}
	}
	if (sorting)
		return (1);
	return (0);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (length <= 1)
		return (1);
	if (check_sorting1(tab, length, f)
		|| check_sorting2(tab, length, f))
		return (1);
	return (0);
}
