/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:49:05 by zbakkas           #+#    #+#             */
/*   Updated: 2024/09/04 14:44:59 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"

static int	get_inp_count(char **str)
{
	int	x;
	int	c;

	x = 0;
	c = 0;
	while (str[x])
	{
		if (!ft_strncmp(str[x], "<", 2) || !ft_strncmp(str[x], "<<", 3) || !ft_strncmp(str[x], ">", 2)|| !ft_strncmp(str[x], ">>", 3))
			c++;
		x++;
	}
	return (c);
}

static int	is_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

static void	get_inp_v(t_inp	*inp, int *c, int typ, char *str,char **envp)
{
	// printf("in=%s\n",str);
	if (typ == 4 && is_quote(str))
		inp[*c].is_q = true;
	else
		inp[*c].is_q = false;
	if (str && (!ft_strncmp(str, "<", 2) || !ft_strncmp(str, "<<", 3)||!ft_strncmp(str, ">", 2) || !ft_strncmp(str, ">>", 3)))
	{
		free(str);
		str = NULL;
	}
	if(typ != 4 && check_ambiguous(str,envp))
		inp[*c].is_am = true;
	else
		inp[*c].is_am = false;
	if(typ!=4)
		inp[*c].inp = whithout_q(change_var(str,envp),0);
	else
		inp[*c].inp = whithout_q(str,0);
	inp[*c].typ = typ;
	inp[*c].last = ft_strdup("1");
	(*c)++;
}
//> 1
//>> 2
//< 3
//<< 4

t_inp	*get_inp(char **str,char **envp)
{
	t_inp	*inp;
	int		x;
	int		c;

	inp = malloc((get_inp_count(str) + 1) * sizeof(t_inp));
	c = 0;
	x = 0;
	while (str[x])
	{
		if (!ft_strncmp(str[x], "<", 2) || !ft_strncmp(str[x], "<<", 3) || !ft_strncmp(str[x], ">", 2)|| !ft_strncmp(str[x], ">>", 3))
		{
			// printf("str+x=%s\n",str[x+1]);
			if (!ft_strncmp(str[x], ">", 2))
				get_inp_v(inp, &c, 1, str[x + 1],envp);
			else if (!ft_strncmp(str[x], ">>", 3))
				get_inp_v(inp, &c, 2, str[x + 1],envp);
			else if (!ft_strncmp(str[x], "<", 2))
				get_inp_v(inp, &c, 3, str[x + 1],envp);
			else if (!ft_strncmp(str[x], "<<", 3))
				get_inp_v(inp, &c, 4, str[x + 1],envp);
		}
		x++;
	}
	inp[c].last = NULL;
	inp[c].is_am = false;
	inp[c].inp = NULL;
	inp[c].typ = 0;
	return (inp);
}
