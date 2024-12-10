/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:51:56 by ahyildir          #+#    #+#             */
/*   Updated: 2023/12/15 20:52:07 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dsize;
	size_t	ssize;
	size_t	i;

	i = -1;
	dsize = ft_strlen(dst);
	ssize = ft_strlen(src);
	if (!dstsize || dstsize <= dsize)
		return (dstsize + ssize);
	while (src[++i] && i < dstsize - dsize - 1)
		dst[dsize + i] = src[i];
	dst[dsize + i] = '\0';
	return (dsize + ssize);
}
