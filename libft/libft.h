#ifndef LIBFT_H
# define LIBHT_H

typedef int size_t; /* 그냥 int로 해도 되는데 공부삼아... 잘 안되면 int로 바꾸자 */

size_t ft_strlen(char *str);
int ft_atoi(const char *str);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
int ft_strlcpy(char *dest, const char *src, int size);
int ft_strlcat(char *dst, const char *src, int size);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
char *ft_strnstr(const char *big, const char *little, int len);

#endif