/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_make_info_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 09:49:16 by gmoon             #+#    #+#             */
/*   Updated: 2020/03/06 09:49:46 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_spec(const char c)
{
	char	*spec_set;

	spec_set = "cspdiuxX";
	while (*spec_set)
	{
		if (*spec_set == c)
			return (1);
		spec_set++;
	}
	return (0);
}

int	is_flag(const char c)
{
	char	*flag_set;

	flag_set = "-.0123456789";
	while (*flag_set)
	{
		if (*flag_set == c)
			return (1);
		flag_set++;
	}
	return (0);
}
