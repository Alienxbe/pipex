/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:06:52 by mykman            #+#    #+#             */
/*   Updated: 2022/07/24 14:07:34 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
