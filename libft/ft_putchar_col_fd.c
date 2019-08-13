/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_col_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 09:54:44 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/06/03 09:54:45 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putchar_col_fd(char *colour, int c, int fd)
{
	ft_putstr_fd(colour, fd);
	ft_putchar_fd(c, fd);
	ft_putstr_fd(RESET, fd);
}
