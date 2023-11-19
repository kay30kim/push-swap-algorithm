/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:58:59 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/19 17:40:27 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		split_a(t_deque *a, t_deque *b, t_list **cmnd)
{
	int		count;
	long	median;
	char	tmp[a->ac * 4];

	tmp[0] = '\0';
	count = get_count(a);
	median = INT32_1;
	if (count <= 11 && count > 2)
		median = special_median_a(a);
	else if (count > 11)
		median = get_true_median(a);
	if (median != INT32_1)
		split_round_median_a(a, b, (int)median, tmp);
	else
		sort_a(a, count, tmp);
	if (tmp[0])
		ft_lstadd_back(cmnd, ft_lstnew(tmp));
	if (median == INT32_1)
		a->p[++(a->top)] = a->head;
	return ((median == INT32_1) ? 1 : 0);
}

int		sorted(t_deque *a)
{
	t_lst	*tmp;

	tmp = a->head;
	while (tmp)
	{
		if (tmp->next && tmp->next->num < tmp->num)
			return (0);
		tmp = tmp->next;
		if (tmp == a->p[a->top])
			break ;
	}
	return (1);
}

void	push_b(t_deque *b, t_deque *a, int count, char *tmp)
{
	int i;

	i = 0;
	count = (count == -1) ? 3 : count;
	while (i++ < count)
	{
		push(&b->head, &a->head, &a->end);
		ft_strcat(tmp, "pa\n");
	}
}

void	b_to_a(t_deque *a, t_deque *b, t_list **cmnd)
{
	int		count;
	long	median;
	char	tmp[a->ac * 4];

	tmp[0] = '\0';
	count = get_count(b);
	median = INT32_1;
	if (count <= 6 && count > 2)
		median = special_median_b(b);
	else if (count > 6)
		median = get_true_median(b);
	if (median != INT32_1)
		split_round_median_b(a, b, (int)median, tmp);
	else
		sort_b(b, count, tmp);
	if (median == INT32_1)
		push_b(b, a, count, tmp);
	if (tmp[0])
		ft_lstadd_back(cmnd, ft_lstnew(tmp));
}

t_list	*quick_sort(t_deque *a, t_deque *b)
{
	t_list	*cmnd;
	int		ret;
	int		sort;

	cmnd = ft_lstnew((void *)"\0");
	while (!(sort = sorted(a)) || b->head != NULL)
	{
		if (!sort)
		{
			while ((ret = split_a(a, b, &cmnd)) == 0)
				;
			if (ret == -1)
				exit(1);
		}
		else
			a->p[++(a->top)] = a->head;
		b_to_a(a, b, &cmnd);
	}
	return (cmnd);
}
