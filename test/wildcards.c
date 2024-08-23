/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:37:51 by zbakkas           #+#    #+#             */
/*   Updated: 2024/08/23 14:26:58 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"

char	*chech_be(char *str, int x)
{
	int		i;
	int		j;
	t_quote	q;
	int		l;
	char	*re;

	q.in_double_quote = 0;
	q.in_single_quote = 0;
	x--;
	i = 0;
	j = 0;
	while (x >= 0)
	{
		l = chacke_q(str[x], &q);
		if (str[x] == '*' && !l)
			break ;
		j++;
		x--;
	}
	re = malloc(j + 1);
	while (i < j)
		re[i++] = str[++x];
	re[i] = '\0';
	return (re);
}

char *check_aft(char *str, int x, int xx)
{
	int i=0;
	int j =0;

	int l;
	while (str[x])
	{
		x++;
		j++;
	}
	char *re;
	re =malloc(j + 1);
	while (i < j)
	{
		re[i++]=str[xx++];
	}
	re[i]='\0';
	// printf("af=%s\n",re);
	return (re);
}

int hh(char *str, char *name, int *i)
{
	int x =0;
	while(str[x])
	{
		if(str[x]!=name[*i])
			return 1;
		x++;
		(*i)++;
	}
	return 0;
}

int hhh(char *str, char *name, int *i)
{
	int x =0;
	while(name[*i])
	{
		x=0;
		while (str[x]&&name[*i] && name[*i] == str[x])
		{
			x++;
			(*i)++;
		}
		if(!str[x])
			return 0;
		(*i)++;
	}
	return 1;
}
int hhhh(char *str, char *name)
{
	int x =ft_strlen(str);
	int i = ft_strlen(name);
	while (x>0)
	{
		if(name[i-1]!=str[x-1])
			return 1;
		i--;
		x--;
	}
	return 0;
}
int last_wildcards(char *str, int x)
{
	t_quote	q;
	int l;

	q.in_double_quote = 0;
	q.in_single_quote = 0;
	while (str[x])
	{
		l = chacke_q(str[x],&q);
		if(!l && str[x]=='*')
			return 0;
		x++;
	}
	return 1;
	
}
int first_wildcards(char *str, int x)
{
	t_quote	q;
	int l;

	q.in_double_quote = 0;
	q.in_single_quote = 0;
	while (x>=0)
	{
		l = chacke_q(str[x],&q);
		if(!l && str[x]=='*')
			return 0;
		x--;
	}
	return 1;
	
}

//'h'*p*r*kv*'*' ===> hkonmpiirnvkv*
int is_equal(char *str, char *name)
{
	t_quote	q;
	int x;
	int l;
	char *ss;
	int i;

	i = 0;
	x =0;
	q.in_double_quote = 0;
	q.in_single_quote = 0;
	while (str[x])
	{
		l = chacke_q(str[x],&q);
		if(last_wildcards(str,x))
			i = -1;
		if(!l && str[x]=='*' &&x-1 >= 0 && i!=-1 && !first_wildcards(str,x-1))
		{
			ss = whithout_q(chech_be(str,x),1);
			if(hhh(ss,name,&i))
				return (free(ss), 0);
			free(ss);
		}
		else if(!l && str[x]=='*' &&x-1 >= 0 && i!=-1 && first_wildcards(str,x-1))
		{
			printf("gg\n");
			ss = whithout_q(chech_be(str,x),1);
			if(hh(ss,name,&i))
				return (free(ss), 0);
			free(ss);
		}
		else if(i==-1)
		{
			ss = whithout_q(check_aft(str,x,x),1);
			if(hhhh(ss,name))
				return (free(ss), 0);
			free(ss);
		}
		x++;
			
	}
	return (1);
}

char **get_name_of_files(char *str )
{

	struct dirent *entry;
	DIR *dp;
	char *str_j;
	char **re;
	
	re = NULL;
	str_j =NULL;
	dp = opendir(".");
	while ((entry = readdir(dp)) != NULL)
	{
		
		if(entry && entry->d_name[0]!='.' && is_equal(str,entry->d_name))
		{
			str_j = strjoin_parsing(str_j,entry->d_name);
			str_j = strjoin_parsing(str_j," ");
		}
		// entry = readdir(dp);
	}
	re =ft_split(str_j,' ');
	free(str_j);
	closedir(dp);
	return re;
}

int check_wildcards(char *str)
{
	t_quote	q;
	int x;
	int l;

	x =0;
	q.in_double_quote = 0;
	q.in_single_quote = 0;
	while (str[x])
	{
		l= chacke_q(str[x],&q);
		if(str[x]=='*'&&!l)
			return 1;
		x++;
	}
	return 0;
}