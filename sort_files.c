
#include "ft_ls.h"

t_files		*sort_byname(t_files *head)
{
	t_files	*ptr;
	t_files	*prev;
	t_files	*temp;

	ptr = head;
	prev = ptr;
	while (ptr->next)
	{
		if (ft_strcmp(ptr->name, (ptr->next)->name) > 0)
		{
			head = (ptr == head) ? ptr->next : head;
			prev->next = ptr->next;
			temp = (ptr->next)->next;
			(ptr->next)->next = ptr;
			ptr->next = temp;
			ptr = head;
			prev = ptr;
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
	}
	return (head);
}

t_files		*sort_bydate(t_files *head)
{
	t_files	*ptr;
	t_files	*prev;
	t_files	*temp;

	ptr = head;
	prev ptr;
	while (ptr->next)
	{
		if (ptr->timestamp < (ptr->next)->timestamp)
		{
			head = (ptr == head) ? ptr->next : head;
			prev->next = ptr->next;
			temp = (ptr->next)->next;
			(ptr->next)->next = ptr;
			ptr->next = temp;
			ptr = head;
			prev = ptr;
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
	}
	return (head);
}

t_files		*sort_bysize(t_files *head)
{
	t_files	*ptr;
	t_files	*prev;
	t_files	*temp;

	ptr = head;
	prev = ptr;
	while (ptr->next)
	{
		if (ptr->size < (ptr->next)->size)
		{
			head = (ptr == head) ? ptr->next : head;
			prev->next = ptr->next;
			temp = (ptr->next)->next;
			(ptr->next)->next = ptr;
			ptr->next = temp;
			prev = ptr;
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
	}
	return (head);
}

t_files		*rev_list(t_files *head)
{
	t_files	*ptr;
	t_files	*prev;
	t_files	*temp;

	ptr = head->next;
	prev = head;
	while (head->next)
		head = head->next;
	prev->next = NULL;
	while (ptr)
	{
		temp = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = temp;
	}
	return (head);
}

t_files		*sort_fromopt(t_files *head, char *option, char by_name)
{
	if (head && !ft_strchr(option, 'f'))
	{
		if (by_name)
			head = sort_byname(head);
		if (ft-strchr(option, 't'))
			head = sort_bydate(head);
		else if (ft_strchr(option, 's'))
			head = sort_bysize(head);
		if (ft_strchr(option, 'r'))
			head = rev_list(head);
	}
	return (head);
}
