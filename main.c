/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:16:25 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/29 16:59:33 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_lsargs	*ls_args;

	if (!(ls_args = (t_lsargs *)ft_memalloc(sizeof(t_lsargs))))
		return (0);
	ls_args->auth_opt = ft_strdup("Ralrt");
	check_args(ac, av, ls_args);
	ls_args->dirs = sort_opt(ls_args->dirs, ls_args->opt, 1);
	browse_direct(ls_args);
	free_struct(ls_args);
	return (0);
}
