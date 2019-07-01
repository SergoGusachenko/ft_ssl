/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:26:11 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/01 04:18:56 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	error(char *str)
{
	ft_putstr(str);
	exit(1);
}

int		check_f(t_ssl **ssl, char *str, char **arg, int position)
{
	int		i;
	int		f;

	i = 1;
	f = 1;
	while (str[i] != '\0')
	{
		if (str[i] == 'p' && (*ssl)->f_s == 0)
			m_p(ssl, str);
		else if (str[i] == 'q'&& (*ssl)->f_s == 0)
		{
			return (*ssl)->f_q = i;
		}
		else if (str[i] == 'r' && (*ssl)->f_s == 0)
			return (*ssl)->f_r = i;
		else if (str[i] == 's')
		{
			m_s(ssl, str, arg, position);
			(*ssl)->f_s++;
		}
		else if((*ssl)->f_s == 0)
			f--;
		i++;
	}
	return (f);
}

void	parse_flag(t_ssl **ssl, char **str)
{
	int i;

	i = 2;
	while (str[i])
	{
		if (str[i][0] == '-')
		{
			if (((*ssl)->max_f = check_f(ssl, str[i], str, i)))
				i++;
			else
				error("invalid option\n");
		}
		else if (str[i][0] != '-')
		{
			(*ssl)->no_f++;
			(*ssl)->file_n = str[i];
		}
		i++;
	}
}

void	get_res(t_ssl **mdf, char **str)
{
	parse_flag(mdf, str);
}
