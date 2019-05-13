/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:33:19 by yhliboch          #+#    #+#             */
/*   Updated: 2018/11/26 15:56:46 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <inttypes.h>
# include <stdio.h>
# define BUFF_SIZE 42
# define ABS(x) ((x < 0) ? (-x) : (x))

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *rs1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
											const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char *s);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memset(void *b, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_atoi(const char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strclr(char *s);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
int					get_next_line(const int fd, char **line);

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *src, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char				*check_change(char *fmt, va_list ap, t_list **list);
int					ft_printf(const char *format, ...);
char				*ft_itoa_u(unsigned long long int n);
char				*ft_itoa_base(unsigned long long int n, int base);
char				*ft_itoa_f(long double n);

typedef struct		s_flags
{
	int				hyp;
	int				plus;
	int				hesh;
	int				zero;
	int				space;
	int				nul;
}					t_flags;

typedef struct		s_mod
{
	int				width;
	int				preci;
	int				sign;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				ld;
	int				x;
	int				j;
	int				z;
}					t_mod;

char				*is_fl(char *fmt, t_flags **fl);
char				*is_width(va_list ap, char *fmt, t_mod **md, t_flags **fl);
char				*is_preci(va_list ap, char *fmt, t_mod **md);
char				*is_mod(char *fmt, t_mod **md);
void				make_new_fmt(t_list **list, char *res);
char				*check(va_list ap, char *fmt, t_flags **fl, t_mod **md);
void				make_width_s(char **res, t_flags *fl, t_mod *md);
char				*inf(t_flags *fl, t_mod **md);
void				make_flags_f(char **res, t_flags *fl, t_mod *md);

char				*d_printf(va_list ap, t_flags *fl, t_mod **md);
char				*u_printf(va_list ap, t_flags *fl, t_mod *md);
char				*o_printf(va_list ap, t_flags *fl, t_mod *md);
char				*x_printf(va_list ap, t_flags *fl, t_mod *md);
char				*ft_itoa_x(unsigned long long int n, t_mod *md);
char				*p_printf(va_list ap, t_flags *fl, t_mod *md);
char				*s_printf(va_list ap, t_flags *fl, t_mod *md);
char				*c_printf(va_list ap, t_flags *fl, t_mod *md, char *fmt);
char				*change(char *fmt, va_list ap, t_flags *fl, t_mod **md);
char				*percent(t_flags *fl, t_mod *md);
char				*f_printf(va_list ap, t_flags *fl, t_mod **md);
double				ft_round(double n, t_mod *md);
char				*ft_itoa_d(long long n, t_mod **md);
int					ft_num_words(char	*str, int sep);
char				*ft_strndup(const char *s1, int n);

#endif
