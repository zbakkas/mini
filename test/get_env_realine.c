/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_realine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:32:57 by zbakkas           #+#    #+#             */
/*   Updated: 2024/08/21 16:38:41 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"

char	*get_str_redline(void)
{
	char	*re;
	char	*user;

	user = getenv("USER");
	re = strjoin_parsing("\033[0;32m", user);
	re = strjoin_parsing(re, "\033[0m\033[1;37m@1337 ");
	re = strjoin_parsing(re, "\033[0;36mminishell\033[0m$ ");
	return (re);
}
