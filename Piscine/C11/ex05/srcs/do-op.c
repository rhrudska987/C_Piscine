/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:23:11 by kyko              #+#    #+#             */
/*   Updated: 2022/09/15 22:27:57 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	sum(int a, int b);
int	sub(int a, int b);
int	mul(int a, int b);
int	div(int a, int b);
int	mod(int a, int b);

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
			result = (result * 10) + (*(str++) - '0');
		else
			break ;
	}
	return (result * sign);
}

void	print_num(int num)
{
	char	c;

	if (!num)
	{
		return ;
	}
	print_num(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
}

void	check_zero(char c)
{
	if (c == '/')
		write(1, "Stop : division by zero\n", 24);
	else if (c == '%')
		write(1, "Stop : modulo bt zero\n", 22);
}

int	check_condition(char **argv, int (*fp[5])(int, int))
{
	int	result;

	result = 0;
	if (argv[2][0] == '+')
		result = fp[0](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argv[2][0] == '-')
		result = fp[1](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argv[2][0] == '*')
		result = fp[2](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argv[2][0] == '/')
		result = fp[3](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argv[2][0] == '%')
		result = fp[4](ft_atoi(argv[1]), ft_atoi(argv[3]));
	return (result);
}

int	main(int argc, char **argv)
{
	int	result;
	int	(*fp[5])(int, int);

	fp[0] = sum;
	fp[1] = sub;
	fp[2] = mul;
	fp[3] = div;
	fp[4] = mod;
	result = 0;
	if (argc == 4)
	{
		if (argv[3][0] == '0' && (argv[2][0] == '/' || argv[2][0] == '%'))
		{
			check_zero(argv[2][0]);
			return (0);
		}
		else
			result = check_condition(argv, fp);
		if (result == 0)
			write(1, "0", 1);
		else
			print_num(result);
		write(1, "\n", 1);
	}
	return (result);
}
