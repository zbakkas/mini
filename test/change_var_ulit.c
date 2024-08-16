/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_var_ulit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:23:37 by zbakkas           #+#    #+#             */
/*   Updated: 2024/08/16 19:46:39 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"

char	*search_in_env(char **envp, char *str)
{
	int	x;
	int	l;

	x = 0;
	l = ft_strlen(str);
	while (envp[x])
	{
		if (ft_strnstr(envp[x], str, l) && envp[x][l] && envp[x][l] == '=')
		{
			return (ft_strnstr(envp[x], str, l) + l + 1);
		}
		x++;
	}
	return (NULL);
}

static int	get_name_var_count(char *str)
{
	char	*re;
	int		x;
	int		is_v;
	int		i;

	x = 0;
	is_v = 0;
	i = 0;
	while (str[x])
	{
		if (is_v)
		{
			if (str[x] == '\n' || is_sp(str[x]) || str[x] == '\''
				|| str[x] == '"' || str[x] == '$' )
				break ;
			i++;
		}
		if (str[x] == '$')
			is_v = 1;
		x++;
	}
	return (i);
}

char	*get_name_var(char *str, int *j)
{
	char	*re;
	int		x;
	int		is_v;
	int		i;

	x = 0;
	is_v = 0;
	i = 0;
	re = malloc(get_name_var_count(str) + 1);
	while (str[x])
	{
		if (is_v)
		{
			if (!ft_isalpha(str[x]) && !ft_isdigit(str[x]) && str[x] != '_')
				break ;
			re[i++] = str[x];
			(*j)++;
			if (ft_isdigit(str[x]) && str[x - 1] == '$')
				break ;
		}
		if (str[x] == '$')
			is_v = 1;
		x++;
	}
	return (re[i] = '\0', (re));
}
