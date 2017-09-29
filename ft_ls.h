/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:13:19 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/27 16:18:25 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "libft/lift.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types>

typedef	struct		s_files
{
	dev_t			device;
	char			*permit;
	char			*owner;
	char			*group;
	char			*name;
	char			*parent_dir;
	char			*date;
	char			type;
	int				links;
	int				size;
	int				blocks;
	unsigned int	timestamp;
	struct s_files	*next;
}			t_files;

typedef	struct		s_lsargs
{
	char			*auth_opt;
	char			*opt;
	t_files			*dirs;
}			t_lsargs;

void		check_args(int ac, char **av, t_lsargs *ls_args);
void		direct(t_lsargs *args);
void		lst_adde(t_files **head, t_files *new);
void		lst_insertafter(t_files *target, char *new);
void		concat_list(t_files *target, t_list *new);
void		print_dir(t_files *head, char *dir_name, t_lsargs *args);
void		print_file(t_files *file, t_lsargs *args, int links, int size);
void		space_pad(t_files *file, int size, char field);
void		add_color(t_files *file);
void		print_err(char *mess, int time);
void		error_mess(char *mess, int term);
void		free_one(t_files *head);
void		free_list(t_files *head);
void		free_struct(t_lsargs *args);

t_files		*get_finfo(char *file_name, char islink);
t_files		*lstcopy_link(t_files *link);
t_files		*sort_opt(t_files *head, char *opt, char name);

char		*file_permit(mode_t file_mode);
char		file_type(mode_t file_mode);
char		*get_date(struct stat info);
char		*get_group(struct stat info);
char		*get_owner(struct stat info);

int			get_col(t_files *head, char *field);
int			get_tot(t_files *head);

#endif
