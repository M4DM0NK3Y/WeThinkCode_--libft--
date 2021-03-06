/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@students.wethinkcode    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 10:10:10 by cterblan          #+#    #+#             */
/*   Updated: 2019/07/23 22:22:39 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/private_libft_includes.h"


/*
	Performs the (*del) function on each "t_list **alst" node.
*/
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*lstnxt;

	lst = *alst;
	while (lst)
	{
		lstnxt = lst->next;
		del((lst)->content, (*alst)->content_size);
		free(lst);
		lst = lstnxt;
	}
	*alst = NULL;
}
