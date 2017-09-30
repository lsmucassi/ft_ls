/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:26:16 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/11 09:47:26 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;
	char	str;

	str = 0;
	if (!s1)
		s1 = &str;
	if (!s2)
		s2 = &str;
	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char*)malloc(len * sizeof(*new));
	if (new)
	{
		ft_strcpy(new, s1);
		ft_strcpy(new + ft_strlen(s1), s2);
	}
	return (new);
}
