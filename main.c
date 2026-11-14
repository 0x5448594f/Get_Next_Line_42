/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderive </var/spool/mail/tderive>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 08:50:03 by tderive           #+#    #+#             */
/*   Updated: 2026/11/14 09:21:50 by tderive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	FILE	*file;
	char	*test;

	file = fopen("text.txt", "r");
	if (file == NULL)
	{
		printf("Failed");
		return (-1);
	}
	test = get_next_line(fileno(file));
	printf("test = %s\n", test);
	test = get_next_line(fileno(file));
	printf("test = %s\n", test);
	return (0);
}
