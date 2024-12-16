/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:34:32 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/16 11:35:02 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_putstr_fd(char *str, int fd)
{
    if (!str)
        return;
    while (*str)
        write(fd, str++, 1);
}

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int ft_atoi_safe(const char *str, int *result)
{
    long res = 0;
    int sign = 1;

    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        res = res * 10 + (*str++ - '0');
        if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN))
            return (0);
    }
    *result = (int)(res * sign);
    return (1);
}
