/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-26 19:25:12 by zbakkas           #+#    #+#             */
/*   Updated: 2024-06-26 19:25:12 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"
#include <string.h>

void get_all(char *line,char **t,t_args *args)
{
    

    // printf("%s\n",line);
    ft_split_str(line,t);
    // printf("ff\n");
    int i =0;
    int x =0;
    while(ft_split_str(line,t)[x])
        x++;
    args->cmd = (char **)malloc(x*sizeof(char *));
    args->flag = (char **)malloc(x*sizeof(char *));
    args->dependes = (char **)malloc(x*sizeof(char *));
    args->token = (char **)malloc(x*sizeof(char *));
    while(ft_split_str(line,t)[i])
    {
        
        printf("%s\n",ft_split_str(line,t)[i]);
        // ft_lstnew_one(get_cmd(ft_split_str(line,t)[i]),get_flages(ft_split_str(line,t)[i]),get_dependes(ft_split_str(line,t)[i]),get_token(ft_split_str(line,t)[i]));
        args->cmd[i]=get_cmd(ft_split_str(line,t)[i]);
        args->flag[i]=get_flages(ft_split_str(line,t)[i]);
        args->dependes[i]=get_dependes(ft_split_str(line,t)[i]);
        args->token[i]=get_token(ft_split_str(line,t)[i]);
        i++;
    }


}

// int main()
// {   
//     char **t =(char **)malloc(6*sizeof(char *));
// 	t[0]="|";
// 	t[1]="<";
// 	t[2]="<<";
// 	t[3]=">>";
// 	t[4]=">";
//     t_args args;


// 	get_all("cat t.txt | grep \"e\" > out",t,&args);
//     int i =0;
// while (args.cmd[i])
// {


// printf("cmd==>%s<-\n",args.cmd[i]);
// printf("flag==>%s<-\n",args.flag[i]);
// printf("depends==>%s<-\n",args.dependes[i]);
// printf("token==>%s<-\n",args.token[i]);
// i++;
// }
// }
