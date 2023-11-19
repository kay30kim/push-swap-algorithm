/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:46:03 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/19 17:24:35 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_deque *a, t_list *cmnd)
{
	t_lst *tmp;
	t_list	*tmp_a;

	while (a->head)
	{
		tmp = a->head;
		a->head = a->head->next;
		free(tmp);
	}
	while (cmnd)
	{
		tmp_a = cmnd;
		free(cmnd->content);
		cmnd = cmnd->next;
		free(tmp_a);
	}
	free(a->p);
}

void	make_deque(t_deque *deque_a, t_deque *deque_b, char **av, int ac)
{
	int		i;

	i = 1;
	if (ac == 2)
		i = 0;
	if (!is_digit(ac, av) || !(deque_a->head = malloc(sizeof(t_lst))) || is_duplicated(av, i))
		error_exit();
	deque_a->head->num = ft_atoi(av[i++]);
	deque_a->head->prev = NULL;
	deque_a->end = deque_a->head;
	while (av[i++])
		lst_addback(av[i++], &deque_a->end);
	deque_b->head = NULL;
	deque_b->end = NULL;
}

int		main(int ac, char **av)
{
	t_deque	deque_a;
	t_deque	deque_b;
	t_list	*cmnd;

	if (ac == 2)
		av = ft_split(av[1], ' ');
	make_deque(&deque_a, &deque_b, av, ac);
	if (!(deque_a.p = malloc(sizeof(t_lst*) * ac)) ||
	!(deque_b.p = malloc(sizeof(t_lst*) * ac)))
		exit(1);
	deque_a.ac = ac;
	deque_b.ac = ac;
	deque_a.top = 0;
	deque_b.top = 0;
	deque_a.p[deque_a.top] = NULL;
	deque_b.p[deque_a.top] = NULL;
	cmnd = quick_sort(&deque_a, &deque_b);
	while (cmnd != NULL)
	{
		ft_putstr_fd((char *)cmnd->content, 1);
		cmnd = cmnd->next;
	}
	free(deque_b.p);
	free_all(&deque_a, cmnd);
}
