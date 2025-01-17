/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:11:02 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/16 18:09:19 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define PATH_SEPARATE '/'

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# define STRGEN_BUFFSIZE 20

typedef struct s_strgen
{
	char *str;                  //メインの文字列を保持するポインタ
	char buff[STRGEN_BUFFSIZE]; //一時的なデータを蓄積するバッファ
	size_t position;            //バッファ内の現在の書き込み位置
	int error;                  //エラーフラグ
}					t_strgen;

typedef struct s_bufferio
{
	int				fd;
	t_strgen		*strgen;
}					t_bufferio;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int i);
int					ft_isalpha(int i);
int					ft_isascii(int i);
int					ft_isdigit(int i);
int					ft_isprint(int i);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, int i);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int i);
int					ft_toupper(int i);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *str, char c);
int					abs(int nbr);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_strcmp(const char *s1, const char *s2);
void				*ft_2darraynew(size_t size, size_t width, size_t height);
double				ft_atof(const char *str);
int					ft_isspace(int c);
void				ft_2darraydel(void *array);
int					ft_bufferioread(t_bufferio *io);
t_bufferio			*ft_bufferionew(int fd, int close_on_error);
void				ft_bufferiodel(t_bufferio *io, int do_close);
void				ft_strgendel(t_strgen *strgen);
void				ft_strgenflush(t_strgen *strgen);
t_strgen			*ft_strgennew(void);
char				*ft_strgenfetch(t_strgen *strgen, size_t len);
void				ft_strgenchr(t_strgen *strgen, char insert);
void				ft_strgenstr(t_strgen *strgen, char *insert);
char				*ft_strgencomp(t_strgen *strgen);
char				*ft_strjoin2(char const *s1, char const *s2);
size_t				ft_xlstlen(void *lst, size_t size);
int					ft_xlstpop(void *lst_ptr, size_t size, int index,
						void *dst);
void				*ft_xlst2array(void *lst, size_t size, size_t *__len);
void				ft_xlstclear(void *lst_ptr, size_t size);
int					ft_xlstappend(void *lst_ptr, size_t size, void *new);
char				*ft_readline(t_bufferio *io);
char				*ft_joinpath(char *base, char *path);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);
#endif