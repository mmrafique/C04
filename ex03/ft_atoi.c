/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhmajee <muhmajee@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 00:06:45 by muhmajee          #+#    #+#             */
/*   Updated: 2025/08/28 17:53:39 by muhmajee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(char *str)
{
	int		sign;
	long	result;

	if (!str)
		return (0);
	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(sign * result));
}

/*#include <stdio.h>
int	main(void)
{
	char str1[] = " ---+--+1234ab567";
	printf("atoi: %i\n", atoi(str1));
	printf("ft_atoi: %i\n", ft_atoi(str1));
	return (0);
}*/
