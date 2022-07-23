/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:26:06 by mykman            #+#    #+#             */
/*   Updated: 2022/07/23 02:00:45 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//execve(command, args, envp);

void	ft_exit(char *error_msg, int error_val)
{
	ft_fprintf(STDERR_FILENO, "%s\n", error_msg);
	exit(error_val);
}

void	free_tab(void **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab[i]);
	free(tab);
}

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		ft_printf("%s\n", tab[i]);
}

int main(int argc, char const **argv, char * const envp[])
{
	if (argc != 5)
		ft_exit("Usage: ./pipex infile cmd1 cmd2 outfile", EXIT_FAILURE);
	ft_exec(argv[2], envp);
	return (0);
}
