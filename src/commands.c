/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:06:54 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/19 17:22:25 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_lst *a, t_lst *b, char *line)
{
	t_lst *tmp;

	tmp = a;
	ft_printf("%s\na: ", line);
	while (tmp != NULL)
	{
		ft_printf("%d, ", tmp->num);
		tmp = tmp->next;
	}
	tmp = b;
	ft_putstr_fd("\nb : ", 1);
	while (tmp != NULL)
	{
		ft_printf("%d, ", tmp->num);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
}

void	push(t_lst **from, t_lst **to, t_lst **to_end)
{
	t_lst *tmp;

	if (*from == NULL)
		return ;
	tmp = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	if (*to)
		(*to)->prev = tmp;
	else
		*to_end = tmp;
	tmp->next = *to;
	*to = tmp;
	(*to)->prev = NULL;
}

void	swap(t_lst **head)
{
	t_lst *tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
}

void	rotate(t_lst **head, t_lst **end)
{
	if (*head == NULL || *end == NULL || (*head)->next == NULL)
		return ;
	(*end)->next = *head;
	(*head)->prev = *end;
	*head = (*head)->next;
	(*head)->prev = NULL;
	*end = (*end)->next;
	(*end)->next = NULL;
}

void	rev_rotate(t_lst **head, t_lst **end)
{
	if (*head == NULL || *end == NULL || (*end)->prev == NULL)
		return ;
	(*head)->prev = *end;
	(*end)->next = *head;
	*head = *end;
	*end = (*end)->prev;
	(*end)->next = NULL;
	(*head)->prev = NULL;
}
