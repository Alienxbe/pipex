/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:26:06 by mykman            #+#    #+#             */
/*   Updated: 2022/07/26 00:15:35 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

int		ft_exec(const char *str, char **envp);
void	ft_pexec(const char *str, char **envp);

void	ft_exit(char *error_msg, int error_val);
void	print_tab(char **tab);
void	free_tab(void **tab);
void	close_pipe(int *pipefd);

#endif
