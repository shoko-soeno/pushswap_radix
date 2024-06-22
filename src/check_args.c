/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:18:46 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/22 14:20:49 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

static int	ft_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

bool	ft_isnum(char *num)
{
	size_t	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	while (args[++i])
	{
		tmp = ft_atol(args[i]);
		if (!ft_isnum(args[i]) || ft_duplicate(tmp, args, i)
			|| tmp < -2147483648 || tmp > 2147483647)
			{
				ft_putstr_fd("Error\n", 2);
				//exit(1); //this line will free all of allocated memorty and finish this program
				if (argc == 2){
					ft_free(args);
				}
				return (false);
			}
	}
	if (argc == 2)
		ft_free(args);
	return (true);
}
