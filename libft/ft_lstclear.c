/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:58:22 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/17 12:25:58 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Elimina un nodo con la función declarada en del */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		ptr = *lst;
		*lst = ptr->next;
		free(ptr);
	}
	*lst = NULL;
}
