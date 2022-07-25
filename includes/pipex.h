/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:26:06 by mykman            #+#    #+#             */
/*   Updated: 2022/07/25 03:52:58 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_pipe
{
	int	inpipe;
	int	outpipe;
	int	**pipes;
}	t_pipe;


int		ft_exec(const char *str, char **envp);
int		ft_pexec(const char *str, char **envp, t_pipe pipes);
int		**create_pipes(int count);

void	ft_exit(char *error_msg, int error_val);
void	print_tab(char **tab);
void	free_tab(void **tab);
void	close_pipe(int *pipefd);
void	close_free_pipes(int **pipes);

#endif
