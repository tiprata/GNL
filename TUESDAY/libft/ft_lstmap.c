/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiprata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:45:09 by tiprata           #+#    #+#             */
/*   Updated: 2015/11/27 16:46:52 by tiprata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *tmp;
	t_list *ptr;

	if (!lst || !(*f))
		return (NULL);
	if (!(ptr = (t_list *)malloc(sizeof(*ptr))))
		return (NULL);
	ptr = f(lst);
	tmp = ptr;
	lst = lst->next;
	while (lst)
	{
		list = f(lst);
		tmp->next = list;
		tmp = list;
		lst = lst->next;
	}
	tmp->next = NULL;
	return (ptr);
}
