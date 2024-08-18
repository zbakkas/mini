/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:35:37 by zbakkas           #+#    #+#             */
/*   Updated: 2024/08/18 17:28:52 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIN_H
#define MIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <string.h>
#include <readline/readline.h>
#include "libft/libft.h"
#include <stdbool.h>

// #ifndef g_exit_status
// #define g_exit_status

extern int	g_exit_status;

// #endif


# define TOKENS_ERROR "minishell: syntax error near unexpected token"
# define NEW_LINE_ERROR "minishell: syntax error near unexpected token `newline'\n"
// # define HEREDOC_ERROR "minishell: syntax error near unexpected token `<<'"
// # define APPEND_ERROR "minishell: syntax error near unexpected token `>>'"
// # define IN_ERROR "minishell: syntax error near unexpected token `<'"
// # define OUT_ERROR "minishell: syntax error near unexpected token `>'"

# define QUOTES_ERROR "minishell: unexpected EOF while looking for matching"
# define AMBIGUOUS_ERROR "minishell: ambiguous redirect\n"
// # define SPACE_REDIRECTION_ERROR ": No such file or directory"


/////////////////////////////////////////////////
typedef struct s_envp
{
	char			*env;
	struct  s_envp	*prev;
	struct  s_envp	*next;
}                   t_envp;

/////////////////////////////////////////////

typedef struct  s_quote
{
	int inDoubleQuote ;
	int inSingleQuote ;

}t_quote;


typedef struct s_inp
{
	char *inp;
	bool is_h;

	

} t_inp;

typedef struct s_out
{
	char *out;
	bool is_a;


} t_out;
///////change_var////
typedef struct s_args_var
{
	int		x;
	int		l;
	char	*re;
	int		i;
}	t_args_var;
/////////////////////

typedef struct s_args_n
{
	char **arguments;
	t_inp *inp;
	t_out *out;
	struct s_args_n *next;
	
} t_args_n;


char * get_str_redline();

char	**ft_split_pip(char  *s, char c);
char **split_part(char *s);
char *set_speece( char *str) ;


// char *get_argumants(char *str);
// char **get_flages(char *str);
// char *get_cmd(char *str);
char *change_var(char * str, char **envp, int *err);
int	change_var_count(char *str, char **envp);
char	*get_name_var(char *str, int *j);
char	*search_in_env(char **envp, char *str);


char **get_args(char **str);
t_out *get_out(char **str);
t_inp *get_inp(char **str);

t_args_n *initialization_list(char *line, char **envp);
void	ft_lstadd_backk(t_args_n **lst, t_args_n *new);
t_args_n	*ft_lstnew_one(char **str);
void	ft_lstiterr(t_args_n *lst);
void	clear_list(t_args_n **lst);

char	*whithout_q(char *str);

int check_errors(char *str,int err);
int chacke_q(char c,t_quote *q);
int	is_sp(char c);


#endif