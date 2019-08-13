/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_col_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 09:45:20 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/06/03 09:45:24 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_col_fd(char *colour, char *str, int fd)
{
	ft_putstr_fd(colour, fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(RESET, fd);
}
