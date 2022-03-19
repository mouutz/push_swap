/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_suites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:42:55 by msahli            #+#    #+#             */
/*   Updated: 2021/07/07 19:44:42 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>

/* Sort two */
void	sort_two(t_stack *a, t_mem *mem)
{
	t_s_elem	*elem;

	if (!a)
		return ;
	elem = a->first;
	if (elem->value > elem->next->value)
		sa(a, 1, mem);
	free_all(mem, NULL, NULL);
}

/* Gere le tri pour une suite de 3 éléments */
void	sort_three(t_stack *a, t_mem *mem)
{
	int				one;
	int				two;
	int				three;

	if (!a || !mem)
		error(mem, 1, NULL, NULL);
	one = a->first->value;
	two = a->first->next->value;
	three = a->first->next->next->value;
	if (one > two && two < three && one < three)
		sa(a, 1, mem);
	else if (one > two && two > three && one > three)
	{
		sa(a, 1, mem);
		rra(a, 1, mem);
	}
	else if (one > two && two < three && one > two)
		ra(a, 1, mem);
	else if (one < two && two > three && one < three)
	{
		sa(a, 1, mem);
		ra(a, 1, mem);
	}
	else if (one < two && two > three && one > three)
		rra(a, 1, mem);
}

void	prep_set(t_stack *a, t_stack *b, t_mem *mem)
{
	int	big;
	int	small;

	big = biggest(a);
	small = smallest(a);
	while (!is_on_top(a, small))
		bring_to_top(a, small, mem);
	pb(a, b, 1, mem);
	if (stack_length(a) > 3)
	{
		while (!is_on_top(a, big))
			bring_to_top(a, big, mem);
		pb(a, b, 1, mem);
	}
}

/* Gere les suites de 4 a 5 */
void	sort_more_three(t_stack *a, t_stack *b, t_mem *mem)
{
	int	stack_len;

	stack_len = stack_length(a);
	prep_set(a, b, mem);
	sort_three(a, mem);
	if (stack_len == 5)
	{
		pa(b, a, 1, mem);
		ra(a, 1, mem);
	}
	pa(b, a, 1, mem);
	if (is_empty_stack(mem->a))
		error(mem, 1, NULL, NULL);
	free_all(mem, NULL, NULL);
}

/* Gere tous les cas de petites suites */
int	small_cases(t_stack *a, t_stack *b, t_mem *mem)
{
	if (stack_length(a) == 1)
	{
		free_all(mem, NULL, NULL);
	}
	else if (stack_length(a) == 2)
		sort_two(a, mem);
	else if (stack_length(a) == 3)
	{
		sort_three(a, mem);
		free_all(mem, NULL, NULL);
	}
	else
		sort_more_three(a, b, mem);
	if (is_empty_stack(mem->a))
		error(mem, 1, NULL, NULL);
	if (is_empty_stack(mem->a))
		error(mem, 1, NULL, NULL);
	free_all(mem, NULL, NULL);
	return (SUCCESS);
}
