/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:19:02 by kyko              #+#    #+#             */
/*   Updated: 2022/09/09 21:47:21 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			*nums;
	int			i;
	long long	size;
	long long	a;
	long long	b;

	a = (long long)max;
	b = (long long)min;
	i = 0;
	size = a - b;
	if (b >= a)
	{
		*range = 0;
		return (0);
	}
	nums = (int *)malloc(sizeof(int) * size);
	if (!nums)
		return (-1);
	while (b < a)
		nums[i++] = b++;
	*range = nums;
	return (size);
}
