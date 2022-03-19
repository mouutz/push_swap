/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step2_keep_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:43:07 by msahli            #+#    #+#             */
/*   Updated: 2021/07/07 19:44:34 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>

/* Compte la plus longue suite de target_index triés dans l'ordre croissant*/
/* Va renseigner keep a true si bool define est true */
int	largest_keep_a(t_s_elem *start, t_stack *stack, bool define)
{
	t_s_elem	*elem;
	int			index_max;
	int			count;

	elem = start;
	index_max = 0;
	count = 0;
	while (elem)
	{
		if (elem->t_i >= index_max)
		{
			if (define)
				elem->keep = true;
			index_max = elem->t_i;
			++count;
		}
		else if (define)
			elem->keep = false;
		elem = elem->next;
		if (elem == NULL)
			elem = stack->first;
		if (elem == start)
			break ;
	}
	return (count);
}

/* Retourne l'adresse du premiere élément de la suite triée à garder sur A */
t_s_elem	*get_max_keep(t_stack *stack)
{
	t_s_elem	*elem;
	t_s_elem	*max;
	int			max_keep;
	int			cur;

	max_keep = 0;
	elem = stack->first;
	while (elem)
	{
		cur = largest_keep_a(elem, stack, false);
		if (cur > max_keep)
		{
			 max_keep = cur;
			 max = elem;
		}
		elem = elem->next;
	}
	return (max);
}

/* Va determiner la plus longue suite d'index triés et mettre keep a true */
void	set_keep(t_mem *mem)
{
	t_s_elem	*max;
	t_stack		*stack;

	stack = mem->a;
	max = get_max_keep(stack);
	mem->maxsize = largest_keep_a(max, stack, true);
}

/* Mets sur la stack B tous ceux dont keep = false */
void	push_keep_false_b(t_mem *mem)
{
	int	size;

	size = stack_length(mem->a) - mem->maxsize;
	while (size > 0)
	{
		if (mem->a->first->keep == false)
		{
			pb(mem->a, mem->b, 1, mem);
			size--;
		}
		else
			ra(mem->a, 1, mem);
	}
}
