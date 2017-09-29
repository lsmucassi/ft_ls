/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_finfo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:49:11 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/29 14:02:07 by lmucassi         ###   ########.fr       */
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
	char	*time_tabnow;
	time_t	now;

	now = time(NULL);
	time_now = &ctime(now);
	time_tabnow = ft_strplit(ft_strtrim(time_now), ' ');
	time_file = ft_strtrim(ctime(&(info.st_mtimespec.tv_sec)));
	time_tabfile = ft_strsplit(time_file, ' ');
	if (!ft_strcmp(time_tabnow[4], time_tabfile[4]))
	{
		time_tabfile[3][5] = 0;
		time_file = ft_strjoin
