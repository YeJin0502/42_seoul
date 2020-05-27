/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_s2free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanam <sanam@studenr.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:29:04 by sanam             #+#    #+#             */
/*   Updated: 2020/04/30 15:29:15 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin_s2free(char *s1, char *s2)
{
	char		*ret;

	ret = ft_strjoin(s1, s2);
	free(s2);
	return (ret);
}