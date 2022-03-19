/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:43:38 by msahli            #+#    #+#             */
/*   Updated: 2021/07/12 14:45:03 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>

void	algorithm(t_mem *mem)
{
	t_stack		*cpy;
	t_params	params;

	params = init_params(mem);
	cpy = cpy_stack(mem->a, mem, &params);
	bubble_sort_it(cpy);
	set_target_index_cpy(cpy);
	set_target_index(cpy);
	free_stack(cpy);
	set_keep(mem);
	push_keep_false_b(mem);
	while (!is_empty_stack(mem->b))
	{
		params.elem = mem->b->first;
		evaluate_actions(mem, &params);
		sort(mem, &params);
	}
	if (!(is_on_top(mem->a, smallest(mem->a))))
		bring_to_top(mem->a, smallest(mem->a), mem);
	if (is_empty_stack(mem->a))
		error(mem, 1, NULL, NULL);
	free_all(mem, NULL, NULL);
}

int	main(int argc, char **argv)
{
	t_mem	*mem;
	int		red_args;

	mem = init_mem();
	if (argc >= 2)
	{
		red_args = read_args(argc, argv, mem);
		if (is_empty_stack(mem->a))
			error(mem, 1, NULL, NULL);
		if (is_sorted_stack(mem->a))
			free_all(mem, NULL, NULL);
		if (red_args <= 5)
			small_cases(mem->a, mem->b, mem);
		else
			algorithm(mem);
	}
	error(mem, 0, NULL, NULL);
	return (0);
}
