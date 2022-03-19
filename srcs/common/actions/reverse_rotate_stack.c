/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:45:51 by msahli            #+#    #+#             */
/*   Updated: 2021/07/07 19:55:00 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

/* Fonction de reverse rotate utile pour les différentes actions */
void	reverse_rotate(t_stack *sta)
{
	t_s_elem	*prev;
	t_s_elem	*elem;

	if (!sta->first || !sta->first->next || !sta)
		return ;
	elem = sta->first;
	while (elem->next)
	{
		prev = elem;
		elem = elem->next;
	}
	elem->next = sta->first;
	sta->first = elem;
	prev->next = NULL;
}

/* Action RRA demandée dans le sujet */
void	rra(t_stack *a, int print_option, t_mem *mem)
{
	reverse_rotate(a);
	if (print_option == 1)
		write(1, "rra\n", 4);
	mem->action_count++;
}

/* Action RRB demandée dans le sujet*/
void	rrb(t_stack *b, int print_option, t_mem *mem)
{
	reverse_rotate(b);
	if (print_option == 1)
		write(1, "rrb\n", 4);
	mem->action_count++;
}

/* Action RRR demandée dans le sujet */
void	rrr(t_stack *a, t_stack *b, int print_option, t_mem *mem)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print_option == 1)
		write(1, "rrr\n", 4);
	mem->action_count--;
}
