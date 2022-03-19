/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:44:01 by msahli            #+#    #+#             */
/*   Updated: 2021/07/07 19:44:24 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# define SUCCESS 1
# define ERROR 0
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_s_element
{
	int					value;
	bool				keep;
	struct s_s_element	*initial_position;
	int					t_i;
	struct s_s_element	*next;
}						t_s_elem;

typedef struct s_stack
{
	t_s_elem	*first;
}				t_stack;

typedef struct s_mem
{
	t_stack	*a;
	t_stack	*b;
	int		max;
	int		action_count;
	int		maxsize;
}			t_mem;

typedef struct s_params
{
	t_s_elem	*elem;
	t_s_elem	*best;
	int			c_for_a;
	int			c_for_b;
	int			min_move;
	int			total;
	int			action_b;
	int			min_a;
	int			min_b;
}				t_params;

int			stack_length(t_stack *sta);
bool		is_empty_stack(t_stack *sta);
t_mem		*init_mem(void);
long		push_atoi(char *str, t_mem *mem);
void		push_end_plus_origin(t_stack *sta, int x, t_s_elem *ori, t_mem *m);
void		swap_ab(t_stack *sta);
void		sa(t_stack *a, int print_option, t_mem *mem);
void		sb(t_stack *b, int print_option, t_mem *mem);
void		ss(t_stack *a, t_stack *b, int print_option, t_mem *mem);
void		pa(t_stack *a, t_stack *b, int print_option, t_mem *mem);
void		push_other_stack(t_stack *one, t_stack *two);
void		pb(t_stack *a, t_stack *b, int print_option, t_mem *mem);
void		rotate_stack(t_stack *sta);
void		ra(t_stack *a, int print_option, t_mem *mem);
void		rb(t_stack *b, int print_option, t_mem *mem);
void		rr(t_stack *a, t_stack *b, int print_option, t_mem *mem);
void		reverse_rotate(t_stack *sta);
void		rra(t_stack *a, int print_option, t_mem *mem);
void		rrb(t_stack *b, int print_option, t_mem *mem);
void		rrr(t_stack *a, t_stack *b, int print_option, t_mem *mem);
t_stack		*cpy_stack(t_stack *sta, t_mem *mem, t_params *params);
int			find_duplicate_small(t_stack *a);
int			ft_isalpha(int c);
int			is_sorted_stack(t_stack *a);
int			min(int x, int y);
int			max(int x, int y);
int			is_on_top(t_stack *a, int x);
int			where_middle(t_stack *a, int value);
t_s_elem	*last_element(t_stack *sta);
int			read_args(int argc, char **argv, t_mem *mem);
void		push_end(t_stack *sta, int x, t_mem *mem);
void		check_duplicates(t_mem *mem);
void		free_stack(t_stack *sta);
void		error(t_mem *mem, int print, int *min_a, int *min_b);
void		free_all(t_mem *mem, int *min_a, int *min_b);
#endif
