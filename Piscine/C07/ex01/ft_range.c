/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:08:35 by kyko              #+#    #+#             */
/*   Updated: 2022/09/09 21:46:48 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			i;
	int			*nums;
	long long	a;
	long long	b;
	long long	size;

	a = (long long)max;
	b = (long long)min;
	size = a - b;
	i = 0;
	if (min >= max)
		return (0);
	nums = (int *)malloc(sizeof(int) * (size));
	if (!nums)
		return (0);
	while (b < a)
	{
		nums[i] = b;
		i++;
		b++;
	}
	return (nums);
}
