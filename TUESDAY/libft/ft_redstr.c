/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:28:08 by tiprata           #+#    #+#             */
/*   Updated: 2016/01/11 15:33:36 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_redstr(char *str)
{
	ft_putstr("\x1B[31m");
	write(1, str, ft_strlen(str));
	ft_putstr("\033[0m");
}
