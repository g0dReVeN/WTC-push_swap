/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 08:16:22 by jgovend           #+#    #+#             */
/*   Updated: 2018/07/05 17:04:51 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *src, size_t i)
{
	char	*str;

	if (!src)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str = ft_strncpy(str, src, i);
	str[i] = '\0';
	return (str);
}
