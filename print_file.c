/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:28:51 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/29 21:12:22 by giyant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_filesize(t_files *file, int size_col)
{
	if (file->type == 'b' || file->type == 'c')
	{
		ft_putnbr((int)major(file->device));
		ft_putstr(", ");
		ft_putnbr((int)minor(file->device));
	}
	else
	{
		space_pad(file, size_col, 2);
		ft_putnbr(file->size);
	}
}

void	print_longfile(t_files *file, char *option, int link_col, int size_col)
{
	ft_putchar(file->type);
	ft_putstr(file->permit);
	ft_putchar(' ');
	space_pad(file, link_col, 1);
	ft_putnbr(file_>links);
	ft_putchar(' ');
	if (!ft_strchr(option, 'g'))
	{
		ft_putstr(file->owner);
		ft_putchar(' ');
	}
	ft_putstr(file->group);
	ft_putchar(' ');
	print_filesize(file, size_col);
	ft_putchar(' ');
	ft_putstr(file->date);
	ft_putchar(' ');
	if (ft_strchr(option, 'G'))
		add_color(file);
	ft_putstr(file->name);
	ft_putstr("\033[0m");
	ft_putchar('\n');
}

void	print_shtfile(t_files *file, char *option)
{
	if (ft_strchr(option, 'G'))
		add_color(file);
	ft_putstr(file->name);
	ft_putstr("\033[0m");
	ft_putchar('\n');
}

void	print_dir(t_files *head, char *dir_name, t_lsargs *args)
{
	int	link_col;
	int	size_col;

	link_col = get_lencol(head, 1);
	size_col = get_lencol(head, 2);
	ft_putstr(dir_name);
	ft_putendl(":");
	if (ft_strchr(args->opt, '1') && head)
	{
		ft_putstr("total ");
		ft_putnbr(get_totcol(head));
		ft_putchar(' ');
	}
	while (head)
	{
		if (ft_strchr(args->opt, 's'))
		{
			ft_putnbr(head->blocks);
			ft_putchar(' ');
		}
		print_file(head, args, link_col, size_col);
		head = head->next;
	}
}

void	print_file(t_files *file, t_lsargs *argsi, int link_col, int size_col)
{
	if (ft_strchr(args->opt, '1'))
		print_longfile(file, args->opt, link_col, size_col);
	else
		print_shtfile(file, args->opt);
}
