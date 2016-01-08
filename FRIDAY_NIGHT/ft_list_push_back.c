/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:39:15 by tiprata           #+#    #+#             */
/*   Updated: 2015/12/05 16:49:59 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, char *newelem, int bslash)
{
	t_list *node;
	t_list *tmp;
	if (!(node = (t_list *)malloc(sizeof(t_list))))
	  node = NULL;
	node->next = NULL;
	node->str = ft_strdup(newelem);
	node->bslash = bslash;
	if (*begin_list == NULL)
		*begin_list = node;
	else
	{

		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}
