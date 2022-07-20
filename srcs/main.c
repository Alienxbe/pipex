/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:26:06 by mykman            #+#    #+#             */
/*   Updated: 2022/07/20 17:26:23 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char const **argv)
{
	char	*args[] = {"Hello", "World", "What", NULL};

	(void)argc;
	(void)argv;
	execve("/bin/echo", args, NULL);
	ft_printf("hello world\n");
	return (0);
}
