/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pexec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 03:19:22 by mykman            #+#    #+#             */
/*   Updated: 2022/07/26 00:36:04 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pexec(const char *str, char **envp)
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		ft_exit("Could not create pipe", EXIT_FAILURE);
	id = fork();
	if (id == -1)
		ft_exit("Fork failed", EXIT_FAILURE);
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (ft_exec(str, envp) == -1)
			ft_exit("command not found", EXIT_FAILURE);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(id, NULL, 0);
	}
}
