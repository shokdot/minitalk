/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:25:46 by healeksa          #+#    #+#             */
/*   Updated: 2024/04/04 18:13:46 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*addr;

	i = ft_strlen(src);
	addr = (char *)malloc(sizeof(char) * (i + 1));
	if (!addr)
		return (0);
	ft_strlcpy(addr, src, i + 1);
	return (addr);
}
