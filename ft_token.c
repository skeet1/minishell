/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:42:10 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/03 08:31:31 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_num_cmd_side(t_data *data, char *s)
{
	int	i;
	int side;

	i = 0;
	side = 1;
	while (s[i])
	{
		if (s[i] == '|' )
			side++;
		i++;
	}
	data->side = side;
}

void	ft_token(t_data *data, char *s)
{
	int     i;
	int		start;
	int		token = 0;
	int		side = 1;

	i = 0;
	start = i;
	ft_num_cmd_side(data, s);
	data->cmd_sides = ft_split(s, '|');
	ft_token_side(data);
	printf("sides : %d\n", data->side);
}