/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:34:37 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/04 12:33:12 by mkarim           ###   ########.fr       */
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
	int		quotes[2];

	quotes[0] = 0;
	quotes[1] = 0;
	i = 0;
	if (s[0] == '|' || s[ft_strlen(s) - 1] == '|')
		return (ft_putstr(SNT_ERR), ft_putendl("|'"), 1);
	while (s[i])
	{
		if (s[i] == '\'')
			quotes[0]++;
		else if (s[i] == '"')
			quotes[1]++;
		while (quotes[0] % 2 || quotes[1] % 2)
		{
			if (s[i] == '\'')
				quotes[0]++;
			else if (s[i] == '"')
				quotes[1]++;
			i++;
		}
		pipe = 0;
		if (s[i] == '|')
			pipe = 1;
		while (ft_isspace(s[i]))
			i++;
		if (s[i] == '|' && pipe)
			return (ft_putendl("repeted pipes error"), 1);
		i++;
	}
	return (0);
}

int	check_red(char *s)
{
	return (0);
}

int	ft_check_syntax(char *s)
{
	if (check_quotes(s) || check_pipes(s)
		|| check_red(s))
		return (1);
	return (0);
}