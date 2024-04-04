/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:01:32 by apresas-          #+#    #+#             */
/*   Updated: 2023/10/18 12:20:48 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include "ft_format.h"
// # include "get_next_line/get_next_line.h"
// # include "ft_printf/ft_printf.h"

# ifndef FAILURE
#  define FAILURE 1
# endif
# ifndef SUCCESS
#  define SUCCESS 0
# endif

typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

int		ft_abs(int num);
long	ft_absl(long num);
float	ft_absf(float num);
double	ft_absd(double num);
double	ft_sqrt(double x);
double	ft_rsqrt(double x);
int		ft_isint(char *str);
int		ft_isuint(char *str);
int		ft_islong(char *str);
int		ft_isulong(char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_istype_iter(const char *s, int (*f)(int));
int		ft_match_ch(int c, const char *pattern);
int		ft_match_str(char *str, const char *pattern);
int		ft_chrcount(char *str, int c);
size_t	ft_strlen(const char *s);
size_t	ft_low_strlen(const char *s1, const char *s2);
int		ft_intlen(int number);
int		ft_uintlen(unsigned int number);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(char *s, int c);
int		ft_strchr_i(char *str, int chr);
char	*ft_strnchr(char *str, int chr);
int		ft_strnchr_i(char *str, int chr);
char	*ft_strrchr(const char *s, int c);
int		ft_strrchr_i(const char *str, int chr);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlcmp(const char *s1, const char *s2);
int		ft_strrcmp(const char *s1, const char *s2);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
t_uint	ft_atou(char *str);
long	ft_strtol(const char *str);
t_ulong	ft_strtoul(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strljoin(char const *s1, long s1_n, char const *s2, long s2_n);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strspn(const char *str, const char *accept);
size_t	ft_strcspn(const char *str, const char *reject);
char	*ft_strtok(char *str, const char *delim);
char	*ft_strtok_r(char *str, const char *delim, char **saveptr);
char	*ft_strpbrk(const char *s, const char *accept);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *str);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
void	ft_putnbr(int nbr);
void	ft_putnbr_unsigned(unsigned int nbr);
void	ft_puthex_fd(size_t hex, int fd);
void	ft_puthex(size_t hex);
void	ft_puthex_case_fd(size_t hex, int letter_case, int fd);
void	ft_puthex_case(size_t hex, int letter_case);
void	ft_putaddress(unsigned long long address);
void	ft_nl(void);
char	*ft_skip_char_ptr(char **str, int ch);
// void	ft_skip_char_ptr(char **str, int ch);
int		ft_skip_chr_i(char *str, int i);
int		ft_skip_char(char *str, int *i, char c);
void	ft_free_array(void **array);
void	ft_free_array_r(void **array, int i);
int		ft_file_lines(int fd);
char	**ft_store_file(int fd, int lines);
void	*ft_alloc_array(size_t size, size_t h, size_t w);

// ft_printf
int		ft_printf(const char *format, ...);
int		ft_printf_fd(int fd, const char *format, ...);

// get_next_line
char	*get_next_line(int fd);

//bonus
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif // LIBFT_H
