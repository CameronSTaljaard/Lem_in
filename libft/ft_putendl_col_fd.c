/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_col_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 09:45:10 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/06/03 09:47:18 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putendl_col_fd(char *colour, char *str, int fd)
{
	ft_putstr_fd(colour, fd);
	ft_putendl_fd(str, fd);
	ft_putstr_fd(RESET, fd);
}
