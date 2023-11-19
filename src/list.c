/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:49:01 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/19 17:22:49 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_addback(char *str, t_lst **back)
{
	t_lst *tmp;
	long	num;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		error_exit();
	if (*back == NULL)
		return ;
	tmp = malloc(sizeof(t_lst));
	tmp->num = (int)num;
	tmp->next = NULL;
	(*back)->next = tmp;
	tmp->prev = *back;
	*back = tmp;
}