/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:06:01 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/21 11:48:45 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child1(t_pipex *pipex, char **av, char **env)
{
	close(pipex->outfile);
	if (pipex->infile < 0)
		ft_error_msg("no such file or directory: ", av[1]);
	pipex->cmd1 = ft_get_cmd(&pipex, av, env, 2);
	if (!(pipex->cmd1))
		ft_error_msg("command not found: ", av[2]);
	close(pipex->fd[0]);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close(pipex->fd[1]);
	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->infile);
	execve(pipex->cmd1, pipex->flag_cmd, env);
}

void	ft_child2(t_pipex *pipex, char **av, char **env)
{
	close(pipex->infile);
	if (pipex->outfile < 0)
		ft_error_msg("permission denied: ", av[4]);
	pipex->cmd2 = ft_get_cmd(&pipex, av, env, 3);
	if (!(pipex->cmd2))
		ft_error_msg("command not found: ", av[3]);
	close(pipex->fd[1]);
	dup2(pipex->fd[0], STDIN_FILENO);
	close(pipex->fd[0]);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->outfile);
	execve(pipex->cmd2, pipex->flag_cmd, env);
	//file name, arguments array specifies the command-line arguments,  environment variable array
}
