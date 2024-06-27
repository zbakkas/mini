/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-25 18:35:37 by zbakkas           #+#    #+#             */
/*   Updated: 2024-06-25 18:35:37 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <string.h>
#include <readline/readline.h>
#include "libft/libft.h"

typedef struct s_args
{
    char **cmd;//=>cmd[0] =cat cmd[1] = grep cmd[2] =NULL
    char **flag;// flag[0] =NULL flag[1] =NULL flag[2] =NULL
    char **token; //token[0] = '|'  token[1] = '>' token[2] = NULL
    char **dependes;//  d[0] = text.txt d[1]= "hello c" d[2]= NULLL
    char **out; // out[0]= NULL out[1]= NULL out[2]= "out.txt"
    // struct s_args *next;
} t_args;


typedef struct s_args_n
{
    char *cmd;//=>cmd[0] =cat cmd[1] = grep cmd[2] =NULL
    char *flag;// flag[0] =NULL flag[1] =NULL flag[2] =NULL
    char *token; //token[0] = '|'  token[1] = '>' token[2] = NULL
    char *dependes;//  d[0] = text.txt d[1]= "hello c" d[2]= NULLL
    char *out; // out[0]= NULL out[1]= NULL out[2]= "out.txt"
    struct s_args_n *next;
} t_args_n;


char * get_str_redline();
char	**ft_split_str(char *str, char **tokens);
void get_all(char *line,char **t,t_args *args,t_args_n **args_n);

char *get_cmd(char *str);
char *get_flages(char *str);
char *get_dependes(char *str);
char *get_token(char *str);

t_args_n	*ft_lstnew_one(t_args args, int i);
void	ft_lstadd_backk(t_args_n **lst, t_args_n *new);
void	ft_lstiterr(t_args_n *lst, void (*f)(char *,char *));
void f(char *name,char *str);
void	clear_list(t_args_n **lst);
