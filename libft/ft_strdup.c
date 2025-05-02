/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:19:33 by najlghar          #+#    #+#             */
/*   Updated: 2025/01/19 12:19:35 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//strdup, strdup -- save a copy of a string

#include "libft.h"
/**
 * copiar una cadena de caracteres a un str[malloc]
 * 
 * la candena de caracteres que recibimos
 * char* la cadena de caractares almacenada en malloc
 */

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(ft_strlen(s1) + 1);
	if (!new)
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
//antes de asignar el malloc 
	//hay que calcular la lengitude de la cadena principal s
		// copia la cadena s en la cadena nueva new
	// libero la nuva cadena con free
	//free(new); // estoy sacando mi espacio de la memoria con el free
	// devuelvo la nueva cad