/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:48:32 by msahli            #+#    #+#             */
/*   Updated: 2021/07/07 19:48:34 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus/checker_bonus.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	execute_read_action(char *action, t_mem *mem)
{
	if (!ft_strcmp(action, "rb"))
		rb(mem->b, 0, mem);
	else if (!ft_strcmp(action, "rr"))
		rr(mem->a, mem->b, 0, mem);
	else if (!ft_strcmp(action, "rra"))
		rra(mem->a, 0, mem);
	else if (!ft_strcmp(action, "rrb"))
		rrb(mem->b, 0, mem);
	else if (!ft_strcmp(action, "rrr"))
		rrr(mem->a, mem->b, 0, mem);
	 else if (!ft_strcmp(action, "sa"))
		sa(mem->a, 0, mem);
	else if (!ft_strcmp(action, "sb"))
		sb(mem->b, 0, mem);
	else if (!ft_strcmp(action, "ss"))
		ss(mem->a, mem->b, 0, mem);
	else if (!ft_strcmp(action, "pa") && !is_empty_stack(mem->b))
		pa(mem->b, mem->a, 0, mem);
	else if (!ft_strcmp(action, "pb") && !is_empty_stack(mem->a))
		pb(mem->a, mem->b, 0, mem);
	else if (!ft_strcmp(action, "ra"))
		ra(mem->a, 0, mem);
	else
		error(mem, 1, NULL, NULL);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_mem	*mem;
	char	*action_messages;

	mem = init_mem();
	if (argc >= 2)
	{
		read_args(argc, argv, mem);
		while (get_next_line(0, &action_messages, mem))
		{
			execute_read_action(action_messages, mem);
			free(action_messages);
		}
		if (is_sorted_stack(mem->a) && is_empty_stack(mem->b))
		{
			write(1, "OK\n", 3);
			free_all(mem, NULL, NULL);
		}
		else
		{
			write(1, "KO\n", 3);
			error(mem, 0, NULL, NULL);
		}
	}
	error(mem, 0, NULL, NULL);
	return (0);
}
