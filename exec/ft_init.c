/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:43:04 by atabiti           #+#    #+#             */
/*   Updated: 2022/07/17 15:18:45 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minishell.h"

int	ft_init(t_cmd *cmds)
{
	cmds->cmdnbr = 0;
	cmds->binfolder = NULL;
	cmds->cmdnbr = 0;
	cmds->cmd_iteration = 0;
	cmds->envvarpos = 0;
	cmds->fd_out = 1;
	return (0);
}
