/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:44:26 by kyko              #+#    #+#             */
/*   Updated: 2022/08/31 13:37:44 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	put_hex(unsigned char *str, unsigned int i, unsigned int size)
{
	const char		*hex_arr = "0123456789abcdef";
	char			c1;
	char			c2;
	unsigned int	k;

	k = i + 16;
	write(1, ":", 1);
	while (i < k)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i > size - 1)
			write(1, "  ", 2);
		else
		{
			c1 = hex_arr[str[i] / 16];
			write(1, &c1, 1);
			c2 = hex_arr[str[i] % 16];
			write(1, &c2, 1);
		}
		i++;
	}
}

void	put_str(unsigned char *str, unsigned int i, unsigned int size)
{
	unsigned int	l;

	l = i;
	i += 16;
	write(1, " ", 1);
	while (l < i)
	{
		if (l > size -1)
			break ;
		if (str[l] < 32 || str[l] > 126)
			write(1, ".", 1);
		else
			write(1, &str[l], 1);
		l++;
	}
	write(1, "\n", 1);
}

void	put_addr(unsigned long long tmp)
{
	char		print_addr[17];
	const char	*hex_arr = "0123456789abcdef";
	int			k;

	k = 0;
	while (k < 16)
	{
		print_addr[k++] = hex_arr[tmp % 16];
		tmp /= 16;
	}
	while (--k >= 0)
		write(1, &print_addr[k], 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long long	tmp;
	unsigned int		i;
	unsigned char		*str;
	unsigned char		*ptr;

	i = 0;
	str = (unsigned char *)addr;
	while (i < size)
	{
		tmp = (unsigned long long)addr + i;
		ptr = (unsigned char *)tmp;
		put_addr(tmp);
		put_hex(str, i, size);
		put_str(str, i, size);
		i += 16;
	}
	return (addr);
}
