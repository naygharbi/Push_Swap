/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:16:17 by najlghar          #+#    #+#             */
/*   Updated: 2025/01/19 12:16:20 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - void* no es una variable --> apunta una cadena
// cc es un compilador y ./a.out es un archivo 
#include "libft.h"

int	ft_isprint(int numero)
{
	if (numero >= 32 && numero <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

//int	main(void)
//{
//	int	a;
//	a = ft_isprint('s');
//	printf("%i", a);
//}
