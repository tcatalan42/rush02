/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcatalan <tcatalan@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:41:55 by tcatalan          #+#    #+#             */
/*   Updated: 2026/03/22 01:47:23 by tcatalan         ###   ########.be       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = -1;
	while(str[++i]);
	return (i);
}

char	**split_char(char *str)
{
	char	**res;
	int		len;
	int		first_block_size;
	int		i;
	char	*first_block;
	char	*block;
	int		j;
	int		block_index;

	len = ft_strlen(str);

	if (len % 3 == 0)
		res = malloc(((len / 3) + 1) * sizeof(char *));
	else
		res = malloc(((len / 3) + 2) * sizeof(char *));

	if (len % 3 == 0)
		first_block_size = 3;
	else
		first_block_size = len % 3;

	first_block = malloc((first_block_size + 1) * sizeof(char));
	i = -1;
	while(++i < first_block_size)
		first_block[i] = str[i];
	first_block[i] = '\0';
	block_index = 0;
	res[block_index] = first_block;
	i = -1;
	j = first_block_size - 1;
	while (++j < len)
	{
		block = malloc((3 + 1) * sizeof(char));
		while (++i < 3)
		{
			block[i] = str[j];
			j++;
		}
		block[i] = '\0';
		res[++block_index] = block;
		i = -1;
		j -= 1;
	}
	res[++block_index] = NULL;
	return (res);
}

int		main(void)
{
	char **result;
	int		i;

	result = split_char("1234666436347843678784389548735489345768348978348943783489347823490344647457376373536567");
	i = -1;

	while (result[++i])
		printf("bloc %d = %s\n", i, result[i]);
	
	return (0);
}
