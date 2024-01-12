/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:23:41 by abelov            #+#    #+#             */
/*   Updated: 2024/01/02 21:23:44 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sysexits.h>
#include "push_swap.h"

void	dnode_print(void *data, void *user_data)
{
	(void)user_data;
	ft_printf("%d\n", *(int *)data);
}

typedef void	(*t_dispatch_f)(t_dlist *dlist_a, t_dlist *dlist_b);

void	do_swap_a(t_dlist *dlist_a, t_dlist *dlist_b)
{
	t_dnode	*dnode1;
	t_dnode	*dnode2;

	(void )dlist_b;
	if (dlist_a->size > 1) {
		dnode1 = ft_dlist_pop(dlist_a);
		dnode2 = ft_dlist_pop(dlist_a);
		ft_dlist_push(dlist_a, dnode1);
		ft_dlist_push(dlist_a, dnode2);
	}
}
void	do_swap_b(t_dlist *dlist_a, t_dlist *dlist_b)
{
	t_dnode	*dnode1;
	t_dnode	*dnode2;

	(void )dlist_b;
	if (dlist_a->size > 1) {
		dnode1 = ft_dlist_pop(dlist_b);
		dnode2 = ft_dlist_pop(dlist_b);
		ft_dlist_push(dlist_b, dnode1);
		ft_dlist_push(dlist_b, dnode2);
	}
}

void	do_push_a(t_dlist *dlist_a, t_dlist *dlist_b)
{
	t_dnode	*dnode;

	dnode = ft_dlist_pop(dlist_b);
	ft_dlist_push(dlist_a, dnode);
}


void	do_push_b(t_dlist *dlist_a, t_dlist *dlist_b)
{
	t_dnode	*dnode;

	dnode = ft_dlist_pop(dlist_a);
	ft_dlist_push(dlist_b, dnode);
}

static t_dispatch_f const	push_dispatch[] = {
		[sa] = do_swap_a,
		[sb] = do_swap_b,
		[pb] = do_push_b,
		[pa] = do_push_a
};

int	main(int argc, char **argv)
{
	int		argg;
	char	*str;
	char	*tok;
	char	*str0;
	char	*saveptr;
	char	buf[4];
	int32_t	i;
	t_dlist	*dlist_a;
	t_dlist	*dlist_b;

	if (argc < 1)
		return (EX_NOINPUT);
	argg = 1;
	dlist_a = ft_dlst_new();
	dlist_b = ft_dlst_new();
	while (argg < argc)
		ft_dlist_append(dlist_a, ft_atoi(argv[argg++]));
	ft_printf("stack a:\n");
	ft_dlist_foreach(dlist_a, dnode_print, NULL);
	ft_printf("stack b:\n");
	ft_dlist_foreach(dlist_b, dnode_print, NULL);

	str = "pb pb pb sa pa pa pa";
	str = getenv("ARG");
	if(!str)
		return (EX_UNAVAILABLE);
	str0 = ft_strtrim(str, "' '");
	tok = ft_strtok_r(str0, " ", &saveptr);
	while (tok && *tok)
	{
		*(int32_t *)buf = 0;
		ft_strncpy(buf, tok, 3);
		i = *(int32_t *)buf;

		if (push_dispatch[i])
			push_dispatch[i](dlist_a, dlist_b);
		tok = ft_strtok_r(NULL, " ", &saveptr);
	}
	ft_printf("=========\n");
//	ft_printf("%s\n", (char *)(int []){sa});
	ft_printf("stack a:\n");
	ft_dlist_foreach(dlist_a, dnode_print, NULL);
	ft_printf("stack b:\n");
	ft_dlist_foreach(dlist_b, dnode_print, NULL);
	free(str0);
	ft_dlist_free_full(&dlist_a);
	ft_dlist_free_full(&dlist_b);

	return (EX_OK);
}
