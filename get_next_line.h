/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codecham <codecham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:41:51 by codecham          #+#    #+#             */
/*   Updated: 2021/10/27 22:05:41 by codecham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// # define BUFFER_SIZE 1000000

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


char	*get_next_line(int fd);

#endif