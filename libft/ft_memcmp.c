/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:47:53 by ahyildir          #+#    #+#             */
/*   Updated: 2023/12/15 20:48:03 by ahyildir         ###   ########.tr       */
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
