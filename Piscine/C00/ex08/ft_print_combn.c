/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:59:28 by kyko              #+#    #+#             */
/*   Updated: 2022/08/29 21:12:51 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	depth_first_search(int n, int d, int start, char nums[])
{
	int	i;

	i = start + 1;
	if (n == d)
	{
		write(1, nums, n);
		if (nums[0] == '9' - n + 1)
			return ;
		write(1, ", ", 2);
		return ;
	}
	while (i < 10)
	{
		nums[d] = i + '0';
		depth_first_search(n, d + 1, i, nums);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	nums[10];

	depth_first_search(n, 0, -1, nums);
}
