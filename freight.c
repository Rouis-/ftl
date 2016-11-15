/*
** freight.c for  in /Users/Rouis/Desktop/ftl
** 
** Made by EL GOHARY Rouis
** Login   <elgoha_r@etna-alternance.net>
** 
** Started on  Sat Nov 12 00:24:18 2016 EL GOHARY Rouis
** Last update Sun Nov 13 22:08:11 2016 EL GOHARY Rouis
*/
#include "ftl.h"

int		charge_container(t_ship *ship)
{
	int	i;
	t_freight *freight;

	add_container_to_ship(ship);
	freight = NULL;
	i = 0;
	while (i < 10)
	{
		freight = create_freight();
		add_freight_to_container(ship, freight);
		my_putstr_color("blue", "[BONUS] Bonus obtenu\n");
		++i;
	}
	return 0;
}

t_freight		*create_freight()
{
	t_freight	*freight;
	int	n;

	n = random_int();
	my_putstr("n = ");
	my_put_nbr(n);
	my_putstr("\n");
	freight = malloc(sizeof(t_freight));
	if (freight == NULL)
	{
		my_putstr_color("red", "freight null...\n");
		return 0;
	}
	if (n >= 0 && n < 70)
		freight->item = "scrap";
	else
		random_freight(freight);
	return freight;
}

void	random_freight(t_freight *freight)
{
	int	m;

	m = random_int();
	my_putstr("m = ");
	my_put_nbr(m);
	my_putstr("\n");
	if (m >= 0 && m < 33)
		freight->item = "attackbonus";
	else if (m >= 33 && m < 66)
		freight->item = "evadebonus";
	else if (m >= 66 && m < 99)
		freight->item = "energy";
	else
		random_freight(freight);
}
