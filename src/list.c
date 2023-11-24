/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:49:01 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/24 16:34:52 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
4	deque A			deque B		^      next
3	 next			 next		|		||		 /\
2	 next			 next		|		\/		 ||
1	  end			  end		|				prev
*/
#include "push_swap.h"

int	ft_lst_is_sorted(t_node *deque, int reverse)
{
	t_node	*tmp;

	tmp = deque;
	if (ft_lst_size(deque) == 0 || !deque)
		return (0);
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val && reverse == 0)
			return (0);
		if (tmp->val < tmp->next->val && reverse == 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_lst_clear(t_node *node)
{
	t_node	*tmp;
	if (!node)
		return ;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}

t_node	*ft_last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

int	ft_lst_size(t_node *node)
{
	int		len;
	t_node	*tmp;

	len = 0;
	tmp = node;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

t_node	*ft_lst_new(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->val = val;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node	*ft_lst_add_top_front(t_node *node, int val)
{
	t_node	*new;

	new = ft_lst_new(val);
	if (!new)
		return (NULL);
	if (!node)
		return (new);
	new->prev = ft_last_node(node);
	ft_last_node(node)->next = new;
	return (node);
}
