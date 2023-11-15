/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:47:12 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/15 15:52:22 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define INT_MAX 2147483647
# define ASCENDING 1
# define DESCENDING 0

typedef struct	s_piles
{
	int		*a;
	int		*b;
	int		alen;
	int		blen;
}				t_piles;

typedef enum	e_opt
{
	NONE,
	INSTR_ONLY,
	VISUAL,
	COLOR,
	ERROR
}				t_opt;

typedef struct	s_fun {
	char	*instr;
	void	(*f)(t_piles *, t_opt);
}				t_fun;

int				*get_pile(char **input, int *len);
t_opt			get_opt(int *ac, char ***av, int get_stream, t_file **stream);
t_fun			*initialize_fun_list(void);
void			delete_funlist(t_fun *fun_list);
int				follow_instructions(t_piles *piles, t_fun *fun_list,
		char *instr, t_opt opt);
void			sa(t_piles *piles, t_opt opt);
void			sb(t_piles *piles, t_opt opt);
void			ss(t_piles *piles, t_opt opt);
void			pa(t_piles *piles, t_opt opt);
void			pb(t_piles *piles, t_opt opt);
void			ra(t_piles *piles, t_opt opt);
void			rb(t_piles *piles, t_opt opt);
void			rr(t_piles *piles, t_opt opt);
void			rra(t_piles *piles, t_opt opt);
void			rrb(t_piles *piles, t_opt opt);
void			rrr(t_piles *piles, t_opt opt);
void			print_instr(char *instr, t_opt opt);
void			print_a(t_piles piles, t_opt opt, int imin, int imax);
void			print_b(t_piles piles, t_opt opt, int imin, int imax);
int		find_instructions(t_piles piles, t_fun *fun_list, t_opt opt);
int		quick_sort_a(t_piles *piles, t_fun *fun_list, int len, t_opt opt);
int		quick_sort_b(t_piles *piles, t_fun *fun_list, int len, t_opt opt);
int		is_sorted(int *pile, int len, int order);
void	sort_3(t_piles *piles, t_fun *fun_list, int len, t_opt opt);
void	push_sort_3(t_piles *piles, t_fun *fun_list, int len, t_opt opt);
int		get_mediane(int *mediane, int *pile, int len);
void	reg_quick_sort(int *array, int len);

#endif
