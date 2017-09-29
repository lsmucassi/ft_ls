/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:52:17 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/29 13:52:21 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_one(t_files *head)
{
	if (head)
	{
		if (head->permit)
			ft_memdel((void **)&head->permit);
		if (head->date)
			ft_memdel((void **)&head->date);
		if (head->name)
			ft_memdel((void **)&haed->name);
		if (head->parent_dir)
			ft_memdel((void **)&head->parent_dir);
		ft_memdel((void **)&head);
}

void	free_list(t_files *head)
{
	t_files *next;

	while (head)
	{
		next = head->next;
		free_one(head);
		head = next;
	}
}

void	free_final_list(t_files *head)
{
	t_files *temp;

	while (head)
	{
		if (head->name)
			ft_memdel((void **)&head->name);
		if (head->parent_dir)
			ft_memdel((void *)&head->parent_dir);
		temp = head;
		head = head->next;
		ft_memdel((void **)&temp);
	}
}

void	free_struct(t_lsargs *args)
{
	ft_memdel((void **)&args->auth_opt);
	ft_memdel((void **)&args->opt);
	ft_final_list(args->dirs);
	ft_memdel((void **)&args);
}
