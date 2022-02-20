/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:57:03 by dkarhan           #+#    #+#             */
/*   Updated: 2022/02/19 16:57:08 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s)
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' || c == '\0')
	{
		if (s[i] == (char) c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *my_str, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	if (!my_str)
	{
		my_str = malloc(1);
		my_str[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(my_str) + ft_strlen(buffer)) + 1));
	i = -1;
	j = 0;
	if (my_str)
		while (my_str[++i] != '\0')
			str[i] = my_str[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(my_str) + ft_strlen(buffer)] = '\0';
	free(my_str);
	return (str);
}

char	*new_line(char *my_str)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!my_str[i])
		return (NULL);
	while (my_str[i] && my_str[i] != '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!new_line)
		return (NULL);
	i = 0;
	while (my_str[i] && my_str[i] != '\n')
	{
		new_line[i] = my_str[i];
		i++;
	}
	if (my_str[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*my_new_str(char *my_str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	while (my_str[i] != '\n' && my_str[i])
		i++;
	if (!my_str[i])
	{
		free(my_str);
		return (NULL);
	}
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(my_str) - i + 1));
	if (!new_str)
		return (NULL);
	j = 0;
	while (my_str[i++])
		new_str[j++] = my_str[i];
	new_str[j] = '\0';
	free(my_str);
	return (new_str);
}
