/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:18:14 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/27 16:29:34 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_err(char *mess, int time)
{
	if (time == 1)
	{
		ft_putstr("ft_ls: ");
		perror(mess);
	}
	else if (time == 2 && errno != 2)
	{
		ft_putstr(mess);
		ft_putendl(":");
		ft_putstr("ft_ls: ");
		perror(mess);
	}
}

void	err_mess(char *mess, int term)
{
	ft_putcolor("ERROR: ", "red");
	perror(message);
	if (term)
		exit(0);
}
