/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:07:00 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/19 16:20:08 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_count(t_deque *s)
{
	int		count;
	t_lst *tmp;

	tmp = s->head;
	count = 0;
	while (tmp != s->p[s->top] && count < 12)
	{
		count++;
		tmp = tmp->next;
	}
	if (!s->p[s->top] && count == 3)
		return (-1);
	return (count);
}

int	get_true_median(t_deque *a)
{
	t_lst	*tmp;
	int		arr[a->ac + 1];
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
				arr[a->ac] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[a->ac];
			}
	}
	return (arr[i / 2]);
}
