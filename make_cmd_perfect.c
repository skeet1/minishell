/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_perfect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:33:49 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/03 19:11:54 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_special(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	check_space(char *s, int i)
{
	int 	len;
	int		ret;

	ret = 0;
	len = ft_strlen(s);
	if (i && i < len - 1)
	{
		if (s[i - 1] != ' ')
			ret++;
		if (s[i + 1] != ' ')
			ret++;
	}
	else if (i)
	{
		if (s[i - 1] != ' ')
			ret++;
	}
	else
	{
		if (s[i + 1] != ' ')
			ret++;
	}
	return (ret);
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
		if (is_special(s[i]))
		{
			len += check_space(s, i);
		}
		len++;
		i++;
	}
	return (len);
}

int	space_before(char *s, int i)
{
	if (i)
		if (!ft_isspace(s[i - 1]))
			return (1);
	return (0);
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
		if (i)
		{
			if (ft_isspace(s[i]) && ft_isspace(s[i - 1]))
			{
				i++;
				continue;
			}
		}
		if (is_special(s[i]))
		{
			if (check_space(s, i) == 2)
			{
				cmd[j++] = ' ';
				cmd[j++] = s[i];
				cmd[j++] = ' ';
			}
			else if (check_space(s, i) == 1)
			{
				if (space_before(s, i))
				{
					cmd[j++] = ' ';
					cmd[j++] = s[i];
				}
				else {
					cmd[j++] = s[i];
					cmd[j++] = ' ';
				}
			}
			else
				cmd[j++] = s[i];
		}
		else
			cmd[j++] = s[i];
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