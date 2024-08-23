/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:50:38 by zbakkas           #+#    #+#             */
/*   Updated: 2024/08/23 12:44:57 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"

static int	whithout_q_count(char *str, int x)
{
	int		c;
	int		l;
	t_quote	q;

	q.in_double_quote = 0;
	q.in_single_quote = 0;
	c = 0;
	while (str[x])
	{
		l = chacke_q(str[x], &q);
		if ((str[x] == '"' || str[x] == '\''))
		{
			if ((l == 1 && str[x] == '"') || (l == 2 && str[x] == '\''))
				c++;
		}
		else
			c++;
		x++;
	}
	return (c);
}

char	*whithout_q(char *str)
{
	char	*re;
	int		x;
	int		c;
	int		l;
	t_quote	q;

	q.in_double_quote = 0;
	q.in_single_quote = 0;
	x = 0;
	c = 0;
	if (!str)
		return (NULL);
	re = malloc(whithout_q_count(str, x) + 1);
	while (str[x])
	{
		l = chacke_q(str[x], &q);
		if ((l == 1 && str[x] == '"') || (l == 2 && str[x] == '\''))
			re[c++] = str[x];
		else if (str[x] != '"' && str[x] != '\'')
			re[c++] = str[x];
		x++;
	}
	re[c] = '\0';
	return (re);
}

char *chech_be(char *str, int x)
{
	int i=0;
	int j =0;
	t_quote	q;
	int l;

	q.in_double_quote = 0;
	q.in_single_quote = 0;
	x--;
	while (x >= 0)
	{
		l =chacke_q(str[x],&q);
		if(str[x]=='*'&&!l)
			break;
		j++;
		x--;
	}

	char *re;
	re =malloc(j+1);
	while (i < j)
	{
		re[i++]=str[++x];
	}
	re[i]='\0';
	// printf("be=%s\n",re);
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
		if(!l && str[x]=='*' &&x-1 >= 0 && i!=-1)
		{
			ss = whithout_q(chech_be(str,x));
			if(hhh(ss,name,&i))
				return (free(ss), 0);
			free(ss);
		}
		else if(i==-1)
		{
			ss = whithout_q(check_aft(str,x,x));
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
int ft_strlen_doubl(char **str)
{
	int x =0;
	if(!str)
		return 0;

	while (str[x])
	{
		x++;
	}
	
	return x;
}

static int	get_args_count(char **str)
{
	int	x;
	int	c;
	
	x = 0;
	c = 0;
	while (str[x])
	{
	// printf("str=%s",str[x]);
		
		if (str[x + 1] && (ft_strncmp(str[x], "<", 2) == 0
				|| ft_strncmp(str[x], ">", 2) == 0
				|| ft_strncmp(str[x], "<<", 3) == 0
				|| ft_strncmp(str[x], ">>", 3) == 0))
			x++;
		else if(check_wildcards(str[x]))
		{
			char **ss = get_name_of_files(str[x]);
			if(ft_strlen_doubl(ss)>0)
				c+= ft_strlen_doubl(ss);
			else
				c++;
		}
		else
			c++;
		x++;
	}
	return (c);
}

char	**get_args(char **str)
{
	char	**re;
	int		x;
	int		c;

	x = 0;
	c = 0;
	int i = get_args_count(str);
	printf("i=%d\n",i);
	re = (char **)malloc((i + 1) * sizeof(char *));
	while (str[x])
	{
		if (str[x + 1] && (ft_strncmp(str[x], "<", 2) == 0
				|| ft_strncmp(str[x], ">", 2) == 0
				|| ft_strncmp(str[x], "<<", 3) == 0
				|| ft_strncmp(str[x], ">>", 3) == 0))
			x++;
		else if(check_wildcards(str[x]))
		{
			char **ss = get_name_of_files((str[x]));
			if(ft_strlen_doubl(ss)>0)
			{
				int j =0;
				while (ss[j])
				{
					re[c++] =ss[j++];
				}
			}
			else
				re[c++] = whithout_q(str[x]);
		}
		else
			re[c++] = whithout_q(str[x]);
		x++;
	}
	re[c] = NULL;
	return (re);
}

// int main()
// {
//     char *str0 ="ls \"\" -a \"\" -l";
//     char *str1 ="l\"s\"> \"hello  <'worde\"  \"-l -a\" \"\">\"\" 'out'";
//     char *str2 ="l\"s\"< 'hello  \">> worde'  \"-l -a\">> out >f";
//     char *str3 ="<'cat'\"<\" \" min '2\" \"-e\"";
//     char *str4 = "'ca't file >out >>out1<< stop out2 > out3 \"-e\" -l";
//     char *str5 ="ls";
//     printf("%s\n",str5);
// //    printf("%s\n", set_speece(str3));
// char ** str =split_part(set_speece(str5));
// int x =0;
// // while (str[x])
// // {
// //     printf("%s\n",str[x]);
// //     x++;
// // }
// // // printf("x==%d\n",x);
// // // printf("--------------------\n");
// // // printf("cmd=%s\n",get_cmd2(str) ? get_cmd2(str):"(null)");
// // // char **flags=get_flags2(str);
// // // x =0;
// // // while (flags && flags[x])
// // // {
// // //     printf("flag%d =%s\n",x,flags[x]);
// // //     x++;
// // // }
// // x =0;
// // char **args =get_args(str); 
// // while (args[x])
// // {
// //     printf("arg[%d]=%s\n",x,args[x]);
// //    x++;
// // }
// // // get_args(str);
// // // printf("%s\n" , whithout_q("    cat ffr"));
// // x =0;
// t_out *out =get_out(str);
// while (out[x].out)
// {
//     printf("out file [%d]:%s\n",x,out[x].out);
//     printf("is append [%d]:%d\n",x,out[x].is_a);
//     x++;
// }
// x =0;
// t_inp *inp =get_inp(str);
// while (inp[x].inp)
// {
//     printf("inp file [%d]:%s\n",x,inp[x].inp);
//     printf("is Heredoc [%d]:%d\n",x,inp[x].is_h);
//     x++;
// }
// }