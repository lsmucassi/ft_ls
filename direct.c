/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:33:44 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/29 17:00:35 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files		*get_finfo(char *file_name, char islink)
{
	struct stat buff;
	t_files		*file;

	file = (t_files *)ft_memmalloc(sizeof(t_files));
	if (lstat(file_name, &buff) == -1)
		return (NULL);
	if (islink)
	{
		if (stat(file_name, &buff) == -1)
			return (NULL);
	}
	file->device = buff.st_rdev;
	file->name = ft_strdup(file_name);
	file->type = file_type(buff.st_mode);
	file->permit = file_permit(buff.st_mode);
	file->links = buff.st_nlink;
	file->owner = get_owner(buff);
	file->group = get_group(buff);
	file->size = buff.st_size;
	file->blocks = buff.st_blocks;
	file->date = get_date(buff);
	file->timestamp = buff.st_mtimespec.tv_sec;
	file->next = NULL;
	return (file);
}

int		read_direct(t_files *cur_dir, t_lsargs *args,
		t_files **head, t_files **rec)
{
	DIR				*dirp;
	struct dirent	*dir_entry;
	char			*full_name;
	t_files			*temp;

	if (!(dirp = opendir(cur_dir->name)))
		return (0);
	while ((dir_entry = readdir(dirp)))
	{
		if (!ft_strchr(args->opt, 'a') && dir_entry->d_name[0] == '.')
			continue ;
		full_name = strjoin_nlim(0, cur_dir->name, "/",
				dir_entry->d_name, NULL);
		if (!(temp = get_finfo(full_name, 0)))
			return (0);
		if (ft_strchr(args->opt, 'R') && temp->type == 'd' &&
				ft_strcmp(dir_entry->d_name, ".") &&
					ft_strcmp(dir_entry->d_name, ".."))
				lst_adde(rec, lstcopy_link(temp));
		temp->name = ft_strdup(dir_entry->d_name);
		temp->parent_dir = ft_strdup(cur_dir->name);
		lst_adde(head, temp);
		ft_memdel((void**)&full_name);
	}
	closedir(dirp);
	return (0);
}

void	direct(t_lsargs *args)
{
	t_files		*files_list;
	t_files		*rec;
	t_files		*cur_dir;

	cur_dir = args->dirs;
	while (cur_dir)
	{
		files_list = NULL;
		rec = NULL;
		if (read_direct(cur_dir, args, &files_list, &rec))
		{
			files_list = sort_opt(files_list, args->opt, 1);
			print_dir(files_list, (cur_dir)->name, args);
		}
		else
			print_error((cur_dir)->name, 2);
		free_list(files_list);
		if (rec)
		{
			rec = sort_opt(rec, args->opt, 1);
			concat_list(cur_dir, rec);
		}
		if ((cur_dir = cur_dir->next))
			ft_putchar('\n');
	}
}
