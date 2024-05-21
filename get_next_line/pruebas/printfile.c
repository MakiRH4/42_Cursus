/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:22:54 by fleonte           #+#    #+#             */
/*   Updated: 2024/05/21 14:22:54 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

int gnl(int fd);

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    int fd2 = open("text.txt", O_RDONLY);
    printf("File descriptor number is: %d\n", fd);
    printf("2nd File descriptor number is: %d\n", fd2);
    
    gnl(fd);



    return (0);
}