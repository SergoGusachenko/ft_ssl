/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:27:43 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/04 17:38:41 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	init_f(t_ssl **mdf)
{
	(*mdf)->algo = 1;
	(*mdf)->f_p = 0;
	(*mdf)->f_s = 0;
	(*mdf)->f_r = 0;
	(*mdf)->f_q = 0;
	(*mdf)->no_f = 0;
	(*mdf)->msg_len = 0;
	(*mdf)->h0 = 0x67452301;
	(*mdf)->h1 = 0xefcdab89;
	(*mdf)->h2 = 0x98badcfe;
	(*mdf)->h3 = 0x10325476;
	(*mdf)->a = 0x67452301;
	(*mdf)->b = 0xefcdab89;
	(*mdf)->c = 0x98badcfe;
	(*mdf)->d = 0x10325476;
}

void	init_h(t_ssl **mdf)
{
	(*mdf)->msg_len = 0;
	(*mdf)->h0 = 0x67452301;
	(*mdf)->h1 = 0xefcdab89;
	(*mdf)->h2 = 0x98badcfe;
	(*mdf)->h3 = 0x10325476;
	(*mdf)->a = 0x67452301;
	(*mdf)->b = 0xefcdab89;
	(*mdf)->c = 0x98badcfe;
	(*mdf)->d = 0x10325476;
}

void	print_msg(t_ssl *mdf)
{
	uint8_t *p;

	p=(uint8_t *)&mdf->h0;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p=(uint8_t *)&mdf->h1;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p=(uint8_t *)&mdf->h2;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p=(uint8_t *)&mdf->h3;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	if(mdf->f_r == 0)
		ft_printf("\n");
}

void	mdf_main(t_ssl **mdf, uint32_t *w)
{
	int i;
	uint32_t g;
	uint32_t f;

	for(i = 0; i<64; i++)
	{
		if (i < 16) {
			f = ((*mdf)->b & (*mdf)->c) | ((~(*mdf)->b) & (*mdf)->d);
			g = i;
		} else if (i < 32) {
			f = ((*mdf)->d & (*mdf)->b) | ((~(*mdf)->d) & (*mdf)->c);
			g = (5 * i + 1) % 16;
		} else if (i < 48) {
			f = (*mdf)->b ^ (*mdf)->c ^ (*mdf)->d;
			g = (3 * i + 5) % 16;
		} else {
			f = (*mdf)->c ^ ((*mdf)->b | (~(*mdf)->d));
			g = (7 * i) % 16;
		}
		uint32_t temp = (*mdf)->d;
		(*mdf)->d = (*mdf)->c;
		(*mdf)->c = (*mdf)->b;
		(*mdf)->b = (*mdf)->b + LEFTROTATE(((*mdf)->a + f + g_k[i] + w[g]), g_r[i]);
		(*mdf)->a = temp;
	}
}

void	md5(unsigned char*initial_msg, t_ssl **mdf)
{
	uint8_t *msg = NULL;
	uint32_t *w;
	int offset;
	size_t initial_len;

	initial_len = (*mdf)->msg_len;
	offset = 0;
	w = NULL;
	int new_len;
	for (new_len = initial_len*8 + 1; new_len%512!=448; new_len++);
	new_len /= 8;
	msg = ft_memalloc(new_len + 64);
	ft_memcpy(msg, initial_msg, initial_len);
	msg[initial_len] = 128;
	uint32_t bits_len = 8 * initial_len;
	ft_memcpy(msg + new_len, &bits_len, 4);
	for (offset=0; offset<new_len; offset += (512/8))
	{
		w = (uint32_t *) (msg + offset);
		mdf_main(mdf, w);
		(*mdf)->h0 += (*mdf)->a;
		(*mdf)->h1 += (*mdf)->b;
		(*mdf)->h2 += (*mdf)->c;
		(*mdf)->h3 += (*mdf)->d;
	}
	free(msg);
}

void	mdf_manage(char	**str)
{
	t_ssl *mdf;
	mdf = ft_memalloc(sizeof(t_ssl));
	init_f(&mdf);
	get_res(&mdf, str);
	free(mdf);
}
