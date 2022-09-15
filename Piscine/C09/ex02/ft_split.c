/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyko <kyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:51:08 by kyko              #+#    #+#             */
/*   Updated: 2022/09/11 16:01:56 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

int	is_cset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	word_cnt;
	int	i;

	word_cnt = 0;
	i = 1;
	while (str[i])
	{
		if (is_cset(str[i], charset) && !is_cset(str[i - 1], charset))
			word_cnt++;
		if (!is_cset(str[i], charset) && !str[i + 1])
			word_cnt++;
		i++;
	}
	return (word_cnt);
}

char	*put_word(char *str, int start, int end, char *charset)
{
	char	*ret;
	char	*tmp;

	if (is_cset(str[end], charset) && !is_cset(str[end -1], charset))
	{
		ret = (char *)malloc(end - start + 1);
		if (!ret)
			return (0);
		tmp = ret;
		while (start < end)
			*(tmp++) = str[start++];
	}
	else
	{
		ret = (char *)malloc(end - start + 2);
		if (!ret)
			return (0);
		tmp = ret;
		while (start <= end)
			*(tmp++) = str[start++];
	}
	*tmp = 0;
	return (ret);
}

char	**make_ret(char *str, char *charset, int start, int end)
{
	char	**ret;
	int		count;
	int		i;

	i = 0;
	count = word_count(str, charset);
	ret = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ret)
		return (0);
	while (str[++end] && count != 0)
	{
		if ((is_cset(str[end], charset) && !is_cset(str[end - 1], charset))
			|| (!is_cset(str[end], charset) && !str[end + 1]))
		{
			ret[i] = put_word(str, start, end, charset);
			i++;
			start = end + 1;
			while (is_cset(str[start], charset))
				start++;
		}
	}
	ret[i] = 0;
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	int		start;
	int		end;

	start = 0;
	while (is_cset(str[start], charset))
			start++;
	end = start - 1;
	return (make_ret(str, charset, start, end));
}
