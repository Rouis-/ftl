/*
** container.c for  in /Users/Rouis/Desktop/ftl
** 
** Made by EL GOHARY Rouis
** Login   <elgoha_r@etna-alternance.net>
** 
** Started on  Thu Nov 10 13:32:54 2016 EL GOHARY Rouis
** Last update Sun Nov 13 22:50:39 2016 EL GOHARY Rouis
*/
#include "ftl.h"

int		add_container_to_ship(t_ship *ship)
{
	t_container	*container;

	my_putstr_color("blue", "[+] Ajout de la cargaison en cours...\n");
	container = malloc(sizeof(t_container));
	if (container == NULL)
	{
		my_putstr_color("red", "[!] Votre vaisseau a explose lorsque vous avez charge la cargaison\n");
		return 0;
	}
	container->nb_elem = 0;
	container->first = NULL;
	container->last = NULL;
	ship->container = container;
	my_putstr_color("green", "[§] Le container a ete ajoute avec succes!\n");
	return 1;
}

void	add_freight_to_container(t_ship *ship, t_freight *freight)
{
	freight->next = NULL;
	if (ship->container->last == NULL)
	{
		freight->prev = NULL;
		ship->container->first = freight;
		ship->container->last = freight;
	}
	else
	{
		ship->container->last->next = freight;		
		freight->prev = ship->container->last;
		ship->container->last = freight;
	}
	++ship->container->nb_elem;
}

int		is_freight_in_container(t_ship *ship, t_freight *freight)
{
	t_freight	*tmp;

	tmp = ship->container->first;
	while ((tmp = tmp->next))
		if (tmp == freight)
			return 1;
	free(tmp);
	return 0;
}

void	del_freight_from_container(t_ship *ship, t_freight *freight)
{
	if (is_freight_in_container(ship, freight))
	{
		if (freight->prev == NULL && freight->next == NULL)
		{
			ship->container->first = NULL;
			ship->container->last = NULL;
		}
		else
		{
			if (freight->prev == NULL)
			{
				ship->container->first = freight->next;
				ship->container->first->prev = NULL;
			}
			else if (freight->next == NULL)
			{
				ship->container->last = freight->prev;
				ship->container->last->next = NULL;
			}
			else
			{
				freight->next->prev = freight->prev;
				freight->prev->next = freight->next;
			}
		}
		free(freight);
		--(ship->container->nb_elem);
	}
}

int		get_bonus(t_ship *ship, t_zone *zone)
{
	t_freight	*tmp;

	if (ship->container != NULL && ship->container->nb_elem != 0)
	{
		my_putstr("[BONUS] Ouverture des cargaisons\n");
/*		aff_container_freight(ship);*/
		tmp = ship->container->first;

		while ((tmp = tmp->next))
		{
			del_freight_from_container(ship, tmp);
			my_putstr_color("green", "nb elem = ");
			my_put_nbr(ship->container->nb_elem);
			my_putstr("\n");
			my_putstr(tmp->item);
			my_putstr("\n");
		}
		zone->container_exist = 0;
		return 0;
	}
	my_putstr_color("red", "[BONUS] Pas de cargaisons a ouvrir\n");
	my_putstr_color("red", "[BONUS] FINNNN\n");
	aff_container_freight(ship);
	my_putstr_color("green", "nb elem = ");
	my_put_nbr(ship->container->nb_elem);
	my_putstr("\n");
	return 0;
}
/*
  if (my_strcmp(tmp->item, "attackbonus") == 0)
  {
  ship->weapon->damage += 5;
  my_putstr_color("green", "[+] Bonus d'attaque  +5\n");
  del_freight_from_container(ship, tmp);
  }
  else if (my_strcmp(tmp->item, "evadebonus") == 0)
  {
  ship->navigation_tools->evade += 3;
  my_putstr_color("green", "[+] Bonus d'esquive +3\n");
  del_freight_from_container(ship, tmp);
  }
  else if (my_strcmp(tmp->item, "energy") == 0)
  {
  ship->ftl_drive->energy += 1;
  my_putstr_color("green", "[+] Bonus d'energie +1\n");
  del_freight_from_container(ship, tmp);
  }
  else
  return 0;
*/

void	aff_container_freight(t_ship *ship)
{
	t_freight	*tmp;

	tmp = ship->container->first;
	while (tmp != NULL)
	{
		my_putstr("La box contient ");
		my_putstr(tmp->item);
		my_putstr("\n");
		tmp = tmp->next;
	}
}
