/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:46:03 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/16 15:57:14 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ft_sort_three(t_node *deque_a)
{
	if (deque_a->val > deque_a->next->val)
	{
		if (deque_a->val < deque_a->next->next->val)
			execute(&deque_a, NULL, "sa", 0);
		else if (deque_a->next->val > deque_a->next->next->val)
		{
			execute(&deque_a, NULL, "sa", 0);
			execute(&deque_a, NULL, "rra", 0);
		}
		else
			execute(&deque_a, NULL, "ra", 0);
	}
	else if (deque_a->val < deque_a->next->val)
	{
		if (deque_a->val > deque_a->next->next->val)
			execute(&deque_a, NULL, "rra", 0);
		else if (deque_a->next->val > deque_a->next->next->val)
		{
			execute(&deque_a, NULL, "sa", 0);
			execute(&deque_a, NULL, "ra", 0);
		}
	}
}

void	ft_quicksort(t_node *deque_a, t_node *deque_b)
{
	int	i;
	int	pos[2];
	int	mode;

	multi_execute(&deque_a, &deque_b, "pb", 2);
	while (stack_len(deque_a) > 3)
	{
		pos[0] = find_min_index(deque_a, deque_b, stack_len(deque_a));
		i = -1;
		while (++i < pos[0])
			deque_a = deque_a->next;
		pos[1] = execute_calc(deque_a, deque_b, stack_len(deque_a), true);
		mode = lcm(pos, stack_len(deque_a), stack_len(deque_b), true);
		if (mode == 1)
			reverse_pos(&deque_a, &deque_b, pos);
		execute_ps(&deque_a, &deque_b, pos, mode);
		execute(&deque_a, &deque_b, "pb", false);
	}
	sort_three(deque_a);
	while (stack_len(deque_b) > 0)
	{
		target_push(deque_a, find_target(deque_b, deque_a));
		execute(&deque_a, &deque_b, "pa", false);
	}
	min_max_push(deque_a, false);
}


void	push_swap(t_node *deque_a, t_node *deque_b, int len)
{
	if (ft_lst_is_sorted(deque_a, 0))
		return ;
	if (len == 2)
		ft_execute(&deque_a, &deque_b, "sa", 0);
	else if (len == 3)
		ft_sort_three(deque_a);
	else
		ft_quicksort(deque_a, deque_b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_node	*deque_a;
	t_node	*deque_b;

	i = 0;
	deque_a = NULL;
	deque_b = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = -1;
	}
	if (argc > 1)
	{
		while (argv[++i])
		{
			if (ft_is_valid(deque_a, argv[i]) == 0)
				ft_free_stop(deque_a, ERROR_MSG_INPUT);
			deque_a = add_node(deque_a, ft_atoi(argv[i]));
		}
		push_swap(deque_a, deque_b, ft_lst_size(deque_a));
		ft_lst_clear(deque_a);
		ft_lst_clear(deque_b);
	}
	return (0);
}
