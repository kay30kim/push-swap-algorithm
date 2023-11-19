/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:12 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/19 17:27:58 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>

# define INT32_1 2147483648
# define ERROR_MSG_ARG "[ERROR] You need one argument\n"
# define ERROR_MSG_FILENO "[ERROR] Invalid file\n"
# define ERROR_MSG_EXTENSION "[ERROR] It is not .ber file\n"
# define ERROR_MSG_NOFILE "[ERROR] There is no file name\n"
# define ERROR_MSG_OPEN "[ERROR] Can't open the map\n"
# define ERROR_MSG_INIT "[ERROR] Initialization is failed\n"
# define ERROR_MSG_PATH "[ERROR] THis is not a valid path\n"
# define ERROR_MSG_INPUT "[ERROR] Your input format is wrong\n"

typedef struct		lst
{
	int			num;
	struct lst	*next;
	struct lst	*prev;
}	t_lst;

typedef struct		deque
{
	t_lst	*head;
	t_lst	*end;
	t_lst	**p;
	int		top;
	int		ac;
}	t_deque;

typedef struct node
{
	int			val;
	struct node	*prev;
	struct node	*next;
} t_node;

// Stack Utilties
void	print_stacks(t_lst *a, t_lst *b, char *line);
void	push(t_lst **from, t_lst **to, t_lst **to_end);
void	swap(t_lst **head);
void	rotate(t_lst **head, t_lst **end);
void	rev_rotate(t_lst **head, t_lst **end);
// push swap operations
long	special_median_a(t_deque *a);
int		deal_higher_a(t_deque *a, char *cmnds, int med, int *t_rewind);
void	split_round_median_a(t_deque *a, t_deque *b, int med, char *cmnds);
void	three_case(t_deque *a, char *tmp);
void	sort_a(t_deque *a, int count, char *tmp);
long	special_median_b(t_deque *b);
int		deal_lower_b(t_deque *b, char *cmnds, int med, int count[2]);
void	split_round_median_b(t_deque *a, t_deque *b, int med, char *cmnds);
void	three_caseb(t_deque *a, char *tmp);
void	sort_b(t_deque *b, int count, char *tmp);
void	lst_addback(char *str, t_lst **back);
// sorting Utilities
int		split_a(t_deque *a, t_deque *b, t_list **cmnd);
int		sorted(t_deque *a);
t_list	*quick_sort(t_deque *a, t_deque *b);
int		get_count(t_deque *s);
int		get_true_median(t_deque *a);
// generic Utilities
void	error_exit(void);
int		is_digit(int ac, char **av);
int		is_duplicated(char **av, int i);
char	ft_strcat(char *dst, const char *src);
#endif
