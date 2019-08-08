/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:09:51 by nouhaddo          #+#    #+#             */
/*   Updated: 2019/08/05 16:53:53 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** ----------------------------------------------------------------------------
** 								  Includes
** ----------------------------------------------------------------------------
*/

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

/*
** ----------------------------------------------------------------------------
** 								define colors
** ----------------------------------------------------------------------------
*/

# define BLACK(x) "\033[30;1m" x "\033[0m"
# define RED(x) "\033[31;1m" x "\033[0m"
# define GREEN(x) "\033[32;1m" x "\033[0m"
# define YELLOW(x) "\033[33;1m" x "\033[0m"
# define BLUE(x) "\033[34;1m" x "\033[0m"
# define MAGENTA(x) "\033[35;1m" x "\033[0m"
# define CYAN(x) "\033[36;1m" x "\033[0m"
# define WHITE(x) "\033[37;1m" x "\033[0m"

/*
** ----------------------------------------------------------------------------
** 								Constant variables
** ----------------------------------------------------------------------------
*/

# define D_BIAS 1023
# define D_MX_SIZE 2044
# define LD_BIAS 16383
# define LD_MX_SIZE 32766

/*
** ----------------------------------------------------------------------------
** 								User defined type
** ----------------------------------------------------------------------------
*/

typedef struct		s_bool
{
	int				b:1;
}					t_bool;

typedef struct		s_str
{
	char			*str;
	struct s_str	*next;
}					t_str;

typedef struct		s_int
{
	int				d;
	struct s_str	*next;
}					t_int;

typedef struct		s_addr
{
	void			*addr;
	struct s_addr	*next;
}					t_addr;

typedef struct		s_queue
{
	t_addr			*first;
	t_addr			*last;
}					t_queue;

/*
** ----------------------------------------------------------------------------
** 								Math functions
** ----------------------------------------------------------------------------
*/

int					ft_atoi(const char *str);
int					ft_abs(int x);
long long			ft_binpow(long long n, int pow, long long mod);

/*
** ----------------------------------------------------------------------------
** 							Bit Manipulation functions
** ----------------------------------------------------------------------------
*/

int					ft_bits_extend(int number, int s, int p);

/*
** ----------------------------------------------------------------------------
** 						  Memory Manipulation functions
** ----------------------------------------------------------------------------
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
** ----------------------------------------------------------------------------
** 						  String Manipulation functions
** ----------------------------------------------------------------------------
*/

size_t				ft_strlen(const char *str);
int					ft_strwlen(int *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strnchr(const char *s, int c, size_t size);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *s, const char *find, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);

/*
** ----------------------------------------------------------------------------
** 						  	String list functions
** ----------------------------------------------------------------------------
*/

t_str				*ft_new_t_str(char *s, int len);
t_str				*ft_find_t_str(t_str *head, char *s);
void				ft_print_t_str(t_str *head);
void				ft_free_t_str(t_str *head);

/*
** ----------------------------------------------------------------------------
** 						  	Address list functions
** ----------------------------------------------------------------------------
*/

t_addr				*ft_new_t_addr(void *addr);
void				ft_free_t_addr(t_addr *head);
t_addr				*ft_push_t_addr(t_addr *head, void *addr, int *added);

/*
** ----------------------------------------------------------------------------
** 						  	   Char functions
** ----------------------------------------------------------------------------
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** ----------------------------------------------------------------------------
** 						  	   Read functions
** ----------------------------------------------------------------------------
*/

char				*ft_get_file_content(int fd, int size);

/*
** ----------------------------------------------------------------------------
** 						  	  Print functions
** ----------------------------------------------------------------------------
*/

int					ft_putchar(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*searchlist(t_list *src, void *content);
int					ft_lstcount(t_list *head);
t_list				*ft_lstconcate(t_list *list1, t_list *list2);
t_list				*ft_remove_item(t_list *list, t_list *item);
t_list				*ft_listrevers(t_list *list);

/*
** ft_printf
*/

typedef struct		s_prefix
{
	int				d;
	char			*f;
	int				w;
	int				p;
	int				s;
	char			t;
}					t_prefix;

int					ft_printf(const char *format, ...);
int					ft_print_global(t_prefix *pr, va_list ap);
int					ft_print_c(t_prefix *pr, int c);
int					ft_print_wc(t_prefix *pr, int c);
int					ft_print_s(t_prefix *pr, char *str);
int					ft_print_ws(t_prefix *pr, char *str);
int					ft_print_percente(t_prefix *pr);
char				*ft_add_pref(char *s, t_prefix *pr);
int					ft_print_nbr(char *s, t_prefix *pr);
int					ft_reconize_flag(char *s, t_prefix *pr);
char				*ft_sign(long long n);
char				*ft_uns(unsigned long long dec, int base);
int					ft_print_double(double f, t_prefix *pr);
int					ft_print_long_double(long double f, t_prefix *pr);
char				*ft_pow_of_5(char *holder, size_t h_len, size_t power);
void				ft_sum(char *s1, int l1, char *s2, int l2);
void				ft_div_by_2(char *s, int len, int repeat);
void				ft_mult_by_2(char *s, int len, int repeat);
void				ft_round(char *f, int len, int pr);
int					base_to_dec(char *nbr, int base);
int					ft_pow(int n, int p);
char				*ft_read_memory(char *p, int bytes);
void				*ft_realloc(void *tab, int oldlen, int newlen, size_t size);
int					ft_put_ntime(char c, int n);
void				ft_strrev(char *str);
void				ft_strlowercase(char *str);
char				*ft_strndup(char *src, size_t len);
int					ft_lputnstr(char *str, int n);
int					ft_lputstr(char *str);
int					ft_findchar(char *str, char c);

void				ft_startc(int colorcode);
void				ft_endc(void);
void				ft_error(char *error_msg);
int					ft_count_if(char **tab, int (*f)(char*));
int					ft_sqrt(int nb);
void				ft_intsort(int *tab, int size);
void				ft_strsort(char **tab, int wordcount);
int					ft_charreplace(char *str, char from, char to);
int					ft_putnbr_base(long nbr, char *base);
int					ft_putwchar(int c);
void				ft_putwstr(int *s);

/*
** ----------------------------------------------------------------------------
** 						  	  Queue functions
** ----------------------------------------------------------------------------
*/

t_queue				*ft_new_queue(void);
void				ft_enque(t_queue *q, void *data);
void				ft_pop(t_queue *q);

/*
** ----------------------------------------------------------------------------
** 						  	  		End
** ----------------------------------------------------------------------------
*/

#endif
