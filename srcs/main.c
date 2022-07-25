/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:26:06 by mykman            #+#    #+#             */
/*   Updated: 2022/07/25 04:40:11 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** Should remove the pipes list and replace it by a clever
** ft_pexec function
*/
static void	ft_pipex(int argc, char const **argv, char **envp)
{
	int	**pipes;

	pipes = create_pipes(argc - 4);
	if (!pipes)
		ft_exit("Could not create pipes", EXIT_FAILURE);
	ft_pexec(argv[2], envp, (t_pipe){-1, pipes[0][1], pipes});
	for (int i = 0; i < argc - 5; i++)
		ft_pexec(argv[3 + i], envp, (t_pipe){pipes[i][0], pipes[i + 1][1], pipes});
	ft_pexec(argv[argc - 2], envp, (t_pipe){pipes[argc - 5][0], -1, pipes});
	close_free_pipes(pipes);
	while (wait(NULL) > 0)
		;
}

int main(int argc, char const **argv, char **envp)
{
	if (argc < 5)
		ft_exit("Usage: ./pipex infile cmd1 cmd2 outfile", EXIT_FAILURE);
	ft_pipex(argc, argv, envp);
	return (0);
}
