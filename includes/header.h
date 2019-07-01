#ifndef HEADER_H
# define HEADER_H
# define NUM_F 100
# include "../libft/libft.h"
# include "printf.h"
# include <stdint.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
# define BUFFSIZE	(int)(5 * 1e3)
typedef struct		s_ssl
{
	int				f_p;
	int				f_q;
	int				f_r;
	int				f_s;
	int				no_f;
	int				max_f;
	char			*file_n;
	size_t			msg_len;
	uint32_t		h0;
	uint32_t		h1;
	uint32_t		h2;
	uint32_t		h3;
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
}					t_ssl;

static		uint32_t g_r[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
							5, 9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
							4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
							6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

static		uint32_t g_k[64] = {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

typedef void		(*t_s_func)(char **str);
int					get_hash(char *str);
void				get_res(t_ssl **mdf, char **str);
t_s_func			get_s_func(char *specifier);
void				m_p(t_ssl **ssl, char *str);
void				m_s(t_ssl **ssl, char *str, char **arg, int pos);
int					check_f(t_ssl **ssl, char *str, char **arg, int position);
void				parse_flag(t_ssl **ssl, char **str);
void				print_msg(t_ssl *mdf);
void				mdf_manage(char	**str);
char				*read_file(t_ssl **ssl, char *str);
unsigned char		*file_r(t_ssl **ssl, char **str);
void				shatfs_manage(char	**str);
void				error(char *str);
void				mdf_res(t_ssl **mdf, char **str);
void				md5(unsigned char*initial_msg, t_ssl **mdf);

#endif
