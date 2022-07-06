/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:47:50 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/06 08:14:08 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
	{
		while (1)
		{
			data.cmd_line = readline(PROMPT);
			add_history(data.cmd_line);
			data.cmd_line = ft_strtrim(data.cmd_line, " ");
			ft_token(&data, data.cmd_line);
		}
	}
}