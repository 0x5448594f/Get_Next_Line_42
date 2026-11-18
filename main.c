/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thyo <derive.theo@proton.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:39:03 by thyo              #+#    #+#             */
/*   Updated: 2026/11/18 18:47:13 by thyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	FILE	*file = fopen("text.txt", "r");
	if (!file)
	{
		printf("No file.");
		return (-1);
	}

	char *test;
	test = get_next_line(fileno(file));
	printf("%s\n", test);
	return (0);
}
