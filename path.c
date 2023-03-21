/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:04:15 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/21 10:09:28 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

char	*ft_get_path(char **env)
{
	char	*path;

	path = NULL;
	while (*env)
	{
		if (ft_strncmp(*env, "PATH", 4) == 0)
		{
			path = *env + 5;
			break ;
		}
		env++;
	}
	return (path);
}

char	*ft_get_cmd(t_pipex **pipex, char **av, char **env, int n_cmd)
{
	char	*path;
	char	**splited_paths;
	char	*cmd;

	cmd = NULL;
	if (ft_strchr(av[n_cmd], '/'))
		cmd = ft_slash_cmd(pipex, av[n_cmd]);
	else
	{
		path = ft_get_path(env);
		if (!path)
			ft_error_msg("command not found: ", av[n_cmd]);
		splited_paths = ft_split(path, ':');
		cmd = ft_join_slash_cmd(pipex, av[n_cmd], splited_paths);
	}
	return (cmd);
}

char	*ft_join_slash_cmd(t_pipex **pipex, char *av, char **paths)
{
	int		i;
	char	*slash_path;
	char	*cmd;

	(*pipex)->flag_cmd = ft_split(av, ' ');
	i = -1;
	cmd = NULL;
	slash_path = NULL;
	while (paths[++i])
	{
		slash_path = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(slash_path, (*pipex)->flag_cmd[0]);
		free(slash_path);
		if (access(cmd, X_OK) == 0)
		{
			ft_free(paths);
			return (cmd);
		}
		free(cmd);
	}
	ft_free((*pipex)->flag_cmd);
	ft_free(paths);
	return (NULL);
}

char	*ft_slash_cmd(t_pipex **pipex, char *arg)
{
	(*pipex)->flag_cmd = ft_split(arg, ' ');
	if (access((*pipex)->flag_cmd[0], X_OK) == 0)
		return ((*pipex)->flag_cmd[0]);
	ft_free((*pipex)->flag_cmd);
	return (NULL);
}
