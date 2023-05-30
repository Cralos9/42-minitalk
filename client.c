/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:36:36 by cacarval          #+#    #+#             */
/*   Updated: 2023/05/26 14:44:33 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	signal_action(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(100);
	}
	bit = 0;
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Format: [./client <SERVER ID (PID)> <STRING>]\n");
		return (1);
	}
	else
	{
		while (argv[2][i] != '\0')
		{
			signal_action(ft_atoi(argv[1]), argv[2][i]);
			i++;
		}
		signal_action(ft_atoi(argv[1]), '\n');
	}
	return (0);
}
