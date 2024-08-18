/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_var_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:27:17 by zbakkas           #+#    #+#             */
/*   Updated: 2024/08/18 17:28:16 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"

// $? g_exit_status
static int	change_var_count_one(int *x)
{
	char	*str;
	int		i;

	str = ft_itoa(g_exit_status);
	i = ft_strlen(str);
	(*x)++;
	free(str);
	return (i);
}

static int	change_var_count_tow(char **envp, int *x, char *str)
{
	int		j;
	char	*var;
	int		i;
	char	*ss;

	ss = get_name_var(str + *x, x);
	var = search_in_env(envp, ss);
	i = 0;
	free(ss);
	i += ft_strlen(var);
	j = 0;
	return (i);
}

int	change_var_count(char *str, char **envp)
{
	int		x;
	int		i;
	int		l;
	t_quote	q;

	q.inDoubleQuote = 0;
	q.inSingleQuote = 0;
	x = -1;
	i = 0;
	while (str[++x])
	{
		l = chacke_q(str[x], &q);
		if (str[x] == '$' && l != 1 && str[x + 1]
			&& !is_sp(str[x + 1]) && str[x + 1] != '$')
		{
			if (str[x + 1] == '?')
				i = i + change_var_count_one(&x);
			else if (!(is_sp(str[x + 1]) || str[x + 1] == '\''
					|| str[x + 1] == '"'))
				i = i + (change_var_count_tow(envp, &x, str) + 2);
		}
		else
			i++;
	}
	return (i);
}
