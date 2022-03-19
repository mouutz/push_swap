/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:43:46 by msahli            #+#    #+#             */
/*   Updated: 2021/07/07 19:53:23 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include <common/common.h>

void			algorithm(t_mem *mem);
t_params		init_params(t_mem *mem);
void			bring_to_top(t_stack *sta, int x, t_mem *mem);
void			sort_more_three(t_stack *a, t_stack *b, t_mem *mem);
void			prep_set(t_stack *a, t_stack *b, t_mem *mem);
int				small_cases(t_stack *a, t_stack *b, t_mem *mem);
void			sort_two(t_stack *a, t_mem *mem);
void			sort_three(t_stack *a, t_mem *mem);
int				biggest(t_stack *a);
int				smallest(t_stack *a);
t_stack			*bubble_sort_it(t_stack *cpy);
void			set_target_index_cpy(t_stack *cpy);
void			set_target_index(t_stack *sta);
int				largest_keep_a(t_s_elem *elem, t_stack *stack, bool define);
void			set_keep(t_mem *mem);
void			push_keep_false_b(t_mem *mem);
t_s_elem		*evaluate_actions(t_mem *mem, t_params *params);
int				abs_value(int x);
int				where_to_insert(t_stack *s, int x, t_s_elem *t, t_s_elem *p);
int				optimize_actions(int count_for_a, int count_for_b);
int				sort(t_mem *mem, t_params *params);

#endif
