/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:59:44 by nleggeri          #+#    #+#             */
/*   Updated: 2023/03/30 17:00:46 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	search_path_in_env(char **envp)
{
	int	j;

	j = 0;
	while (envp[j])
	{
		if (envp[j][0] == 'P' && envp[j][1] == 'A' \
			&& envp[j][2] == 'T' && envp[j][3] == 'H')
			break ;
		j++;
	}
	return (j);
}

char	*join_all_path(char *env, char *cmd, char slash)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!env || !cmd)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(env) + ft_strlen(cmd) + slash + 1));
	if (!join)
		return (NULL);
	while (env[i])
		join[j++] = env[i++];
	join[j] = slash;
	j++;
	i = 0;
	while (cmd[i])
		join[j++] = cmd[i++];
	join[j] = '\0';
	return (join);
}

char	*existence_of_cmd(char **env, char *cmd)
{
	int		j;
	char	*tmp;

	j = -1;
	while (env[++j])
	{
		tmp = join_all_path(env[j], cmd, '/');
		if (access(tmp, F_OK) == 0)
			return (tmp);
		free(tmp);
	}
	return (NULL);
}
