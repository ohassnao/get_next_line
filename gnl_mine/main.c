/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:11:23 by ohassnao          #+#    #+#             */
/*   Updated: 2022/11/25 15:45:15 by ohassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("file", O_CREAT | O_RDWR);
	printf("*/%s/*", get_next_line(fd));
	printf("*/%s/*", get_next_line(fd));
	printf("*/%s/*", get_next_line(fd));
}

