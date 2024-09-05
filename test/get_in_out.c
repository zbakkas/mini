/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_in_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:19:17 by zbakkas           #+#    #+#             */
/*   Updated: 2024/09/05 10:58:59 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"

t_in *get_inp(t_files *files)
{
    t_in    *in;
    int     i;
    int     x;
    
    x =0;
    i =0;
    while (files[i].last)
    {
        if(files[i].typ== 4 || files[i].typ== 3)
            x++;
        i++;
    }
    in = malloc((x+1)* sizeof(t_in));
    i =0;
    x =0;
    while (files[i].last)
    {
        if(files[i].typ== 4 || files[i].typ== 3)
        {
            in[x].in = files[i].file;
            if(files[i].typ== 4)
                in[x].is_h = true;
            in[x].is_am = files[i].is_am;
            in[x].is_q = files[i].is_q;
            x++;
        }
        i++;
    }
    in[x].in =NULL;
    in[x].is_am =false;
    in[x].is_h =false;
    in[x].is_q=false;
    return (in);
}

t_out *get_out(t_files *files)
{
    t_out    *out;
    int     i;
    int     x;
    
    x =0;
    i =0;
    while (files[i].last)
    {
        if(files[i].typ== 1 || files[i].typ== 2)
            x++;
        i++;
    }
    // printf("xxxxxxx===========%d\n",x);
    out = malloc((x+1)* sizeof(t_out));
    i =0;
    x =0;
    while (files[i].last)
    {
        if(files[i].typ== 1 || files[i].typ== 2)
        {
            out[x].out = files[i].file;
            if(files[i].typ== 2)
                out[x].is_a = true;
            out[x].is_am = files[i].is_am;
            x++;
        }
        i++;
    }
    out[x].out=NULL;
    out[x].is_a=false;
    out[x].is_am=false;
    return (out);
}

