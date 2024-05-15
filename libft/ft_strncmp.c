/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktas <ktas@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:37:47 by ktas              #+#    #+#             */
/*   Updated: 2023/12/15 15:37:49 by ktas             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*xs1;
	unsigned char	*xs2;

	xs1 = (unsigned char *) s1;
	xs2 = (unsigned char *) s2;
	i = -1;
	while ((xs1[++i] || xs2[i]) && i < n)
		if (xs1[i] != xs2[i])
			return (xs1[i] - xs2[i]);
	return (0);
}
