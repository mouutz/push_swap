/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step3_find_shortest_action.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:43:11 by msahli            #+#    #+#             */
/*   Updated: 2021/07/07 19:44:36 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>

/* Calcule de façon optimiséele nombre d'actions a faire */
int	optimize_actions(int c_a, int c_b)
{
	if (c_a > 0 && c_b > 0)
		return (abs_value(c_a) + abs_value(c_b) - min(c_a, c_b));
	else if (c_a < 0 && c_b < 0)
		return (abs_value(c_a) + abs_value(c_b) + max(c_a, c_b));
	else
		return (abs_value(c_a) + abs_value(c_b));
	return (SUCCESS);
}

void	init_variables(int *i, int *pos, bool *end)
{
	*i = 1;
	*pos = 0;
	*end = false;
}

/* Calcule le nombre d'actions a faire pour positionner au bon index sur A */
/* Pour tous les elements, a recalculer apres avoir deplacé 1 élément */
int	where_to_insert(t_stack *sta, int x, t_s_elem *tmp, t_s_elem *prev)
{
	int			i;
	int			pos;
	bool		end;

	init_variables(&i, &pos, &end);
	while (prev && !end)
	{
		if (tmp == NULL)
		{
			tmp = sta->first;
			end = true;
		}
		if ((x > prev->t_i && x < tmp->t_i)
			|| (prev->t_i > tmp->t_i && (x < tmp->t_i || x > prev->t_i)))
			pos = i;
		i++;
		prev = tmp;
		tmp = tmp->next;
	}
	if (pos > stack_length(sta) / 2)
		pos -= stack_length(sta);
	return (pos);
}

/* Calcule le plus petit nombre d'actions a faire pour trier un element */
t_s_elem	*evaluate_actions(t_mem *mem, t_params *params)
{
	t_s_elem	*tmp;
	t_s_elem	*prev;

	params->c_for_b = 0;
	params->min_move = 0xFFFFFFF;
	while (params->elem)
	{
		tmp = mem->a->first->next;
		prev = mem->a->first;
		params->c_for_a = where_to_insert(mem->a, params->elem->t_i, tmp, prev);
		params->action_b = params->c_for_b;
		if (params->c_for_b > stack_length(mem->b) / 2)
			params->action_b -= stack_length(mem->b);
		params->total = optimize_actions(params->c_for_a, params->action_b);
		if (params->total < params->min_move)
		{
			params->min_move = params->total;
			params->best = params->elem;
			params->min_a = params->c_for_a;
			params->min_b = params->action_b;
		}
		params->elem = params->elem->next;
		params->c_for_b++;
	}
	return (params->best);
}
