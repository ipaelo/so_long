/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:14:47 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/17 12:42:31 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*f_list;
	t_list	*new;

	temp = lst;
	f_list = NULL;
	while (temp)
	{
		new = ft_lstnew((*f)(temp->content));
		if (!new)
		{
			ft_lstclear(&f_list, del);
			return (NULL);
		}
		ft_lstadd_back(&f_list, new);
		temp = temp->next;
	}
	return (f_list);
}
