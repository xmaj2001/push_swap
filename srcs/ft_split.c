/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:33:30 by mefernan          #+#    #+#             */
/*   Updated: 2024/08/15 12:47:35 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	word_counter(const char *str, char c)
{
	int	flag;
	int	counter;

	flag = 0;
	counter = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			counter++;
			flag = 1;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (counter);
}

static char	*word_dup(const char *str, int start, int finish)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * ((finish - start) + 1));
	if (!word)
		return (NULL);
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	check(int num_w)
{
	if (!num_w)
		return ;
}

char	**ft_split(char const *str, char c)
{
	int		index;
	int		num_w;
	size_t	j;
	size_t	i;
	char	**split;

	num_w = word_counter(str, c);
	check(num_w);
	split = (char **)malloc(sizeof(char *) * (num_w + 1));
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(str))
	{
		if (str[i] != c && index < 0)
			index = i;
		else if ((str[i] == c || i == ft_strlen(str)) && index >= 0)
		{
			split[j++] = word_dup(str, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
