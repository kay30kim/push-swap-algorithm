/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:29:43 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/24 18:35:04 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_every(t_node *deque_a, t_node *deque_b, int len, char cha)
{
	printf("[%c]  len = %d\n", cha, len);
	t_node	*tmp1 = deque_a;
	t_node	*tmp2 = deque_b;

	printf("A : ");
	while (tmp1)
	{
		printf("%d ", tmp1->val);
		tmp1 = tmp1->next;
	}
	printf("\n");

	printf("B : ");
	while (tmp2)
	{
		printf("%d ", tmp2->val);
		tmp2 = tmp2->next;
	}
	printf("\n\n");
}

int	ft_less_three_a(t_node *deque_a, t_node *deque_b, int len)
{
	if (len == 2)
		ft_do_instruction(&deque_a, &deque_b, "sa", 0);
	else if (len == 3)
		ft_sort_three_a(deque_a);
	return (1);
}

int	ft_less_three_b(t_node *deque_a, t_node *deque_b, int len)
{
	if (len == 2)
	{
		printf("come\n");
		ft_do_instruction(&deque_a, &deque_b, "sb", 0);
		print_every(deque_a, deque_b, len, 'z');
		ft_do_multi_instruction(&deque_a, &deque_b, "pa", 2);
		print_every(deque_a, deque_b, len, 'P');
	}
	else if (len == 3)
		ft_sort_three_b(deque_a, deque_b);
	return (1);
}

int	ft_quicksort_a(t_node *deque_a, t_node *deque_b, int len)
{
	int	pivot;
	int	num;
	int	pushed_under;

	print_every(deque_a, deque_b, len, 'a');
	if (ft_lst_is_sorted(deque_a, INCREASING))
		return (1);
	if ((num = len) && len <= 3)
	{
		printf("please\n");
		return (ft_less_three_a(deque_a, deque_b, len));
	}
	pushed_under = 0;
	if (!get_pivot(&pivot, deque_a, len))
		return (0);
	printf("pivot = %d\n", pivot);
	while (len != num / 2 + num % 2)
	{
		if (deque_a->val < pivot && (len--))
			ft_do_instruction(&deque_a, &deque_b, "pb", 0);
		else if ((++pushed_under))
			ft_do_instruction(&deque_a, &deque_b, "ra", 0);
	}
	print_every(deque_a, deque_b, len, 'a');
	while (!ft_lst_is_sorted(deque_a, INCREASING) && pushed_under--)
		ft_do_instruction(&deque_a, &deque_b, "rra", 0);
	printf("finish\n");
	return (ft_quicksort_a(deque_a, deque_b, num / 2 + num % 2)
		&& ft_quicksort_b(deque_a, deque_b, num / 2));
}

int	ft_quicksort_b(t_node *deque_a, t_node *deque_b, int len)
{
	int	pivot;
	int	num;
	int	pushed_under;

	print_every(deque_a, deque_b, len, 'b');
	pushed_under = 0;
	if (ft_lst_is_sorted(deque_b, DESCENDING))
		while (len--)
			ft_do_instruction(&deque_a, &deque_b, "pa", 0);
	if (len <= 3)
		return (ft_less_three_b(deque_a, deque_b, len));
	if ((num = len) && !get_pivot(&pivot, deque_b, len))
		return (0);
	while (len != num / 2)
		if (deque_b->val >= pivot && len--)
			ft_do_instruction(&deque_a, &deque_b, "pa", 0);
		else if (++pushed_under)
			ft_do_instruction(&deque_a, &deque_b, "rb", 0);
	while (!ft_lst_is_sorted(deque_b, DESCENDING) && pushed_under--)
		ft_do_instruction(&deque_a, &deque_b, "rrb", 0);
	printf("BBB\n");
	return (ft_quicksort_a(deque_a, deque_b, num / 2 + num % 2)
		&& ft_quicksort_b(deque_a, deque_b, num / 2));
}

void	print(int *cache, int len)
{
	int	i;

	i = 0;
	printf("cache : ");
	while (i < len)
		printf("%d ", cache[i++]);
	printf("\n");
}

int		get_pivot(int *pivot, t_node *deque, int len)
{
	int		*cache;
	int		*buf;
	int		i;
	t_node	*tmp;

	tmp = deque;
	if (!(cache = (int *)malloc(sizeof(int) * len)))
		return (0);
	if (!(buf = (int *)calloc(len, sizeof(int))))
		return (0);
	i = -1;
	while (++i < len)
	{
		cache[i] = tmp->val;
		tmp = tmp->next;
	}
	ft_mergesort(0, len - 1, cache, buf);
	*pivot = cache[len / 2];
	print(cache, len);
	free(cache);
	return (1);
}