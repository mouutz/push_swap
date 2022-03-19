/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:46:45 by msahli            #+#    #+#             */
/*   Updated: 2021/07/07 19:46:46 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

/* Cherche un doublon sur les petites suites */
int	find_duplicate_small(t_stack *a)
{
	int			i;
	t_s_elem	*elem;
	t_s_elem	*tmp;

	i = 0;
	tmp = a->first;
	while (tmp->next)
	{
		elem = tmp->next;
		while (elem)
		{
			if (tmp->value == elem->value)
			{
				i++;
				break ;
			}
			elem = elem->next;
		}
		tmp = tmp->next;
	}
	return (i);
}

/* Détermine si la stack est triée ou pas */
int	is_sorted_stack(t_stack *a)
{
	t_s_elem	*elem;

	elem = a->first;
	while (elem->next)
	{
		if (elem->next->value < elem->value)
			return (ERROR);
		elem = elem->next;
	}
	return (SUCCESS);
}
