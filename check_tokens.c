/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:00:34 by sergiopax         #+#    #+#             */
/*   Updated: 2022/03/04 17:40:20 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_environment	g_env;

char	get_last_char(char *string)
{
	int	i;

	i = 0;
	while (string && *(string + i))
	{
		if (*(string + i + 1) == '\0')
			return (*(string + i));
		i++;
	}
	return ('a');
}

bool	check_tokens(char ***tokens)
{
	char	last_char;
	int		i;

	i = 0;
	while (tokens && *(tokens + i))
	{
		last_char = get_last_char(**(tokens + i));
		if (last_char == '/' || last_char == '.')
		{
			printf("%s is a directory\n", **(tokens + i));
			g_env.exit_status = 126;
			return (false);
		}
		i++;
	}
	return (true);
}
