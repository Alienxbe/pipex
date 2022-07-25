/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pexec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 03:19:22 by mykman            #+#    #+#             */
/*   Updated: 2022/07/25 04:28:02 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**create_pipes(int count)
{
	int	**pipes;
	int	i;

	pipes = (int **)ft_calloc(sizeof(int *), count + 1);
	if (!pipes)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipes[i] || pipe(pipes[i]) == -1)
		{
			close_free_pipes(pipes);
			return (NULL);
		}
	}
	return (pipes);
}

int	ft_pexec(const char *str, char **envp, t_pipe pipes)
{
	int	id;

	id = fork();
	if (id == -1)
		ft_exit("Fork failed", EXIT_FAILURE);
	if (id == 0)
	{
		if (pipes.inpipe >= 0)
			dup2(pipes.inpipe, STDIN_FILENO);
		if (pipes.outpipe >= 0)
			dup2(pipes.outpipe, STDOUT_FILENO);
		close_free_pipes(pipes.pipes);
		if (ft_exec(str, envp) == -1)
			ft_exit("command not found", EXIT_FAILURE);
	}
	return (id);
}
