/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:43:13 by tiprata           #+#    #+#             */
/*   Updated: 2015/11/27 11:43:18 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *delist;

	delist = *alst;
	while (delist != NULL)
	{
		del(delist->content, delist->content_size);
		free(delist);
		delist = delist->next;
	}
	*alst = NULL;
}
