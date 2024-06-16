/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:40:20 by abelov            #+#    #+#             */
/*   Updated: 2024/06/09 22:40:21 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sysexits.h>

int main(int argc, char **argv)
{
	if (argc <= 1)
		exit(EX_USAGE);
	return (EXIT_SUCCESS);
}
