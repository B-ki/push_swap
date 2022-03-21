/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:37:43 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/21 16:18:42 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_next_line(int fd)
{
	static char	*prev;
	char		*buff;
	int			ret;

	if (!prev)
		prev = NULL;
	buff = malloc(sizeof(char) * (50 + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (ret > 0 && !gnl_strchr(prev))
	{
		ret = read(fd, buff, 50);
		if (ret > 0)
		{
			buff[ret] = '\0';
			prev = ft_join(buff, prev);
		}
	}
	free (buff);
	if (ret < 0)
		return (NULL);
	return (ft_newline(&prev));
}

char	*gnl_substr(char *str, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	if (ft_strlen(str) < start)
	{
		dest = malloc(sizeof(char));
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(sizeof(char) * (ft_strlen(str) - start + 1));
	if (!dest)
		return (NULL);
	while (str[start] && i < len)
	{
		dest[i] = str[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*gnl_strchr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == 10)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_join(char *buff, char *prev)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (strlen_gnl(buff) + strlen_gnl(prev) + 1));
	if (!dest)
		return (NULL);
	while (prev && prev[i])
	{
		dest[i] = prev[i];
		i++;
	}
	while (buff && buff[j])
	{
		dest[i] = buff[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	free (prev);
	return (dest);
}

char	*ft_newline(char **prev)
{
	int		sz;
	char	*newline;
	char	*tmp;

	sz = 0;
	newline = NULL;
	tmp = *prev;
	if (*prev)
	{
		sz = gnl_strchr(*prev) - *prev + 1;
		newline = gnl_substr(*prev, 0, sz);
		*prev = gnl_substr(*prev, sz, strlen_gnl(*prev) - sz);
		free (tmp);
		return (newline);
	}
	return (NULL);
}
