/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:31:23 by yyefimov          #+#    #+#             */
/*   Updated: 2017/01/27 11:52:09 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# include <fcntl.h>
# include "libft/libft.h"

int						get_next_line(const int fd, char **line);

typedef struct			s_gnl
{
	int					fd;
	char				*buff;
	struct s_gnl		*next;
}						t_gnl;

#endif
