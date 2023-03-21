/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:51:36 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/21 11:25:15 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void	ft_open_files(char **av, t_pipex *pipex)
{
	pipex->infile = open(av[1], O_RDONLY);
    pipex->outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

void	ft_init_var(t_pipex *pipex)
{
	pipex->infile = 0;
	pipex->outfile = 0;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->flag_cmd = NULL;
}

void	ft_error_msg(char *msg, char *av)
{
	ft_putstr_fd(msg, 2);
	if (av)
		ft_putendl_fd(av, 2);
	exit(1);
}
