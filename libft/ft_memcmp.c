/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktas <ktas@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:30:11 by ktas              #+#    #+#             */
/*   Updated: 2023/12/15 15:30:12 by ktas             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*xs1;
	unsigned char	*xs2;

	xs1 = (unsigned char *) s1;
	xs2 = (unsigned char *) s2;
	i = -1;
	if (!xs1 && !xs2)
		return (0);
	while (++i < n)
		if (xs1[i] != xs2[i])
			return (xs1[i] - xs2[i]);
	return (0);
}
