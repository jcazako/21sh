#include "ft_sh.h"

int	putit(int c)
{
	ft_putchar(c);
	return (0);
}

void	del_key(t_key *ct, size_t ct_size)
{
	ft_bzero(ct, ct_size);
	free(ct);
}

void	del_data(t_sh *data, size_t ct_size)
{
	ft_dlstdel(&data->lst_key, (void(*)(void*, size_t))del_key);
	ft_bzero(data, ct_size);
	free(data);
}

void	init_data(t_sh *data)
{
	data->lst_key = NULL;
	data->index = 0;
}

void	print_lst_key(t_sh* data)
{
	t_dlist	*lst_key;
	int	key;

	lst_key = data->lst_key;
	while (lst_key)
	{
		key = KEY(lst_key);
		write(1, &key, 4);
		lst_key = lst_key->next;
	}
}

int	main(int ac, char **av, char **env)
{
	t_sh	*data;
	int	ret;

	(void)ac;
	(void)av;
	(void)env;
	data = ret_data();
	if ((ret = init_term(data)))
		return (ret);
	init_data(data);
	ft_printf("21sh> ");
	while (42)
	{
		if (get_key(data))
			break ;
	}
	ft_printf("\nline: ");
	print_lst_key(data);
	ft_putchar('\n');
	del_data(data, sizeof(t_sh));
	return (0);
}