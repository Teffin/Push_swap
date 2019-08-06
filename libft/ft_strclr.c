/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:01:34 by hharrold          #+#    #+#             */
/*   Updated: 2018/11/30 19:01:42 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int		a;

	a = 0;
	if (s)
	{
		while (s[a] != '\0')
		{
			s[a] = '\0';
			a++;
		}
	}
}