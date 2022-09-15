/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmun <junmun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 06:10:15 by junmun            #+#    #+#             */
/*   Updated: 2022/09/10 06:13:56 by junmun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>

void				ft_show_tab(struct s_stock_str *par);
struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		printf("실행 시 인자를 1개 이상 넣어주세요. argc와 **argv를 받아 바로 ft_strs_to_tab에 전달합니다.");
		return (-1);
	}
	ft_show_tab(ft_strs_to_tab(ac, av));
}
