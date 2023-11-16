/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:12 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/16 15:11:17 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>

# define ERROR_MSG_ARG "[ERROR] You need one argument\n"
# define ERROR_MSG_FILENO "[ERROR] Invalid file\n"
# define ERROR_MSG_EXTENSION "[ERROR] It is not .ber file\n"
# define ERROR_MSG_NOFILE "[ERROR] There is no file name\n"
# define ERROR_MSG_OPEN "[ERROR] Can't open the map\n"
# define ERROR_MSG_INIT "[ERROR] Initialization is failed\n"
# define ERROR_MSG_PATH "[ERROR] THis is not a valid path\n"
# define ERROR_MSG_INPUT "[ERROR] Your input format is wrong\n"

typedef struct node
{
	int			val;
	struct node	*prev;
	struct node	*next;
} t_node;

// Stack Utilties
t_node				*last_first_node(t_node *node, bool is_last);
t_node				*add_node(t_node *node, int content);
t_node				*create_node(int content);
void				clear_lst_node(t_node *node);
void				print_stack(t_node *stack, char *str, bool advanced,
						bool to_first);
int					stack_len(t_node *stack);
int					min(int a, int b);
int					max(int a, int b);

// push swap operations
bool				swap(t_node **stack);
bool				push(t_node **stack_from, t_node **stack_to);
bool				rotate(t_node **stack, bool reverse);
bool				execute(t_node **stack_a, t_node **stack_b, char *line,
						bool s_print);
int					execute_calc(t_node *stack_a, t_node *stack_b, int len,
						bool return_pos_b);
int					reverse_calc(t_node *stack_a, t_node *stack_b, int len,
						bool return_pos_b);
bool				multi_execute(t_node **stack_a, t_node **stack_b,
						char *line, int n);
void				check_exit_else_exec(t_node **stack_a, t_node **stack_b,
						char *line);
void				exec_smt(t_node **stack_a, t_node **stack_b, int pos[2],
						int mode);
void				execute_ps(t_node **stack_a, t_node **stack_b, int pos[2],
						int mode);
void				reverse_pos(t_node **stack_a, t_node **stack_b, int pos[2]);

// sorting Utilities
void				push_swap(t_node *stack_a, t_node *stack_b, int len);
bool				is_sorted(t_node *stack, bool reverse);
int					min_max_pos(t_node *stack, bool max, bool pos);
int					find_target(t_node *stack_from, t_node *stack_to);
void				target_push(t_node *stack, int pos);
void				min_max_push(t_node *stack, bool max);
int					calc(t_node *stack_a, t_node *stack_b, int len,
						bool return_pos_b);
int					lcm(int pos[2], int len_a, int len_b, bool return_move);
int					node_index(t_node *stack, int target);
int					find_min_index(t_node *stack_a, t_node *stack_b, int len);
void				sort_three(t_node *stack_a);
void				reverse_pos(t_node **stack_a, t_node **stack_b, int pos[2]);

// generic Utilities
int					ft_strcmp(const char *s1, const char *s2);
void				ft_error(t_node *stack_a);
int					ft_atoi_ps(char *str, t_node *stack_a);
bool				is_valid(t_node *stack_a, char *str);

#endif
