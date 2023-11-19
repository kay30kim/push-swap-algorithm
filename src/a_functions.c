/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:59:09 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/19 16:23:13 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	special_median_a(t_deque *a)
{
	t_lst	*tmp;
	int		arr[12];
	int		i;
	int		j[2];

	tmp = a->head;
	i = 0;
	while (tmp != a->p[a->top])
	{
		arr[i++] = tmp->num;
		tmp = tmp->next;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] < arr[j[1]])
			{
				arr[11] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[11];
			}
	}
	return ((!a->p[a->top]) ? arr[3] : arr[2]);
}

int		deal_higher_a(t_deque *a, char *cmnds, int med, int *t_rewind)
{
	int		skips;
	t_lst	*tmp;

	skips = 0;
	tmp = a->head;
	while (tmp != a->p[a->top] && tmp->num > med)
	{
		skips++;
		tmp = tmp->next;
	}
	if (tmp == a->p[a->top])
		return (0);
	*t_rewind = *t_rewind + skips;
	while (skips--)
	{
		rotate(&a->head, &a->end);
		ft_strcat(cmnds, "ra\n");
	}
	return (1);
}

void	split_round_median_a(t_deque *a, t_deque *b, int med, char *cmnds)
{
	int		rewind;

	rewind = 0;
	if (b->head)
		b->p[++(b->top)] = b->head;
	while (a->head != a->p[a->top])
	{
		if (a->head->num <= med)
		{
			push(&a->head, &b->head, &b->end);
			ft_strcat(cmnds, "pb\n");
		}
		else if (!(deal_higher_a(a, cmnds, med, &rewind)))
			break ;
	}
	while (a->p[a->top] && --rewind >= 0)
	{
		rev_rotate(&a->head, &a->end);
		ft_strcat(cmnds, "rra\n");
	}
}

void	three_case(t_deque *a, char *tmp)
{
	while (!(a->head->next->num < a->head->next->next->num
	&& a->head->num < a->head->next->next->num))
	{
		if (a->head->next->num > a->head->next->next->num
		&& a->head->next->num > a->head->num)
		{
			rev_rotate(&a->head, &a->end);
			ft_strcat(tmp, "rra\n");
		}
		else
		{
			rotate(&a->head, &a->end);
			ft_strcat(tmp, "ra\n");
		}
	}
	if (!(a->head->next->num < a->head->num))
		return ;
	swap(&a->head);
	ft_strcat(tmp, "sa\n");
}

void	sort_a(t_deque *a, int count, char *tmp)
{
	if (count == 1)
		return ;
	if (count == 2)
	{
		if (a->head->next->num < a->head->num)
		{
			swap(&a->head);
			ft_strcat(tmp, "sa\n");
		}
		return ;
	}
	three_case(a, tmp);
}
