/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:42:58 by tiprata           #+#    #+#             */
/*   Updated: 2015/11/27 11:45:54 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*nlist;
	void		*ncontent;

	if (!(ncontent = malloc(sizeof(*ncontent) * content_size + 1)))
		return (NULL);
	if (content)
		ft_memcpy(ncontent, content, content_size);
	else
	{
		content = NULL;
		content_size = 0;
	}
	if (!(nlist = (t_list *)malloc(sizeof(*nlist))))
		return (NULL);
	nlist->content = ncontent;
	nlist->content_size = content_size;
	nlist->next = NULL;
	return (nlist);
}
