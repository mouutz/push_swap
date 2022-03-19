/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:46:18 by msahli            #+#    #+#             */
/*   Updated: 2021/07/12 14:36:45 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	push_atoi(char *str, t_mem *mem)
{
	long	i;
	long	max;
	long	sign;
	long	result;

	i = 0;
	max = 0;
	sign = 1;
	result = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (ft_isalpha(str[i]) || max >= 1)
			error(mem, 1, NULL, NULL);
		if (str[i] == '-')
			sign = -sign;
		max++;
		i++;
	}
	if (!str[i] || !ft_isdigit(str[i]))
		error(mem, 1, NULL, NULL);
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (str[i] && !(ft_isdigit(str[i])) && str[i] != ' ')
		error(mem, 1, NULL, NULL);
	return (result * sign);
}
