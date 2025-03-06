/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:19:52 by dsayumi-          #+#    #+#             */
/*   Updated: 2025/03/06 17:19:54 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrm(t_list *lst, t_list *rm_element, void (*del)(void *))
{
	t_list	*head;
	t_list	*prev;

	if (lst == rm_element)
	{
		head = lst->next;
		ft_lstdelone(lst, del);
		return (head);
	}
	head = lst;
	while (lst != NULL)
	{
		prev = lst;
		lst = lst->next;
		if (lst == rm_element)
		{
			prev->next = lst->next;
			ft_lstdelone(lst, del);
			break ;
		}
	}
	return (head);
}
