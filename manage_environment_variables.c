/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_environment_variables.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergiopax <sergiopax@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:27:58 by keshav            #+#    #+#             */
/*   Updated: 2022/02/21 09:26:23 by sergiopax        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_environment	g_env;

void	init_env(int argc, char *argv[], char *envp[])
{
	int	i;
	int	j;

	i = 0;
	while (envp && *(envp + i) && argc && argv)
		i++;
	g_env.env_var = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!g_env.env_var)
	{
		perror("Problem with memory allocation");
		exit(1);
	}
	j = 0;
	while (j < i)
	{
		if (!ft_strncmp(envp[j], "HOME=", 5))
			g_env.home = ft_strdup(envp[j] + 5);
		if (ft_strncmp(envp[j], "OLDPWD", 6))
			*(g_env.env_var + j) = ft_strdup(envp[j]);
		else
			*(g_env.env_var + j) = ft_strdup("");
		j++;
	}
	g_env.size = i;
	g_env.previous = ft_strdup(getenv("HOME"));
}

void	free_global(void)
{
	int	i;

	i = 0;
	free(g_env.previous);
	while (g_env.env_var && *(g_env.env_var + i))
	{
		free(*(g_env.env_var + i));
		i++;
	}
	free(g_env.home);
	free(g_env.env_var);
}
