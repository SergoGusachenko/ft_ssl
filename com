gcc -g main.c manage_f.c dispatch.c utils.c md5.c shatfs.c libft/ft_memcpy.c libft/ft_memalloc.c libft/ft_putstr.c libft/ft_strcmp.c libft/ft_bzero.c libft/ft_putchar.c includes/libftprintf.a
