/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:26:17 by ikalkan           #+#    #+#             */
/*   Updated: 2025/06/18 13:29:57 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*whereweat;
	t_list	*temp;

	if (!lst)
		return ;
	temp = NULL;
	whereweat = *lst;
	while (whereweat)
	{
		temp = whereweat;
		whereweat = whereweat->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
