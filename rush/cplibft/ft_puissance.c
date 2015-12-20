/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 21:51:39 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/02 12:42:47 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_puissance(int nb, int p)
{
	int		i;
	int		temp;

	i = 1;
	temp = nb;
	if (p == 0)
		return (1);
	while (i < p)
	{
		nb = nb * temp;
		i++;
	}
	return (nb);
}
