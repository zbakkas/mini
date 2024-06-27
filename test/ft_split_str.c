/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:11:32 by zbakkas           #+#    #+#             */
/*   Updated: 2023/09/06 22:25:50 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"
#include <string.h>

//cat t.txt | grep e  > out

static char *get_part(char *str,int x)
{
	
	char *re;
	int i;
	i=0;
	re =malloc(x+1);
	while (x)
	{
		re[i] =str[i];
		i++;
		x--;
	}
	re[i]='\0';
	return re;

}

static char *part(char *str, char *tokens)
{
	int re;
	int i;
	int l;

	i = 0;
	re = 0;
	if(!tokens)
		return get_part(str,strlen(str));
	while (str[i])
	{
		l =0;
		while (tokens[l]==str[i+l])
		{
			if(tokens[l+1]=='\0')
			{
				if(l == 0 && str[l+i-1] != '>' && str[l+i+1] != '>' && str[l+i-1] != '<' && str[l+i+1] != '<' )
					return get_part(str,i+l+1);//+1 to get token
				else if(l == 1)
					return get_part(str,i+l+1);//+1 to get token

			}
			l++;
		}

		i++;
	}
	

}
static int count_tokens(char *str, char **tokens)
{
	int re;
	int i=0;
	int x =0;
	int  l =0;
	re =0;
	while (tokens[i])
	{
		l =0;
		// printf("%s\n",tokens[i]);
		while (str[l])
		{
			x =0;
			// printf("%c\n",tokens[i][x]);
			// printf("%c\n",str[l+x]);
			while(tokens[i][x]  && tokens[i][x]==str[l+x])
			{
				// printf("DD\n");
				if( tokens[i][x+1]=='\0')
				{
					if(x == 1)
					{
						// printf("--%c--\n",str[l+x-1]);
						// printf("== %s\n",tokens[i]);
						re++;
					}
					else if(x == 0 && str[l+x-1] != '>' && str[l+x+1] != '>' && str[l+x-1] != '<' && str[l+x+1] != '<' )
					{
						// printf("--%c--\n",str[l+x-1]);
						// printf("== %s\n",tokens[i]);
						re++;
					}

				}
			
				x++;
			}
			l++;
		}
		
		i++;
	}
	return re;
	
}

static char ** get_token_sorte(char *str, char **tokens,int c)
{
	char **re ;
	// printf("%d\n",count_tokens(str,tokens));
	re= (char **)malloc(c*sizeof(char *));
	int x =0;
	int i ;
	int l;
	int r =0;
	while (str[x])
	{
		i =0;
		while (tokens[i])
		{
			l=0;
			while (tokens[i][l]== str[x+l])
			{
				if( tokens[i][l+1]=='\0')
				{
					if(l == 1)
					{
						// printf("--%c--\n",str[l+x-1]);
						// printf("== %s\n",tokens[i]);
						re[r++]=tokens[i];
					}
					else if(l == 0 && str[l+x-1] != '>' && str[l+x+1] != '>' && str[l+x-1] != '<' && str[l+x+1] != '<' )
					{
						// printf("--%c--\n",str[l+x-1]);
						// printf("== %s\n",tokens[i]);
						re[r++]=tokens[i];
					}

				}
				l++;
			}
			i++;
			
		}
		
		x++;
	}
	re[r]=NULL;
	return re;

}

char	**ft_split_str(char *str, char **tokens)
{
	char **re;
	// printf("rrr\n");
	int c = count_tokens(str,tokens); //+1 ==> we have 2 token but parte is 3 
	// printf("%d\n",c);
	char **tk = get_token_sorte(str,tokens,c);
	re= (char **)malloc((c+1)*sizeof(char *));
	int x =0;
	int i;
	while (c--)
	{
		re[x]=part(str,tk[x]);
		// printf("%s\n",re[x]);
		str+=strlen(re[x]);
		x++;
	}
	re[x++]=part(str,NULL);
	re[x]=NULL;
	// re[0] =part(str,tokens[3]);
	// printf("%s\n",re[0]);
	return re;

}


// int main()
// {
// 	char **t =(char **)malloc(6*sizeof(char *));
// 	t[0]="|";
// 	t[1]="<";
// 	t[2]="<<";
// 	t[3]=">>";
// 	t[4]=">";
// 	char * str = "ls -l | wc -l >out";
// 	// printf("%s",part("cat t.txt || grep e  > out","||"));
// 	int i =0;
// 	while (ft_split_str(str,t)[i])
// 	{
// 		printf("%s\n",ft_split_str(str,t)[i++]);
// 	}
	
	



// }
