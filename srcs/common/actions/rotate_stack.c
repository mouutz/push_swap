/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:45:56 by msahli            #+#    #+#             */
/*   Updated: 2021/07/07 19:55:00 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

/* Fonction rotate utile pour toutes les actions */
void	rotate_stack(t_stack *sta)
{
	t_s_elem	*last;
	t_s_elem	*tmp;

	if (!sta)
		return ;
	last = last_element(sta);
	tmp = sta->first;
	sta->first = sta->first->next;
	tmp->next = NULL;
	last->next = tmp;
}

/* Action RA demandée dans le sujet */
void	ra(t_stack *a, int print_option, t_mem *mem)
{
	if (!a || !mem)
		return ;
	rotate_stack(a);
	if (print_option == 1)
		write(1, "ra\n", 3);
	mem->action_count++;
}

/* Action RB demandée dans le sujet */
void	rb(t_stack *b, int print_option, t_mem *mem)
{
	if (!b || !mem)
		return ;
	rotate_stack(b);
	if (print_option == 1)
		write(1, "rb\n", 3);
	mem->action_count++;
}

/* Action RR demandée dans le sujet */
void	rr(t_stack *a, t_stack *b, int print_option, t_mem *mem)
{
	if (!b || !mem || !a)
		return ;
	rotate_stack(a);
	rotate_stack(b);
	if (print_option == 1)
		write(1, "rr\n", 3);
	mem->action_count++;
}

t_s_elem	*last_element(t_stack *sta)
{
	t_s_elem	*elem;

	if (!sta || !sta->first)
		return (NULL);
	elem = sta->first;
	while (elem->next)
		elem = elem->next;
	return (elem);
}
