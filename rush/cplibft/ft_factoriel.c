/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factoriel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 22:00:38 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/09 10:05:52 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_factoriel(int i)
{
	int		temp;

	temp = i - 1;
	if (i == 0)
		return (1);
	while (temp > 1)
	{
		i = i * temp;
		temp--;
	}
	return (i);
}
