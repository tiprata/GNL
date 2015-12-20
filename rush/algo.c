/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 17:44:25 by pboutin           #+#    #+#             */
/*   Updated: 2015/12/20 20:10:44 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		*remmove(int i, int *tab, int j)
{

	printf("AA");
	if(i > tab[j] && tab[j - 1] > 0)
	{
		printf("AA");
		tab[j - 1] = tab[j - 1] - (i - tab[j]);
		tab[j] = tab[j] - tab[j];

	}
	else if (tab[j] == 1)
		tab[j] = 0;
	else
		tab[j] = tab[j] - i;
	return(tab);
}

int		*algo(int *tab)
{
	int		i;
	int l;
	i = 0;
	l = 0;
	while (tab[i] != 11000)
	{
		l += tab[i];
		i++;
	}
	printf("   %d   ", l);
	i = 0;
	while (tab[i] != 11000)
		i++;
	i--;
	while(tab[i] == 0)
		i--;
	if (tab[i] != 11000)
	{
		if(l%4 == 1)
		{
			printf("AAAAA");
			tab = remmove (1, tab, i);
		}
		else if (l%4 == 2)
		{
			printf("BBBBBBB");
			tab = remmove (1, tab, i);
		}
		else if (l%4 == 3)
		{
			printf("CCCCCC");
			tab = remmove (2, tab, i);
		}
		else if (l%4 == 0)
		{
			printf("DDDDDDD");
			tab = remmove (3, tab, i);
		}
	}
	return (tab);
}

int		main()
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 4);
	tab[0] = 4;
	tab[1] = 2;
	tab[2] = 1;
	tab[3] = 11000;
	tab = algo(tab);
//	printf("%d  ", 1 - 1);
	printf("  %d  ", tab[0]);
	printf("  %d  ", tab[1]);
	printf("  %d  ", tab[2]);
}
