/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:55:00 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/19 17:21:01 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	special_median_b(t_deque *b)
{
	t_lst *tmp;
	int		arr[7];
	int		i;
	int		j[2];

	tmp = b->head;
	i = 0;
	while (tmp != b->p[b->top])
	{
		arr[i++] = tmp->num;
		tmp = tmp->next;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] > arr[j[1]])
			{
				arr[6] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[6];
			}
	}
	return ((!b->p[b->top]) ? arr[2] : arr[1]);
}

int		deal_lower_b(t_deque *b, char *cmnds, int med, int count[2])
{
	int		skips;
	t_lst *tmp;

	skips = 0;
	tmp = b->head;
	while (tmp != b->p[b->top] && tmp->num <= med)
	{
		skips++;
		tmp = tmp->next;
	}
	if (tmp == b->p[b->top])
		return (0);
	count[0] += skips;
	while (skips--)
	{
		rotate(&b->head, &b->end);
		ft_strcat(cmnds, "rb\n");
	}
	return (1);
}

void	split_round_median_b(t_deque *a, t_deque *b, int med, char *cmnds)
{
	int		count[2];

	count[0] = 0;
	count[1] = 0;
	while (b->head != b->p[b->top])
	{
		if (b->head->num > med)
		{
			push(&b->head, &a->head, &a->end);
			ft_strcat(cmnds, "pa\n");
		}
		else if (!(deal_lower_b(b, cmnds, med, count)))
			break ;
	}
	while (b->p[b->top] && --count[0] >= 0)
	{
		rev_rotate(&b->head, &b->end);
		ft_strcat(cmnds, "rrb\n");
	}
}

void	three_caseb(t_deque *a, char *tmp)
{
	while (!(a->head->next->num > a->head->next->next->num
	&& a->head->num > a->head->next->next->num))
	{
		if (a->head->next->num < a->head->next->next->num
		&& a->head->next->num < a->head->num)
		{
			rev_rotate(&a->head, &a->end);
			ft_strcat(tmp, "rrb\n");
		}
		else
		{
			rotate(&a->head, &a->end);
			ft_strcat(tmp, "rb\n");
		}
	}
	if (!(a->head->next->num > a->head->num))
		return ;
	swap(&a->head);
	ft_strcat(tmp, "sb\n");
}

void	sort_b(t_deque *b, int count, char *tmp)
{
	if (b->top)
		b->top--;
	if (count == 1 || !count)
		return ;
	if (count == 2)
	{
		if (b->head->next && b->head->next->num > b->head->num)
		{
			swap(&b->head);
			ft_strcat(tmp, "sb\n");
		}
		return ;
	}
	three_caseb(b, tmp);
}
