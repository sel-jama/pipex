/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 01:51:40 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/21 11:49:19 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac == 5)
	{
		ft_init_var(&pipex);
		ft_open_files(av, &pipex);
		if (pipe(pipex.fd) < 0)
			exit(1);
		pipex.id1 = fork();
		if (pipex.id1 == -1)
			exit (1);
		if (pipex.id1 == 0)
			ft_child1(&pipex, av, env);
		pipex.id2 = fork();
		if (pipex.id2 == -1)
			exit(1);
		if (pipex.id2 == 0)
			ft_child2(&pipex, av, env);
		close(pipex.fd[1]);
		close(pipex.fd[0]);
		wait(&pipex.id1);
		wait(&pipex.id2);
		close(pipex.infile);
		close(pipex.outfile);
	}
	return (0);
}
