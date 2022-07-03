/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_perfect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:33:49 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/03 17:47:37 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_special(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == '\'' || c == '"')
		return (1);
	return (0);
}

int	right_len(char *s)
{
	int		i;
	int		len;
	int		quotes[2];

	i = 1;
	len = 1;
	quotes[0] = 1;
	quotes[1] = 1;
	while (s[i])
	{
		if (s[i] == '\'')
			quotes[0]++;
		else if (s[i] == '"')
			quotes[1]++;
		if (quotes[0] % 2 == 0 || quotes[1] % 2 == 0)
			len++;
		else if (is_special(s[i]))
		{
			while (is_special(s[i]))
			{
				len++;
				i++;
			}
			len += 3;
		}
		else if (!ft_isspace(s[i]))
			len++;
		else
		{
			len++;
			while (ft_isspace(s[i]) && ft_isspace(s[i - 1]))
				i++;
		}
		i++;
	}
	return (len);
}

char	*put_cmd(char *s, int len)
{
	char	*cmd;
	int		i;
	int		j;
	int		quotes[2];

	cmd = malloc(len + 1);
	if (!cmd)
		return (cmd);
	i = 0;
	j = 0;
	quotes[0] = 1;
	quotes[1] = 1;
	while (s[i])
	{
		// printf("now is : %c\n", s[i]);
		if (s[i] == '\'')
			quotes[0]++;
		else if (s[i] == '"')
			quotes[1]++;
		if (quotes[0] % 2 == 0 || quotes[1] % 2 == 0)
			cmd[j++] = s[i];
		else if (is_special(s[i]))
		{
			cmd[j++] = ' ';
			while (!ft_isspace(s[i]))
			{
				cmd[j++] = s[i];
				i++;
			}
			cmd[j++] = ' ';
		}
		else if (!ft_isspace(s[i]))
			cmd[j++] = s[i];
		else
		{
			// cmd[j++] = ' ';
			while (ft_isspace(s[i]) && ft_isspace(s[i - 1]))
				i++;
			cmd[j++] = s[i];
		}
		i++;
	}
	cmd[j] = '\0';
	return (cmd);
}

void    make_cmd_perfect(t_data *data, char *s)
{
	int		len;

	len = right_len(s);
	printf("len is %d\n", len);
	data->cmd_line = put_cmd(s, len);
	printf("%s\n", data->cmd_line);
}