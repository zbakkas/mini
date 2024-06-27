/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-26 00:15:54 by zbakkas           #+#    #+#             */
/*   Updated: 2024-06-26 00:15:54 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "min.h"
//ls -l |
//echo "hello c" >
//ls-l-a

int count_cdm(char *str,char c)
{
    int i =0;
    while (str[i])
    {
        if(str[i]==c)
            return i;
        i++;
    }
    return i;
}

char *get_cmd(char *str)
{
    char *re;
    int i =0;
    while (str[i] ==' ')
        i++;
    str+=i;
    int c = count_cdm(str,' ');
    re =malloc(c+1);
    // printf("%d\n",c);
    i =0;
    while (c>i)
    {
        re[i]= str[i];
        i++;
    }
    re[i]='\0';
    return re;

}
int count_flages(char *str)
{
    int re=0;
    int i =0;
    while (str[i])
    {
        while (str[i] && str[i]!=' ')
        {
            i++;
        }
        while (str[i] && str[i]==' ')
        {
            i++;
        }
        if(str[i]=='-')
            i++;
        else
            break;
        
        
    }
    return i;
    
}
char *get_flages(char *str)
{
    char *re;
    int i =0;
    int x =0;
    while (str[i])
    {
        if(str[i]=='-')
            break;
        i++;
    }
    str+=i;
    // printf("%d",i);
    int c =count_flages(str);
    re =malloc(c+1);
    while (c>x)
    {
       re[x]=str[x];
       x++;
    }
    re[x]='\0';
    // printf(">%s<\n",str);
    return re;
}
int count_dep(char *str)
{
    int i =0;
    if(str[0]=='"')
    {
        str++;
        return count_cdm(str,'"');
    }
    else
        return count_cdm(str,' ');
    
}
char *get_dependes(char *str)
{
    char *re;
    int c;
    int i =0;
    int x =0;
    while (str[i] ==' ')
        i++;
    while (str[i])
    {
        if(str[i]==' ')
            break;
        i++;
    }
    if(str[i]==' ')
        str+=i+1;
    else
        str+=i;
    
    c = count_dep(str);
    re =malloc(c+1);
    if(str[0]=='"')
        str++;
    while (c>x)
    {
        re[x]=str[x];
        x++;
    }
    
    re[x]='\0';
    // printf("%d\n",c);
    // printf(">%s<\n",str);
     return re;
}
char *get_token(char *str)
{
    char *re= NULL;
    int x=0;
    while (str[x])
        x++;
    while (str[x-1]==' ')
        x--;
    
    if(str[x-1]=='|' )
    {
        re =malloc(2);
        re[0]='|';
        re[1]='\0';
        return re;
    }
    if(str[x-1]=='>' )
    {
        if(str[x-2]=='>')
        {
        re =malloc(3);
        re[0]='>';
        re[1]='>';
        re[2]='\0';
        return re;
        }
        else
        {
        re =malloc(2);
        re[0]='>';
        re[1]='\0';
        return re;
        }
    }
    else if(str[x-1]=='<' )
    {
        if(str[x-2]=='<')
        {
        re =malloc(3);
        re[0]='<';
        re[1]='<';
        re[2]='\0';
        return re;
        }
        else
        {
        re =malloc(2);
        re[0]='<';
        re[1]='\0';
        return re;
        }
    }


    

    return re;
}

// int main()
// {
//     printf("%s<\n",get_token("echo hello txt <"));
// }