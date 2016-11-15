/*
** tools.c for  in /Users/Rouis/Desktop/ftl
** 
** Made by EL GOHARY Rouis
** Login   <elgoha_r@etna-alternance.net>
** 
** Started on  Fri Nov 11 19:38:25 2016 EL GOHARY Rouis
** Last update Sun Nov 13 21:59:44 2016 EL GOHARY Rouis
*/
#include "ftl.h"

int	random_int()
{
	int i;

	srand(time(NULL));
	i = rand() % 100;
	return i;
}

int	random_in()
{
	int i;

	srand(time(NULL));
	i = rand() % 100;
	return i;
}

void	my_wait(int t)
{
	int	i;

	t *= 3000;
	while (t >= 0)
	{
		i = 30000;
		while (i >= 0)
			--i;
		--t;
	}
}

void	my_nputchar(int n, char c)
{
	int i;

	i = 0;
	while (i++ < n)
	{
		my_putchar(c);
	}
}

void	my_loading(int t)
{
	int		i;

	i = 0;
	while (i <= 100)
	{
		my_putstr("\r");

		my_putstr_color("green", "[");
		my_nputchar(i, '=');
		my_nputchar(100 - i, ' ');
		my_putstr_color("green", "]  ");
		my_put_nbr(i);
		my_putstr("%");
		my_wait(t);
		i++;
	}
	my_putstr("\n");
}

int	my_put_nbr(int n)
{
	int	d;
	int e;

	d = 1;
	e = -2147483647;
	if (n < e)
		my_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			n = (-1) * n;
			my_putchar('-');
		}
		while ((n / d) >= 10)
			d = d * 10;
		while (d > 0)
		{
			my_putchar('0' + ((n / d) % 10));
			d = d / 10;
		}
	}
	return (0);
}
