/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:34:37 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/04 09:56:50 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_quotes(char *s)
{
	int		i;
	int		quotes[2];

	quotes[0] = 0;
	quotes[1] = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			quotes[0]++;
		else if (s[i] == '"')
			quotes[1]++;
		i++;
	}
	if (quotes[0] % 2 || quotes[1] % 2)
		return (ft_putendl("quotes syntax error"), 1);
	return (0);
}

int	check_pipes(char *s)
{
	int		i;
	int		pipe;

	i = 0;
	if (s[0] == '|' || s[ft_strlen(s) - 1] == '|')
		return (ft_putendl("pipe error"), 1);
	while (s[i])
	{
		pipe = 0;
		if (s[i] == '|')
			pipe = 1;
		while (ft_isspace(s[i]))
			i++;
		if (s[i] == '|')
			return (ft_putendl("repeted pipes error"), 1);
		i++;
	}
	return (0);
}

int	ft_check_syntax(t_data *data)
{
	if (check_quotes(data->cmd_line) || check_pipes(data->cmd_line))
		return (1);
	return (0);
}