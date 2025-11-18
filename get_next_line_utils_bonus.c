/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouzian <hbouzian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:39:27 by hbouzian          #+#    #+#             */
/*   Updated: 2025/11/18 15:39:28 by hbouzian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s)
{
	char	*buffer;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (*s)
		buffer[i++] = *s++;
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*merged_buffer;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	merged_buffer = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!merged_buffer)
		return (NULL);
	i = 0;
	while (*s1)
		merged_buffer[i++] = *s1++;
	while (*s2)
		merged_buffer[i++] = *s2++;
	merged_buffer[i] = '\0';
	return (merged_buffer);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	chr;

	if (!s)
		return (NULL);
	chr = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == chr)
		return ((char *)&s[i]);
	return (NULL);
}
