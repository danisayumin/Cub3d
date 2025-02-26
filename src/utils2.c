/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:55:34 by danielasayu       #+#    #+#             */
/*   Updated: 2025/02/26 16:13:16 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_gnl_memory(int fd)
{
    static	char	*buffer = NULL;

    if (fd < 0)
        return;
// Libera o buffer estático usado pelo get_next_line
    if (buffer)
    {
        free(buffer);
        buffer = NULL;
    }
    // close(fd);
}

void	ft_free_split(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]); // Libera cada string individualmente
		i++;
	}
	free(arr); // Libera o próprio array de ponteiros
}

static int count_words(const char *str, char delimiter)
{
    int count = 0;
    while (*str)
    {
        while (*str == delimiter)
            str++;
        if (*str)
        {
            count++;
            while (*str && *str != delimiter)
                str++;
        }
    }
    return count;
}

// Função que divide a string e retorna um array de substrings
char **ft_split_size(const char *str, char delimiter, int *size)
{
    int i = 0;
    char **result;

    if (!str || !size)
        return NULL;

    *size = count_words(str, delimiter); // Conta as palavras
    result = (char **)malloc((*size + 1) * sizeof(char *)); // Aloca o array de ponteiros
    if (!result)
        return NULL;

    while (*str)
    {
        while (*str == delimiter)
            str++;
        const char *start = str;
        while (*str && *str != delimiter)
            str++;
        if (start != str)
        {
            size_t len = str - start;
            result[i] = (char *)malloc(len + 1);
            if (result[i] == NULL)
            {
                while (i > 0)
                    free(result[--i]);
                free(result);
                return NULL;
            }
            ft_strncpy(result[i], (char *)start, len);
            result[i][len] = '\0';
            i++;
        }
    }
    result[i] = NULL;
    return result;
}

int ft_safe_atoi(const char *str, bool *has_err)
{
    long long result = 0; // Usamos long long para evitar overflow
    int sign = 1;

    *has_err = false;  // Inicializa o erro como falso

    // Se a string for NULL ou vazia, retorna 0
    if (str == NULL || *str == '\0')
    {
        *has_err = true;  // Marca como erro
        return 0;
    }

    // Ignora espaços em branco no início
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' || *str == '\f')
        str++;

    // Verifica se tem um sinal
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    // Converte cada caractere para um número
    while (*str && ft_isdigit(*str))
    {
        result = result * 10 + (*str - '0');
        if (result * sign > INT_MAX)
        {
            *has_err = true;  // Marca erro em caso de overflow
            return INT_MAX;   // Overflow positivo
        }
        if (result * sign < INT_MIN)
        {
            *has_err = true;  // Marca erro em caso de overflow
            return INT_MIN;   // Overflow negativo
        }
        str++;
    }

    // Se a string contém caracteres não numéricos após o número, marca erro
    if (*str != '\0')
    {
        *has_err = true;
    }

    return (int)(result * sign);
}
