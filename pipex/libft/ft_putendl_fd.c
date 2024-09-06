/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:18:26 by floris            #+#    #+#             */
/*   Updated: 2023/11/23 16:22:44 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*output;

	if (!s)
		return;
	output = s;
	while (*output)
	{
		ft_putchar_fd(*output, fd);
		output++;
	}
	ft_putchar_fd('\n', fd);
}
