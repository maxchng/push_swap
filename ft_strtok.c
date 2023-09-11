/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:44:12 by ychng             #+#    #+#             */
/*   Updated: 2023/09/11 19:21:57 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*main_str;
	char		*part;
	size_t		i;

	if (str != NULL)
		main_str = str;
	if (delim == NULL)
		delim = " \t\n\r\v\f\b";
	i = 0;
	while (ft_strchr(delim, main_str[i]) && main_str[i])
		i++;
	if (main_str[i] == '\0')
		return (NULL);
	part = main_str + i;
	while (!ft_strchr(delim, main_str[i]) && main_str[i])
		i++;
	if (main_str[i] != '\0')
	{
		main_str[i] = '\0';
		i++;
	}
	main_str += i;
	return (part);
}
