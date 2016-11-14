/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:04:26 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/14 09:47:36 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

void	ft_lstdelcontent(void *content, size_t content_size)
{
	free(content);
	content = NULL;
	content_size = 0;
}

/*
** Takes data input from a lista and converts it to a string
** Returns the new str or NULL on failure
*/

char	*lst_to_str(t_list *lst, size_t file_size)
{
	char	*str_data;

	if ((str_data = (char *)malloc(sizeof(char) * file_size + 1)) == NULL)
		return (NULL);
	str_data[file_size] = '\0';
	while (lst)
	{
		ft_strncat(str_data, lst->content, lst->content_size);
		lst = lst->next;
	}
	ft_lstdel(&lst, &ft_lstdelcontent);
	free(lst);
	return (str_data);
}

/*
** Reads from the file and stores data in a linked-list. Then sends that list
** to receive a string with all data
** Returns the string created from file data
*/

char	*file_to_str(int fd)
{
	t_list	*lst;
	char	*buffer;
	size_t	bytes_read;
	size_t	file_size;

	lst = NULL;
	file_size = 0;
	if ((buffer = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))) == NULL)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUF_SIZE)))
	{
		file_size += bytes_read;
		if (file_size > 550)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		ft_lstaddback(&lst, ft_lstnew(buffer, BUF_SIZE + 1));
	}
	free(buffer);
	buffer = NULL;
	if (file_size < 20)
		return (NULL);
	return (lst_to_str(lst, file_size));
}

/*
** Opens/closes the file defined in the path. Calls functions to convert file
** to string
** Returns the string created from file data
*/

char	*open_close_file(char *path)
{
	int		fd;
	char	*file_data;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	file_data = file_to_str(fd);
	if (close(fd) == -1)
		return (NULL);
	return (file_data);
}
