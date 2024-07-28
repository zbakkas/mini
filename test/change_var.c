
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-28 15:45:21 by zbakkas           #+#    #+#             */
/*   Updated: 2024-07-28 15:45:21 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"

int exx = 5001;

static char	*search_in_env(char **envp, char *str)
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
			if (str[x] == ' ' || str[x] == '\'' || str[x] == '"')
				break ;
			i++;
		}
		if (str[x] == '$')
			is_v = 1;
		x++;
	}
	return (i);
}

static char	*get_name_var(char *str, int *j)
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
			if (str[x] == ' ' || str[x] == '\'' || str[x] == '"')
				break ;
			re[i++] = str[x];
			(*j)++;
		}
		if (str[x] == '$')
			is_v = 1;
		x++;
	}
	re[i] = '\0';
	return (re);
}

// $?
int	change_var_count_one(int *x)
{
	char	*str;
	int		i;

	str = ft_itoa(exx);
	i = ft_strlen(str);
	(*x)++;
	free(str);
	return (i);
}

int	change_var_count_tow(char **envp, int l, int *x, char *str)
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
	if (l != 2)
		i++;
	while (l != 2 && var && var[j])
	{
		if (j - 1 >= 0 && l != 2 && var[j - 1] == ' ' && var[j] != ' ')
			i++;
		if (l != 2 && var[j] != ' ' && (var[j + 1] == ' '
				|| var[j + 1] == '\0'))
			i++;
		j++;
	}
	return (i);
}

int	change_var_count(char *str, char **envp, int *err)
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
			&& str[x + 1] != ' ' && str[x + 1] != '$')
		{
			if (str[x + 1] == '?')
				i = i + change_var_count_one(&x);
			else if (!(str[x + 1] == ' ' || str[x + 1] == '\''
					|| str[x + 1] == '"'))
				i = i + change_var_count_tow(envp, l, &x, str);
		}
		else
			i++;
	}
	return (i);
}

char *change_var(char * str, char **envp, int *err)
{
	char *re;
	int x;
	int q;
	int qq;
	char * var= NULL;
	int i;
	int  j;

	i = change_var_count(str,envp,err);
	printf("d =%d\n",i);
	re =malloc (i+1);
	x =0;
	i =0;
	q=0;
	qq=0;
	 j =0;
	while (str[x])
	{
		if (str[x] == '\'' ||  str[x] == '"') 
		{
			if(qq ==0)
			{
				q=str[x];
				qq++;
			}
			else if (q==str[x])
			{
				qq=0;
				q=0;            
			}
			
			// sing_q= !sing_q;
		}
	// printf("%c",str[x]);
		// printf("\nq=%c|\n",q);
		if(str[x]=='$'&& q!='\'' && str[x+1]&& str[x+1]!=' ' && str[x+1]!='$')
		{
			if(str[x+1]=='?')
			{
				// i+=ft_strlen(ft_itoa(exx));
				char *sss= ft_itoa(exx);
				int a =0;
				while (sss[a])
				{
					re[i++]=sss[a++];
				}
				free(sss);

				
				x++;
			}
			else if(str[x+1]&& (str[x+1]==' ' ||  str[x+1]=='\''|| str[x+1]=='"'))//|$ |
			{
				// if((str[x+1]=='"' || str[x+1]=='\''))
				//     x++;
			}
			else   
			{





				j =x;
				// printf("v=%s\n",(get_name_var(str+x)));
				char *ss= get_name_var(str+x,&x);
			   var = search_in_env(envp,ss);
				// var = getenv(ss);
				free(ss);


				/////error

				int l =0;
				int k =0;
				while (var &&var[l])
				{
					if(var[l]==' ')
					{
						k =1;
						break;
					}
					l++;
				}
				l =j;
				if (q!='"'&&  str[x])
				{
					while (l>=0)
					{
						
						l--;
						//  printf("%c\n",str[l]);   
						if((str[l]=='>'||str[l]=='<' ))
						{
							if((!var || k))
								*err = 1;
						}

						if(str[l]!=' ')
							break;
						


						
					}
					
					

					
					
				}
				


				//////////
				// var = search_env(env,get_name_var(str+x,&x));
				j =0;
				if( var && var[j] && q!='"')
					re[i++]='"';
				while (var && var[j])
				{
					if(j-1>=0&&q!='"' && var[j-1]==' ' &&var[j]!=' ')
						re[i++]='"';
					// if(j-1>=0&&q!='"' && var[j-1]!=' ' &&var[j]==' ')
					//     re[i++]='"';
					re[i++]=var[j];
					if(q!='"' && var[j]!=' ' &&(var[j+1]==' '|| var[j+1]=='\0'))
						re[i++]='"';
					j++;
				}

				// string   |
				// string|
				// if(q!='"')
				//     re[i++]='"';
				
			
				
			}
		
		
		}
		else    
		{
			re[i++]= str[x];
		}
		x++;
		
	}
	re[i]='\0';
	return re;
}


// int main()
// {
//     t_envp *env=NULL;
//     char *str  = "ll $$ $ARG dd";
//     char *ss= "ll $$ \"echo\" \"|\" \"ls'\" '-l\"    \">\"    \"'\"  \"cat\"   dd";
//     printf("%s\n",str);
//     printf("%s\n",change_var(str));
// }