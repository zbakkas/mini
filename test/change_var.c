/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:45:21 by zbakkas           #+#    #+#             */
/*   Updated: 2024/08/20 14:47:26 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"
int check_afte(char *str, int x, int c)
{
	int i =0;
	
	while (x >=0)
	{
		if(is_sp(str[x]))
			break;
		if(str[x]=='$')
			i++;
			x--;
	}
	
	if(i == c &&  str[x+1] !='"'&&  str[x+1] !='\'')
		return (1);
	return (0);
}

static int	check_erroe_var(char *var, int j, t_args_var *args, char *str)
{
	int	ll;
	int	k;
	int c;

	c = 0;
	ll = - 1;
	k = 0;
	while (var && var[++ll] && !k)
		if (is_sp(var[ll]))
			k = 1;
	ll = j;
	if (args->l != 2 && str[j])
	{
		while (ll > 0)
		{
			ll--;
			if ((str[ll] == '>' || str[ll] == '<' ))
			{
				printf("var=%s,>=%c,<=%c|\n",var,str[args->x + 1],str[j-1]);
				
				if(str[args->x + 1]=='$')
					args->c_var++;
				
				printf("d=%d\n",args->c_var);
				if ((!var || !var[0] || k) && (is_sp(str[args->x + 1]) || !str[args->x + 1])&& (is_sp(str[j-1]) || check_afte(str,j-1, args->c_var)))
					return (1);
			}
			while ((ll>0 &&!is_sp(str[ll]) &&str[ll] != '>' && str[ll] != '<'))
				ll--;
			if (!is_sp(str[ll]))
				break ;
		}
	}
	return (0);
}

//$? g_exit_status
static void	change_var_one(int *x, char *re, int *i)
{
	char	*str;
	int		a;

	str = ft_itoa(g_exit_status);
	a = 0;
	while (str[a])
	{
		re[(*i)++] = str[a++];
	}
	free(str);
	(*x)++;
}

static void change_var_tow(t_args_var *args,char *str,int *err,char **envp)
{
	int		j;
	char	*ss;
	char	*var;

	j = args->x;
	ss = get_name_var(str + args->x, &(*args).x);
	// printf("j=%d,x=%d,j+len=%d\n",j,(*args).x,j+ (ft_strlen(ss)));
	var = search_in_env(envp, ss);
	// if (!(*err))
	
	*err = check_erroe_var(var, j, args, str);
	free(ss);
	j = 0;
	if (var && var[j] && args->l != 2)
		args->re[args->i++] = '"';
	while (var && var[j])
	{
		if (j - 1 >= 0 && args->l != 2 && is_sp(var[j - 1]) && !is_sp(var[j]))
			args->re[args->i++] = '"';
		args->re[args->i++] = var[j];
		if (args->l != 2 && !is_sp(var[j]) && (is_sp(var[j + 1])
				|| var[j + 1] == '\0'))
			args->re[args->i++] = '"';
		j++;
	}
}

// cat << $USER stoop in $USER not value of $USER
static int	check_and_her_var(char *str, int x, t_args_var args)
{
	int	l;

	l = 0;
	while (x >= 0)
	{
		while (x >= 0 && (is_sp(str[x])))
		{
			x--;
		}
		if (x >= 0 && str[x] == '<' && x - 1 >= 0 && str[x - 1] == '<')
			l = 1;
		x--;
	}
	if (!l && str[args.x] == '$' && args.l != 1 && str[args.x + 1]
		&& !is_sp(str[args.x + 1]) && str[args.x + 1] != '$')
		return (1);
	return (0);
}

char	*change_var(char *str, char **envp, int *err)
{
	t_args_var	args;
	t_quote		q;

	q.inDoubleQuote = 0;
	q.inSingleQuote = 0;
	args.re = malloc (change_var_count(str, envp) + 1);
	args.x = -1;
	args.i = 0;
	args.c_var = 0;
	while (str[++args.x])
	{
		args.l = chacke_q(str[args.x], &q);
		if (check_and_her_var(str, args.x, args))
		{
			if (str[args.x + 1] == '?')
				change_var_one(&args.x, args.re, &args.i);
			else if (!(is_sp(str[args.x + 1]) || str[args.x + 1] == '\''
					|| str[args.x + 1] == '"'))
				change_var_tow(&args, str, err, envp);
		}
		else
			args.re[args.i++] = str[args.x];
	}
	args.re[args.i] = '\0';
	return (args.re);
}
