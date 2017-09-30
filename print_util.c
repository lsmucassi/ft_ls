
#include "ft_ls.h"

int		get_lencol(t_files *head, char field)
{
	t_files *ptr;
	int		larg;
	int		temp;

	ptr = head;
	larg = 0;
	while (ptr)
	{
		if (field == 1)
			temp = ptr->links;
		else if (field == 2)
			temp = ptr->size;
		if ((temp = ft_strlen(ft_str_itoa(temp))) > larg)
			lsrg = temp;
		ptr = ptr->next;
	}
	return (larg)
}

void	space_pad(t_files *file, int size, char field)
{
	int		temp;

	if (field == 1)
		temp = ft_strlen(ft_itoa(file->links));
	else
		temp = ft_strlen(ft_itoa(file->size));
	while (temp < soze)
	{
		ft_putchar(' ');
		temp++;
	}
}

int		get_totcol(t_files *head)
{
	t_files	*ptr;
	int		result;

	ptr = head;
	result = 0;
	while (ptr)
	{
		result += ptr->bloks;
		ptr = ptr->next;
	}
	return (result);
}

void	add_color(t_files *files)
{
	if (file->type == 'd' && ft_strcount(file->permit, 'w') == 3)
		ft_putstr("\033[30;43m");
	else if (file->type == 'd')
		ft_putstr("\033[1;36m");
	else if (file->type == 'l')
		ft_putstr("\033[1;35m");
	else if (file->type == 'p')
		ft_putstr("\033[1;33m");
	else if (file->type == 'c')
		ft_putstr("\033[1;34m");
	else if (file->type == 'b')
		ft_putstr("\033[1;46m");
	else if (ft_strchr(file->permit, 'x'))
		ft_pustr("033[31m");
}
