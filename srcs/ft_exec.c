/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:10:33 by mykman            #+#    #+#             */
/*   Updated: 2022/07/24 14:02:59 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_envpvar(char **envp, const char *varname)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strstartwith(envp[i], varname))
		i++;
	return (envp[i]);
}

char	*test_path(char **path_list, char *cmd)
{
	char	*path;
	int		i;
	
	i = -1;
	while (path_list[++i])
	{
		path = ft_strjoinx(3, path_list[i], "/", cmd);
		if (!path)
			return (NULL);
		if (!access(path, F_OK))
			if (!access(path, X_OK))
				return (path);
		free(path);
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**path_list;
	char	*path;
	char	*envp_path;

	envp_path = get_envpvar(envp, "PATH=");
	if (!envp_path)
		return (NULL);
	path_list = ft_split(envp_path + ft_strlen("PATH="), ':');
	if (!path_list)
		return (NULL);
	path = test_path(path_list, cmd);
	free_tab((void **)path_list);
	return (path);
}

int	ft_exec(const char *str, char **envp)
{
	char	**args;
	char	*path;
	int		ret;

	args = ft_split(str, ' ');
	if (!args)
		return (-1);
	path = get_path(args[0], envp);
	ret = execve(path, args, envp);
	free(path);
	free_tab((void **)args);
	return (ret);
}
