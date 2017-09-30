
#include "ft_ls.h"

void	lst_adde(t_files **head, t_files *new)
{
	t_files	*temp;

	if (!(*head))
		*head = new;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	lst_insertafter(t_files *target, char *new)
{
	t_files *new_dir;

	newdir = (t_files *)ft_memalloc(sizeof(t_files));
	new_dir->name = ft_strdup(new);
	new_dir->next = targert->next;
	target->next = new_dir;
}

t_files *lstcopy_link(t_files *link)
{
	t_files *copy;
	copy = (t_files *)ft_memalloc(sizeof(t_files));
	copy = (t_files *)ft_memcpy(copy, link, sizeof(t_files));
	return(copy);
}

void	concat_list(t_files *target, t_files *new)
{
	t_files *temp;

	temp = target->next;
	target->next = new;
	while (new->next)
		new = new->next;
	new->next = temp;
}
