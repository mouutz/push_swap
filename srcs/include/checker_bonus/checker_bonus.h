/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:44:07 by msahli            #+#    #+#             */
/*   Updated: 2021/07/07 19:45:31 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# include <common/common.h>

int		ft_len(const char *s);
char	*gnl_strjoin(char *s1, char *s2, t_mem *mem);
int		ft_hasnewline(char *str);
char	*ft_newline(char *s, t_mem *mem);
char	*ft_prep_s(char *s);
int		get_next_line(int fd, char **line, t_mem *mem);
void	check_line(char *line, t_mem *mem);

#endif
