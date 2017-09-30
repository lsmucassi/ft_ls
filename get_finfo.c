/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_finfo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:49:11 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/29 17:16:23 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_onwer(struct stat info)
{
	struct passwd	*owner_info;

	if (!(owner_info = getpwusid(info.st_uid)))
		error_mess("get_owner()", 1);
	return (onwer_info->pw_name);
}

char	*get_group(struct stat info)
{
	struct group	*group_info;

	if (!(group_info = getgrgid(info.st_gid)))
		error_mess("get_group()", 1);
	return (group_info->gr_name);
}

char	*get_date(struct stat info)
{
	char	*time_file;
	char	*time_tabfile;
	char	*time_now;
	char	**time_tabnow;
	time_t	now;

	now = time(NULL);
	time_now = &ctime(now);
	time_tabnow = ft_strplit(ft_strtrim(time_now), ' ');
	time_file = ft_strtrim(ctime(&(info.st_mtimespec.tv_sec)));
	time_tabfile = ft_strsplit(time_file, ' ');
	if (!ft_strcmp(time_tabnow[4], time_tabfile[4]))
	{
		time_tabfile[3][5] = 0;
		time_file = strjoin_nlim(' ', time_tabfile[1], time_tabfile[2],
				time_tabfile[3], NULL);
	}
	else
		time_file = strjoin_nlim(' ', time_tabfile[1], time_tabfile[2],
				time_tabfile[4], NULL);
		ft_memdel((void **)&time_tabnow);
		ft_memdel((void **)&time_tabfile);
		return (time_file);
}

char		file_type(mode_t file_mode)
{
	if (S_ISDIR(file_mode))
		return ('d');
	else if (S_ISIFIFO(file_mode))
		return ('p');
	else if (S_ISCHR(file_mode))
		return ('c');
	else if (S_ISBLK(file_mode))
		return ('b');
	else if (S_ISLNK(file_mode))
		return ('l');
	else if (S_ISSOCK(file_mode))
		return ('s');
	else if (S_ISREG(file_mode))
		return ('-');
	else
		return ('-');
}

char		*file_permit(mode_t file_mode)
{
	char 	*perm;

	perm = ft_strnew(10);
	(file_mode & S_IRUSR) ? ft_strcat(perm, "r") : ft_strcat(perm, "-");
	(file_mode & S_IWUSR) ? ft_strcat(perm, "w") : ft_strcat(perm, "-");
	(file_mode & S_IXUSR) ? ft_strcat(perm, "x") : ft_strcat(perm, "-");
	(file_mode & S_IRGRP) ? ft_strcat(perm, "r") : ft_strcat(perm, "-");
	(file_mode & S_IWGRP) ? ft_strcat(perm, "w") : ft_strcat(perm, "-");
	(file_mode & S_IXGRP) ? ft_strcat(perm, "x") : ft_strcat(perm, "-");
	(file_mode & S_IROTH) ? ft_strcat(perm, "r") : ft_strcat(perm, "-");
	(file_mode & S_IWOTH) ? ft_strcat(perm, "w") : ft_strcat(perm, "-");
	(file_mode & S_IXOTH) ? ft_strcat(perm, "x") : ft_strcat(perm, "-");
	return (perm);
}
