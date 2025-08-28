/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhmajee <muhmajee@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:16:11 by muhmajee          #+#    #+#             */
/*   Updated: 2025/08/28 17:53:16 by muhmajee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_isvalid_base(char *base)
{
	int	i;
	int	j;

	if (!base || !base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j++] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	long	result;
	int		base_len;
	int		idx;

	result = 0;
	sign = 1;
	if (!ft_isvalid_base(base))
		return (0);
	base_len = ft_strlen(base);
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((idx == ft_index_in_base(*str, base)) != -1)
	{
		result = result * base_len + idx;
		str++;
	}
	return ((int)result * sign);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_atoi_base("   -101010", "01")); // -42
	printf("%d\n", ft_atoi_base("FF", "0123456789ABCDEF")); // 255
	printf("%d\n", ft_atoi_base("op", "poniguay")); // 8
	printf("%d\n", ft_atoi_base("   +y", "poniguay")); // 7
	printf("%d\n", ft_atoi_base("42", "0123456789")); // 42
	return (0);
}*/
