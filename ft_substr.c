/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:51:25 by ikalkan           #+#    #+#             */
/*   Updated: 2025/06/18 13:10:01 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			lenofs;

	if (s == NULL)
		return (NULL);
	lenofs = ft_strlen(s);
	if (start >= lenofs)
		return (ft_strdup(""));
	if (len > lenofs - start)
		len = lenofs - start;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len +1);
	return (str);
}
