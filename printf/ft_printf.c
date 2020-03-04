/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:09:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/05 05:33:49 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <stdio.h>

int ft_printf(const char *format, ...)
{
	int ret;
	int count_s;
	va_list ap;
	char **flags;
	char *specs;
	t_info *info;
	int i;

	ret = 0;
	if (!(count_s = count_spec(format)))
	{
		printf("[ft_strlen:%zu]\n", ft_strlen(format));
		write(1, format, ft_strlen(format));
		return (ft_strlen(format));
	} // 이런거도 함수 빼버릴 수도 있겠다.
	va_start(ap, format);
	flags = make_flags(format, count_s);
	specs = make_specs(format, count_s);
	info = make_list(specs, flags); // 이런건 하나의 함수로 묶을수도 있겠다. free도 마찬가지.
	
	i = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%' && i < count_s)
			format = meet_percent(&ret, format, *(info + i++), ap); // 1.ret 올려주고 2.format을 spec 자리로 이동.
		else
		{
			write(1, format, 1);
			ret++; // 아니면 한글자씩 출력
		}
		format++; // 여기서 spec 넘어감.
	}
	while (--i >= 0) // free
	{
		if (flags[i])
			free(flags[i]);
		free(info[i].flag);
	}
	free(flags);
	free(specs);
	free(info);
	return (ret);
}

// ft_printf 테스트
// int main()
// {
// 	// ft_printf("===============\n"); //OK

// 	// char *a = "hihello";
// 	ft_printf("1: [%d]\n", 2147483648); // 오버, 언더플로우 관리해야.
// 	ft_printf("2: [%u]\n", -1);
// 	ft_printf("3: [%c]\n", 'M');
// 	// ft_printf("4: [%p]\n", a);
// 	// printf("4real: [%p]\n", a);
// 	printf("%d\n", ft_printf("5: [%x]\n", 4294967295)); // 일단 이건 맞음.
// }

// printf 테스트
// int main()
// {
// 	// printf("[%-05d]\n", 123);
// 	// -와 0은 같이 못있음.
	
// 	printf("[%5d]\n", 123); // [  123]
// 	printf("[%05d]\n", 123); // [00123]
// 	printf("[%.5d]\n", 123); // [00123]
// 	// d에선 0과 .이 같은 역할?

// 	printf("[%5d]\n", 123); // [123  ]
// 	printf("[%.5d]\n", 123); // [00123]
// 	printf("[%5.5d]\n", 123); // [00123]
// 	printf("[%-5.5d]\n", 123); // [00123]
// 	printf("[%05.5d]\n", 123); // [00123]
// 	// 우선순위: .5 > - > 5 ?

// 	// printf("[%0d]\n", 123); // [123]
// 	// printf("[%-d]\n", 123); // [123]
// 	// // -와 0은 폭이 없으면 무용지물

// 	printf("[%4.5d]\n", 123); // [00123] 중요!
// 	printf("[%5.4d]\n", 123); // [ 0123] 중요! 이 두개가 가장 핵심!!
// }

typedef struct s_flag
{
	int minus;
	int zero;
	int width;
	int precision;
}	t_flag;

int make_precision(char *flag)
{
	char *tmp;
	int flag_len;
	flag_len = ft_strlen(flag);

	int i;
	i = 0;
	while (flag[flag_len - i - 1] != '.')
		i++;
	if (i == 0)
		return (-1);
	printf("i:%d\n", i);
	tmp = (char *)malloc(i + 1);
	// tmp[i] = '\0';
	int tmp_size = i; // 5
	while (--i > 0)
	{
		tmp[tmp_size - i] = flag[flag_len - i - 1]; // 될까..?
		printf("%d: %c\n", i, flag[flag_len - i - 1]);
	}
	return (ft_atoi(tmp));
}

int main()
{
	printf("%d\n", make_precision("0.44123"));

}

// int make_width(char *flag)
// {

// }

// char *convert_flag(char *c_arg, char *flag)
// {
// 	int i;
// 	i = 0;
// 	while (flag[i])
// 	{
// 		if (flag[i] == '-')
// 	}
// }
