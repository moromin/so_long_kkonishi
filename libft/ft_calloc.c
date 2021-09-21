/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:54:18 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/21 12:29:46 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*block;

	block = malloc(size * count);
	if (block == NULL)
		return (NULL);
	ft_memset(block, 0, size * count);
	return ((void *)block);
}
