/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:57:01 by dkarhan           #+#    #+#             */
/*   Updated: 2022/02/19 17:53:07 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*_line(int fd, char *my_str)
{
	char	*buffer;
	int		a;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(my_str, '\n') && (a = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[a] = '\0';
		my_str = ft_strjoin(my_str, buffer);
	}
	free(buffer);
	return (my_str);
}

char	*get_next_line(int fd)
{
	static char	*my_str[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	my_str[fd] = _line(fd, my_str[fd]);
	if (!my_str[fd])
		return (NULL);
	line = new_line(my_str[fd]);
	my_str[fd] = my_new_str(my_str[fd]);
	return (line);
}

int	main()
{
	int	fd1;
	int	fd2;
	int	fd3;
	char	*line1;
	char	*line2;
	char	*line3;

	fd1 = open("/Users/dkarhan/Desktop/get_next_line_tester/files/alternate_line_nl_with_nl", O_RDONLY);
	fd2 = open("/Users/dkarhan/Desktop/get_next_line_tester/files/multiple_line_no_nl", O_RDONLY);
	fd3 = open("/Users/dkarhan/Desktop/get_next_line_tester/files/multiple_line_with_nl", O_RDONLY);
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
	while (*line1 || *line2 || *line3)
	{
		printf("line 1: %s", line1);
		printf("line 2: %s", line2);
		printf("line 3: %s", line3);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line2 = get_next_line(fd3);
	}
}
