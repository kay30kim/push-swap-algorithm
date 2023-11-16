/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:13:04 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/16 15:48:09 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_node **deque)
{
	t_node	*tmp;

	if (deque == NULL || *deque == NULL || (*deque)->next == NULL)
		return (1);
	tmp = (*deque)->next;
	(*deque)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *deque;
	tmp->next = *deque;
	tmp->prev = NULL;
	(*deque)->prev = tmp;
	*deque = tmp;
	return (1);
}

int	ft_rotate(t_node **deque, int reverse)
{
	t_node	*tmp;

	if (deque == NULL || *deque == NULL || (*deque)->next == NULL)
		return (1);
	tmp = *deque;
	if (reverse == 0)
	{
		/* 반대로 돌리기
		*deque = (*deque)->next;
		(*deque)->prev = NULL;
		tmp->next = NULL;
		tmp->prev = last_first_node(*deque, 1);
		last_first_node(*deque, 1)->next = tmp;*/
	}
	else
	{
		/* 반대로 돌리기
		*deque = last_first_node(*deque, 1);
		(*deque)->prev->next = NULL;
		(*deque)->prev = NULL;
		(*deque)->next = tmp;
		tmp->prev = *deque;*/
	}
	return (1);
}

int	ft_execute(t_node **deque_a, t_node **deque_b, char *line, int is_print)
{
	if (!is_print)
		ft_printf("%s\n", line);
	if (ft_strcmp(line, "sa") == 0)
		return (ft_swap(deque_a));
	else if (ft_strcmp(line, "sb") == 0)
		return (ft_swap(deque_b));
	else if (ft_strcmp(line, "ss") == 0)
		return (ft_swap(deque_a) && ft_swap(deque_b));
	else if (ft_strcmp(line, "pa") == 0)
		return (push(deque_b, deque_a));
	else if (ft_strcmp(line, "pb") == 0)
		return (push(deque_a, deque_b));
	else if (ft_strcmp(line, "ra") == 0)
		return (ft_rotate(deque_a, 0));
	else if (ft_strcmp(line, "rb") == 0)
		return (ft_rotate(deque_b, 0));
	else if (ft_strcmp(line, "rr") == 0)
		return (ft_rotate(deque_a, 0) && ft_rotate(deque_b, 0));
	else if (ft_strcmp(line, "rra") == 0)
		return (ft_rotate(deque_a, 1));
	else if (ft_strcmp(line, "rrb") == 0)
		return (ft_rotate(deque_b, 1));
	else if (ft_strcmp(line, "rrr") == 0)
		return (ft_rotate(deque_a, 1) && ft_rotate(deque_b, 1));
	return (0);
}
