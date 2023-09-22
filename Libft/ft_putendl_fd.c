/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:18:26 by floris            #+#    #+#             */
/*   Updated: 2023/09/22 22:19:41 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
	char	*output;

	output = s;
	while (*output)
		ft_putchar_fd(*output++, fd);
	ft_putchar_fd('\n', fd);
}