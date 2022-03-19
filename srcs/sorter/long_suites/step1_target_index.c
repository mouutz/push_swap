/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step1_target_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:43:03 by msahli            #+#    #+#             */
/*   Updated: 2021/07/07 19:44:31 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>

/* Markup mode */
/* Bubble sort pour déterminer à quelle position devrait se trouver l'élément */
/* Retourne une copie de la stack passée en paramètre */
t_stack	*cpy_stack(t_stack *sta, t_mem *mem, t_params *params)
{
	t_stack		*cpy;
	t_s_elem	*read;

	if (!sta)
		return (NULL);
	cpy = (t_stack *)malloc(sizeof(t_stack));
	read = sta->first;
	if (!cpy)
		error(mem, 1, &params->min_a, &params->min_b);
	read = sta->first;
	cpy->first = NULL;
	while (read)
	{
		push_end_plus_origin(cpy, read->value, read, mem);
		read = read->next;
	}
	return (cpy);
}

void	bubble_swap(t_s_elem **ori, t_s_elem **tmplst, t_s_elem **elem, int *t)
{
	*t = (*elem)->value;
	*ori = (*elem)->initial_position;
	(*elem)->value = (*tmplst)->value;
	(*elem)->initial_position = (*tmplst)->initial_position;
	(*tmplst)->value = (*t);
	(*tmplst)->initial_position = *ori;
}

/* Une fois la copie réalisée, nous devons la trier via bubblesort */
/* Afin de déterminer le target index */
t_stack	*bubble_sort_it(t_stack *cpy)
{
	int			temp;
	t_s_elem	*origin;
	t_s_elem	*tmplst;
	t_s_elem	*elem;

	tmplst = cpy->first;
	elem = cpy->first;
	origin = cpy->first->initial_position;
	temp = cpy->first->value;
	while (elem)
	{
		while (tmplst)
		{
			if (elem->value > tmplst->value)
				bubble_swap(&origin, &tmplst, &elem, &temp);
			tmplst = tmplst->next;
		}
		elem = elem->next;
		tmplst = elem;
	}
	return (cpy);
}

/* Renseignement du target index sur la copie */
void	set_target_index_cpy(t_stack *cpy)
{
	t_s_elem	*elem;
	int			index;

	elem = cpy->first;
	index = 0;
	while (elem)
	{
		elem->t_i = index;
		elem = elem->next;
		index++;
	}
}

/* Renseignement du target index sur la stack A / structure principales */
void	set_target_index(t_stack *sta)
{
	t_s_elem	*elem;

	elem = sta->first;
	while (elem)
	{
		elem->initial_position->t_i = elem->t_i;
		elem = elem->next;
	}
}
