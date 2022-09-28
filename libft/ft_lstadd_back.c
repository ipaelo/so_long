/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itorres- <itorres-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:47:20 by itorres-          #+#    #+#             */
/*   Updated: 2022/05/17 12:25:44 by itorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ultimo;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ultimo = ft_lstlast(*lst);
	ultimo->next = new;
}
