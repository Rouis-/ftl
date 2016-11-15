/*
** ship_command.c for  in /Users/Rouis/Desktop/ftl
** 
** Made by EL GOHARY Rouis
** Login   <elgoha_r@etna-alternance.net>
** 
** Started on  Fri Nov 11 22:06:23 2016 EL GOHARY Rouis
** Last update Sun Nov 13 22:39:39 2016 EL GOHARY Rouis
*/
#include "ftl.h"

int		ship_attack(t_ship *ship, t_zone *zone)
{
	if (my_strcmp(ship->weapon->system_state, "online") != 0)
	{
		my_putstr_color("red", "[WEAPON] Armes en panne impossible d'attaquer le vaisseau ennemi!\n");
		return 0;
	}
	else if (!zone->enemy_exist || ship->enemy->health <= 0)
	{
		my_putstr_color("red", "[ENEMY] Pas de vaisseau ennemi detecte dans cette zone!\n");
		return 0;
	}
	else if (ship->enemy->health >= 0)
	{
		ship->enemy->health -= ship->weapon->damage;
		if (ship->enemy->health < 0)
			ship->enemy->health = 0;
		battle_info(ship, ship->enemy);
		if (ship->enemy->health <= 0)
		{
			ship->enemy->health = 0;
			zone->enemy_exist = 0;
			my_putstr_color("green", "[ENEMY] Vaisseau ennemi detruit super!\n");
			bad_luck(ship);
		}
		return 0;
	}
	return 0;
}

int		ship_detect(t_ship *ship, t_zone *zone)
{
	if (my_strcmp(ship->navigation_tools->system_state, "online") != 0)
	{
		my_putstr_color("red", "[NAV TOOLS] Outils de navigation en panne impossible d'effectuer une detection!\n");
		return 0;
	}
	else if (!zone->container_exist)
	{
		my_putstr_color("red", "[NAV TOOLS] Pas de cargaison detectee dans cette zone!\n");
		return 0;
	}
	else if (zone->container_exist)
	{
		if (ship->container != NULL)
		{
			my_putstr_color("red", "[NAV TOOLS] Pas d'espace disponible sur le vaisseau pour de nouvelles cargaisons\n");
			return 0;
		}
	}
	zone->container_exist = 1;
	charge_container(ship);
	my_putstr_color("green", "[NAV TOOLS] Cargaisons recuperees!\n");
	return 0;
}

int		ship_jump(t_ship *ship, t_zone *zone)
{
	if (ship->ftl_drive->energy <= 0)
	{
		my_putstr_color("red", "[REACTOR] Plus assez d'energie pour passer dans la prochaine zone!\n");
		return -1;
	}
	else if (zone->enemy_exist)
	{
		my_putstr_color("red", "[ENEMY] Impossible de fuir il faut tuer l'ennemi!\n");
		return 0;
	}
	else if (my_strcmp(ship->ftl_drive->system_state, "online") != 0)
	{
		my_putstr_color("red", "[REACTOR] Reacteurs en panne impossible de passer a la prochaine zone!\n");
		return 0;
	}
	++(zone->sector);
	++(ship->navigation_tools->sector);
	--(ship->ftl_drive->energy);
	zone->container_exist = 1;
	return 1;
}

int		bad_luck(t_ship *ship)
{
	int	n;

	n = random_int();
	if (n >= 0 && n < 50)
	{
		my_putstr_color("magenta", "[REACTOR] Pas de chance, suite au combat vous avez perdu 1 point d'energie\n");
		--(ship->ftl_drive->energy);
	}
	return 0;
}
