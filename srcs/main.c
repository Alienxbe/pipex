/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:26:06 by mykman            #+#    #+#             */
/*   Updated: 2022/07/26 00:30:06 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** Should remove the pipes list and replace it by a clever
** ft_pexec function
*/
static void	ft_pipex(int argc, char const **argv, char **envp)
{
	int	stdoutfd;
	int	i;

	stdoutfd = dup(STDOUT_FILENO);
	i = 1;
	while (++i < argc - 2)
		ft_pexec(argv[i], envp);
	dup2(STDOUT_FILENO, stdoutfd);
	close(stdoutfd);
	close(STDOUT_FILENO);
	ft_exec(argv[i], envp);
}

int main(int argc, char const **argv, char **envp)
{
	if (argc < 5)
		ft_exit("Usage: ./pipex infile cmd1 cmd2 outfile", EXIT_FAILURE);
	ft_pipex(argc, argv, envp);
	return (0);
}
