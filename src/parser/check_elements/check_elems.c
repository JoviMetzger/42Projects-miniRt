/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_elems.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 15:13:37 by smclacke      #+#    #+#                 */
/*   Updated: 2024/03/12 15:14:45 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/parser.h"

int	check_a(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == 'A')
		return (1);
	return (0);
}

int	check_c(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == 'C')
		return (1);
	return (0);
}

int	check_l(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == 'L')
		return (1);
	return (0);
}

int	check_sp(char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && str[i] + 1)
	{
		if (str[i] == 's' && str[i + 1] == 'p')
			return (1);
	}
	return (0);
}

int	check_cy(char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && str[i] + 1)
	{
		if (str[i] == 'c' && str[i + 1] == 'y')
			return (1);
	}
	return (0);
}
