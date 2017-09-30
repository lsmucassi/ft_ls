
#include "ft_ls.h"

static int	is_opt(char *arg, t_lsargs *ls_args)
{
	while (*arg)
	{
		if (!ft_strchr(ls_args->auth_opt, *arg) || !ft_isalnum(*arg))
		{
			ft_putstr("ls : illegal option -- ");
			ft_putchar(*arg);
			ft_putchar('\n');
			ft_putstr("usage: ls [-");
			ft_putstr(ls_args->auth_opt);
			ft_putendl("] [file ...]");
			exit(0);
		}
		arg++;
	}
	return (1);
}

static int	store_reqdir(char *dir_name, t_lsargs *ls_args)
{
	t_files	*new_dir;

	if (!(new_dir = get_file(dir_name, 0)))
		return (0);
	if (new_dir->type != 'd')
	{
		if (new_dir->type == '1' && !ft_strchr(ls_args->opt, '1'))
		{
			if (!(new_dir = get_finfo(dir_name, 1)))
				return (0);
		}
		else
		{
			print_file(new_dir ls_args, 0, 0);
			return (1);
		}
	}
	lst_adde(&(ls_args->dirs), new_dir);
	return (1);
}

static void	modify_opt(char **option)
{
	char	*temp;

	if (ft_strchr(*option, 'g'))
	{
		temp = ft_strjoin(*option, "1");
		ft_memdel((void **)option);
		*option = ft_strdup(temp);
	}
	if (ft_strchr(*option, 'f'))
	{
		temp = ft_strjoin(*option, "a");
		ft_memdel((void **)option);
		*option = ft_strdup(tmp);
	}
}

void	check_args(int ac, char **av, t_lsargs *ls_args)
{
	int		i;
	char	*arg_lst;

	i = 0;
	arg_lst = ft_strnew(2);
	while (++i < ac && av[i][0] == '-' && is_opt(&av[i][1], ls_args))
	{
		arg_lst = ft_mem_realloc(arg_lst, ft_strlen(arg_lst)
				+ ft_strlen(av[i]));
		arg_lst = ft_strcat(args_lst, &av[i][1]);
	}
	modify_opt(&arg_lst);
	ls_args->opt = ft_strdup(arg_lst);
	ft_memdel((void **)&arg-lst);
	if (i == ac)
		store_reqdir(".", ls_args);
	while (i < ac)
	{
		if (!store_reqdir(av[i], ls_args))
			print_err(av[i], 1);
		i++;
	}
}
