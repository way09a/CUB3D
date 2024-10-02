/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ahussein <ahussein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:05:19 by Ahussein          #+#    #+#             */
/*   Updated: 2023/08/05 19:05:21 by Ahussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_flag(char *str)
{
	int	x;

	x = -1;
	while (str[++x])
		if (str[x] == '.')
			return (x);
	return (0);
}

int	check_everything(char *str, int x, int count)
{
	x = -1;
	count = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (!(str[1] >= '0' && str[1] <= '9'))
			return (42);
		x++;
	}
	if (str[0] == '.' || str[0] == '\0' || str[ft_strlen(str) - 1] == '.')
		return (42);
	while (str[++x])
	{
		if ((str[x] >= '0' && str[x] <= '9') || str[x] == '.')
		{
			if (str[x] == '.')
				count++;
		}
		else
			return (42);
	}
	if (!((str[x] >= '0' && str[x] <= '9') || str[x] == '\0'))
		return (42);
	if (count > 1)
		return (42);
	return (0);
}

void	do_smtn(t_atof *store, char *s)
{
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			store->sign = -1;
		store->x++;
	}
}

double	ft_atof(char *s)
{
	t_atof		store;
	long double	res;

	if (check_everything(s, 0, 0) == 42)
		return (42);
	store.inde = 0;
	store.x = -1;
	res = 0.0;
	store.flag = check_flag(s);
	store.inde = check_flag(s);
	store.inde = ft_strlen(s) - store.inde;
	store.x = -1;
	store.sign = 1;
	do_smtn(&store, s);
	while (s[++store.x])
		if (s[store.x] >= '0' && s[store.x] <= '9')
			res = (res * 10) + (s[store.x] - '0');
	if (store.flag > 0)
	{
		store.inde = pow(10, store.inde - 1);
		return ((res / store.inde) * store.sign);
	}
	return (res * store.sign);
}
