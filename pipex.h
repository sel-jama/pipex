/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:52:15 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/21 10:27:12 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	*cmd1;
	char	*cmd2;
	pid_t	id1;
	pid_t	id2;
	int		fd[2];
	char	**flag_cmd;
}t_pipex;

void	ft_open_files(char **av, t_pipex *pipex);
char	*ft_get_path(char **env);
char	*ft_get_cmd(t_pipex **pipex, char **av, char **env, int n_cmd);
char	*ft_join_slash_cmd(t_pipex **pipex, char *av, char **paths);
void	ft_child1(t_pipex *pipex, char **av, char **env);
void	ft_child2(t_pipex *pipex, char **av, char **env);
void	ft_free(char **paths);
void	ft_init_var(t_pipex *pipex);
void	ft_error_msg(char *msg, char *av);
char	*ft_slash_cmd(t_pipex **pipex, char *arg);

#endif
