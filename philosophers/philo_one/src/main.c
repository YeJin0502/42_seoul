/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 20:43:51 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/10 21:09:59 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

#include <stdio.h>

int main(int argc, char** argv)
{
	t_args* args;

	args = (t_args*)malloc(sizeof(t_args));
	if (argc == 5)
	{
		args->num_of_ph = atoi(argv[1]); // 예외처리는 나중에.
		args->time_to_die = atoi(argv[2]);
		args->time_to_eat = atoi(argv[3]);
		args->time_to_sleep = atoi(argv[4]);
		args->num_of_times_must_eat = -1;

		printf("%d %d %d %d %d\n", args->num_of_ph, args->time_to_die, args->time_to_eat,args->time_to_sleep, args->num_of_times_must_eat);
	}
	else if (argc == 6)
	{
		args->num_of_ph = atoi(argv[1]); // 예외처리는 나중에.
		args->time_to_die = atoi(argv[2]);
		args->time_to_eat = atoi(argv[3]);
		args->time_to_sleep = atoi(argv[4]);
		args->num_of_times_must_eat = atoi(argv[5]);

		printf("%d %d %d %d %d\n", args->num_of_ph, args->time_to_die, args->time_to_eat,args->time_to_sleep, args->num_of_times_must_eat);
	}
	else
	{
		ft_putendl("error"); // 에러처리도 나중에.
		free(args);
		return (1);
	}
	
}