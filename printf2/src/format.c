static void	minus_or_zero(char *s_arg, char *cv_arg, t_cont *flag, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (flag->minus == 1)
	{
		while (i < ft_strlen(s_arg))
			cv_arg[i++] = s_arg[j++];
		while (i < size)
			cv_arg[i++] = ' ';
	}
	else
	{
		if (flag->is_nega == 0)
		{
			while (i < size - ft_strlen(s_arg))
				cv_arg[i++] = '0';
			while (i < size)
				cv_arg[i++] = s_arg[j++];
		}
		else
		{
			cv_arg[i++] = '-';
			while (i < size - ft_strlen(s_arg) + 1)
				cv_arg[i++] = '0';
			while (i < size)
				cv_arg[i++] = s_arg[j++ + 1];
		}
	}
}

static void	width_or_prec(char *s_arg, char *cv_arg, t_cont *flag, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (flag->prec)
	{
		if (flag->is_nega == 0)
		{
			while (i < size - flag->prec)
				cv_arg[i++] = ' ';
			while (i < size - ft_strlen(s_arg))
				cv_arg[i++] = '0';
			while (i < size)
				cv_arg[i++] = s_arg[j++];
		}
		else
		{
			while (i < size - flag->prec - 1)
				cv_arg[i++] = ' ';
			cv_arg[i++] = '-';
			while (i < size - ft_strlen(s_arg) + 1)
				cv_arg[i++] = '0';
			while (i < size)
				cv_arg[i++] = s_arg[j++ + 1];
		}
	}
	else
	{
		while (i < size - ft_strlen(s_arg))
			cv_arg[i++] = ' ';
		while (i < size)
			cv_arg[i++] = s_arg[j++];
	}
}

char	*apply_flag(char *s_arg, t_info *info)
{
	t_cont	*flag;
	size_t	size;
	char	*cv_arg;

	flag = (t_cont *)info->curr->content;
	if (s_arg[0] == '-')
		flag->is_nega = 1;
	flag->width = (ft_strlen(s_arg) < flag->width) ? flag->width : 0;
	flag->prec = (ft_strlen(s_arg) < flag->prec) ? flag->prec : 0;
	if (!(size = (flag->width > flag->prec) ? flag->width : flag->prec))
		return (ft_strdup(s_arg));
	if (flag->is_nega && flag->width < flag->prec)
		size++;
	else if (flag->prec)
	{
		flag->minus = 0;
		flag->zero = 0;
	}
	else if (flag->minus && flag->zero)
		flag->zero = 0;	
	if (!(cv_arg = (char *)malloc(size + 1)))
		return (0);
	cv_arg[size] = '\0';
	if (flag->minus || flag->zero)
		minus_or_zero(s_arg, cv_arg, flag, size);
	else
		width_or_prec(s_arg, cv_arg, flag, size);
	return (cv_arg);
}