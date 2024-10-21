/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:18:26 by floris            #+#    #+#             */
/*   Updated: 2024/10/21 17:51:51 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*output;

	if (!s)
		return ;
	output = s;
	while (*output)
	{
		ft_putchar_fd(*output, fd);
		output++;
	}
	ft_putchar_fd('\n', fd);
}
