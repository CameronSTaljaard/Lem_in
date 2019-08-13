/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_col_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaljaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 09:58:54 by ctaljaar          #+#    #+#             */
/*   Updated: 2019/06/03 09:59:04 by ctaljaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_col_fd(char *colour, int nbr, int fd)
{
	ft_putstr_fd(colour, fd);
	ft_putnbr_fd(nbr, fd);
	ft_putstr_fd(RESET, fd);
}
