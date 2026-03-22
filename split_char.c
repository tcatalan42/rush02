/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcatalan <tcatalan@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:41:55 by tcatalan          #+#    #+#             */
/*   Updated: 2026/03/22 04:52:59 by tcatalan         ###   ########.be       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	// ------ A SUPPRIMER
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*extract_block(char *str, int start_index, int size)
{
	char	*block;
	int		i;

	i = -1;
	block = malloc((size + 1) * sizeof(char));
	while (++i < size)
	{
		block[i] = str[start_index];
		start_index++;
	}
	block[i] = '\0';
	return (block);
}

char	**split_char(char *str)
{
	char	**res;
	int		len;
	int		j;
	int		first_block_size;
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
	block_index = 0;
	res[block_index] = extract_block(str, 0, first_block_size);
	j = first_block_size - 1;
	while (++j < len)
	{
		res[++block_index] = extract_block(str, j, 3);
		j += 2;
	}
	res[++block_index] = NULL;
	return (res);
}

int	main(void)
{
	char	**result;
	int		i;

	result = split_char("123466978348943783489347823490344647457376373536567");
	i = -1;
	while (result[++i])
		printf("bloc %d = %s\n", i, result[i]);
	i = -1;
	while (result[++i])
		free(result[i]);
	free(result);
	return (0);
}
