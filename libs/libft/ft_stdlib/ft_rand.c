/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:32:00 by apresas-          #+#    #+#             */
/*   Updated: 2024/03/25 12:58:02 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

unsigned long	*get_seed(void);

// A shittier version of srand
void	ft_srand(unsigned int new_seed)
{
	unsigned long	*seed;

	seed = get_seed();
	*seed = new_seed;
	return ;
}

// A shittier version of rand, it's way less random
int	ft_rand(void)
{
	unsigned long	*seed;

	seed = get_seed();
	*seed = *seed * 1103515245 + 12345;
	return ((unsigned int)(*seed / 65536) % RAND_MAX);
}

unsigned long	*get_seed(void)
{
	static unsigned long	seed;

	if (seed == 0)
		seed = 1;
	return (&seed);
}

/* int	ft_abs(int in)
{
	if (in < 0)
		return (-in);
	return (in);
}

int	main(int argc, char **argv)
{
	printf("Let's test our RNG:\n");
	printf("Seed == 12345");
	srand(13579);
	ft_srand(13579);
	// srand(time(0));
	// ft_srand(time(0));

	int* results;
	results = malloc(sizeof(int) * 6);
	results[0] = 0;
	results[1] = 0;
	results[2] = 0;
	results[3] = 0;
	results[4] = 0;
	results[5] = 0;

	int res;
	int dice_throws = 100000;
	if (argv[1] && argv[1][0] == 'c')
	{
		printf("Let's test randomness of C's rand()\n");
		for (int i = 0; i < dice_throws; i++)
		{
			res = rand() % 6;
			printf("b results[%d] = %d\n", res, results[res]);
			results[res] += 1;
			printf("a results[%d] = %d.\n", res, results[res]);
			res = 0;
		}
	}
	else
	{
		printf("Let's test randomness of ft_rand()\n");
		for (int i = 0; i < dice_throws; i++)
		{
			res = ft_rand() % 6;
			printf("b results[%d] = %d\n", res, results[res]);
			results[res] += 1;
			printf("a results[%d] = %d.\n", res, results[res]);
			res = 0;
		}
	}

	printf("\nResults:\n");
	printf("For %d dice throws, this is the distribution of results:\n", \
	dice_throws);
	printf("\t1: %d\n", results[1 - 1]);
	printf("\t2: %d\n", results[2 - 1]);
	printf("\t3: %d\n", results[3 - 1]);
	printf("\t4: %d\n", results[4 - 1]);
	printf("\t5: %d\n", results[5 - 1]);
	printf("\t6: %d\n", results[6 - 1]);
	int perfect_distribution = dice_throws / 6;
	printf("\nExpected perfect distribution value = %d\n", \
	perfect_distribution);
	printf("Difference from perfect distribution:\n");
	printf("\t1: %d\n", results[1 - 1] - perfect_distribution);
	printf("\t2: %d\n", results[2 - 1] - perfect_distribution);
	printf("\t3: %d\n", results[3 - 1] - perfect_distribution);
	printf("\t4: %d\n", results[4 - 1] - perfect_distribution);
	printf("\t5: %d\n", results[5 - 1] - perfect_distribution);
	printf("\t6: %d\n", results[6 - 1] - perfect_distribution);
	printf("\nAverage distribution = %d\n", (ft_abs((results[0] - \
	perfect_distribution)) + ft_abs((results[1] - perfect_distribution)) \
	+ ft_abs((results[2] - perfect_distribution)) + ft_abs((results[3] - \
	perfect_distribution)) + ft_abs((results[4] - perfect_distribution)) \
	+ ft_abs((results[5] - perfect_distribution))) / 6);
	return (0);
} */
