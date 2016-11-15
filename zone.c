/*
** zone.c for  in /Users/Rouis/Desktop/ftl
** 
** Made by EL GOHARY Rouis
** Login   <elgoha_r@etna-alternance.net>
** 
** Started on  Fri Nov 11 15:03:42 2016 EL GOHARY Rouis
** Last update Sun Nov 13 21:50:42 2016 EL GOHARY Rouis
*/
#include "ftl.h"

static const t_zone_command command[] =
{
	{"?", zone_help},
	{"quit", zone_quit},
	{"attack", ship_attack},
	{"detect", ship_detect},
	{"jump", ship_jump},
	{"bonus", get_bonus},
	{NULL, NULL}
};

t_zone	*create_zone()
{
	t_zone	*zone;

	zone = malloc(sizeof(t_zone));
	if (zone == NULL)
	{
		my_putstr_color("red", "[SYSTEM FAILURE] [!] Impossible de charger la carte!\n");
		return NULL;
	}
	zone->sector = 0;
	zone->container_exist = 0;
	zone->enemy_exist = 0;
	zone->enemy = create_enemy();
	return zone;
}

int		start_zone(t_ship *ship, t_zone *zone)
{
	if (ship->navigation_tools->sector == 10)
	{
		my_putstr_color("red", "\n———————————————————————— Vous avez gagne ————————————————————————\n\n");
		zone_quit(ship, zone);
		return 0;
	}

	my_putstr_color("clear", "\n—————————————————————————————— ZONE ");
	my_put_nbr(ship->navigation_tools->sector);
	my_putstr(" ——————————————————————————————\n\n");
	zone->container_exist = 1;
	if (detect_enemy())
	{
		ship->enemy = new_enemy(zone);
		battle_info(ship, ship->enemy);
	}
	while (ship->navigation_tools->sector < 10)
	{
		my_putstr("\nQuelle commande souhaitez-vous executer ? [aide -> '?']\n");
		if (zone_loop(ship, zone) == 0)
		{
			my_putstr_color("red", "\n———————————————————————— Vous avez perdu ————————————————————————\n\n");
			return 0;
		}
		else
			start_zone(ship, zone);
	}
	return 0;
}

int		zone_loop(t_ship *ship, t_zone *zone)
{
	int		status;

	status = zone_command(ship, zone);
	enemy_attack(ship, zone);
	if (status == 1)
		start_zone(ship, zone);
	else if (status == 0)
		zone_loop(ship, zone);
	return 0;
}

int		zone_command(t_ship *ship, t_zone *zone)
{
	char	*cmd;
	int		i;

	i = 0;
	my_putstr("[>] ");
	cmd = readline();
	if (cmd == NULL)
	{
		my_putstr_color("red", "[SYSTEM FAILURE] : le lecteur de commande est bloque\n");
		return 0;
	}
	else
	{
		while (command[i].command_name != NULL)
		{
			if (my_strcmp(cmd, command[i].command_name) == 0)
				return command[i].command_func(ship, zone);
			++i;
		}
		my_putstr_color("red", "[SYSTEM FAILURE] : commande inconnue\n");
	}
	return 0;
}

/* TO DELETE !!!!!!!!!!!!! */

int		zone_help(t_ship *ship, t_zone *zone)
{
	zone = NULL;
	ship = NULL;
	my_putstr("aide\n");
	return 0;
}

int		zone_quit(t_ship *ship, t_zone *zone)
{
	zone = NULL;
	ship = NULL;
	return -1;
}
