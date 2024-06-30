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
#include <stdbool.h>


typedef struct s_args
{
    char *cmd;
    char **flags;
    char *arguments;
} t_args;


typedef struct s_args_n
{
    char *cmd;
    char **flags;
    char *arguments;
    char **files;
    char **tokens;
    struct s_args_n *next;
} t_args_n;


char * get_str_redline();

char	**ft_split_pip(char  *s, char c);
char *get_argumants(char *str);
char **get_flages(char *str);
char *get_cmd(char *str);


void	ft_lstadd_backk(t_args_n **lst, t_args_n *new);
t_args_n	*ft_lstnew_one(char *str);
void f(char *name,char *str);
void	ft_lstiterr(t_args_n *lst, void (*f)(char *, char *));
void	clear_list(t_args_n **lst);