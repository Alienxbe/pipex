/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:26:06 by mykman            #+#    #+#             */
/*   Updated: 2022/07/24 14:07:18 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char const **argv, char **envp)
{
	int	id;
	int	id2;

	if (argc != 5)
		ft_exit("Usage: ./pipex infile cmd1 cmd2 outfile", EXIT_FAILURE);
	id = fork();
	if (id == -1)
		ft_exit("fork() failed", EXIT_FAILURE);
	if (id == 0)
		if (ft_exec(argv[2], envp) == -1)
			ft_exit("Bad function call", EXIT_FAILURE);
	id2 = fork();
	if (id2 == -1)
		ft_exit("fork() failed", EXIT_FAILURE);
	if (id2 == 0)
		if (ft_exec(argv[3], envp) == -1)
			ft_exit("Bad function call", EXIT_FAILURE);
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
	ft_printf("Function executed with succes\n");
	return (0);
}
