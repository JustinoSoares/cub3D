/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre <joandre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:29:23 by joandre           #+#    #+#             */
/*   Updated: 2025/01/16 15:17:02 by joandre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concatenar_e_liberar(char *texto, char *buffer)
{
	char	*temp;

	temp = f_strjoin(texto, buffer);
	free(texto);
	return (temp);
}

char	*ler_primeira_linha(int descritor_arquivo, char *texto)
{
	char	*buffer;
	int		bytes_lidos;

	if (!texto)
		texto = f_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_lidos = 1;
	while (bytes_lidos > 0)
	{
		bytes_lidos = read(descritor_arquivo, buffer, BUFFER_SIZE);
		if (bytes_lidos == -1)
		{
			free(texto);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_lidos] = 0;
		texto = concatenar_e_liberar(texto, buffer);
		if (f_strchr(texto, '\n'))
			break ;
	}
	free(buffer);
	return (texto);
}

char	*obter_linha(char *texto)
{
	int		i;
	char	*str;

	i = 0;
	if (!texto[i])
		return (NULL);
	while (texto[i] && texto[i] != '\n')
		i++;
	str = f_calloc(i + 2, sizeof(char));
	i = 0;
	while (texto[i] && texto[i] != '\n')
	{
		str[i] = texto[i];
		i++;
	}
	if (texto[i] && texto[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*limpar_primeira_linha(char *texto)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (texto[i] && texto[i] != '\n')
		i++;
	if (!texto[i])
	{
		free(texto);
		return (NULL);
	}
	str = f_calloc((f_strlen(texto) - i + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (texto[++i])
		str[j++] = texto[i];
	str[j] = '\0';
	free(texto);
	return (str);
}

char	*get_next_line(int descritor_arquivo)
{
	char		*texto_saida;
	static char	*texto;

	if (descritor_arquivo < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	texto = ler_primeira_linha(descritor_arquivo, texto);
	if (!texto)
		return (NULL);
	texto_saida = obter_linha(texto);
	texto = limpar_primeira_linha(texto);
	return (texto_saida);
}
