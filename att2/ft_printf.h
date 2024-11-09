/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:34:36 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/05 17:13:11 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_char(char c);
int		ft_format(int c, va_list args);
int		ft_hex(unsigned int i, int f);
int		ft_int(int i);
char	*ft_itoa(int n);
char	*ft_pointer_base(unsigned long long pointer, int base);
int		ft_pointer(unsigned long long pointer);
int		ft_printf(const char *input, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_str_count(char *c);
int		ft_str(char *str);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_tolower_all(char *c);
int		ft_tolower(int c);
int		ft_uint(unsigned int uint);
int		ft_unfo_output(const char *input, va_list args);

#endif