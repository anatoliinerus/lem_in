/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:44:26 by anerus            #+#    #+#             */
/*   Updated: 2018/11/12 16:21:19 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <limits.h>

# define BUFF_SIZE 100

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_debug(int i);
int					ft_sort_dig(int *sort, int size);
void				ft_swap(int *a, int *b);
void				ft_sortwords(char *str);
size_t				ft_strlen(const char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *str, int fd);
int					ft_isdigit(int d);
int					ft_isalpha(int c);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				*ft_memset(void *memptr, int val, size_t num);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *destptr, const void *srcptr, size_t num);
void				*ft_memccpy(void *dest, const void *source,
					int ch, size_t count);
void				*ft_memmove(void *destptr, const void *srcptr, size_t num);
void				*ft_memccpy(void *dest, const void *source,
					int ch, size_t count);
int					ft_atoi(const char *str);
int					ft_isalnum(int d);
void				*ft_memchr(const void *memptr, int val, size_t i);
int					ft_memcmp(const void *s1, const void *s2, size_t num);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *a, const char *b);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
int					ft_isprint(int c);
int					ft_isascii(int c);
void				ft_toupper(char *str);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int num, int fd);
void				ft_putnbr(int num);
char				*ft_itoa(long n);
char				*ft_strtrim(char const *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_word_count(char const *s, char c);
char				**ft_strsplit(char const *s, char c);
size_t				ft_word_len(char const *s, char c, size_t i);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_putnstr_fd(char const *str, size_t str_len, int fd);
void				ft_putnstr(char const *str, size_t str_len);
char				*ft_itoa_base(unsigned long n, int base);
char				*ft_ftoa(double n);
char				*ft_longtoa_u(unsigned long n);
int					get_next_line(const int fd, char **line);

#endif
