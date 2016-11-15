/*
** system_repair.c for  in /Users/Rouis/Desktop/ftl
** 
** Made by EL GOHARY Rouis
** Login   <elgoha_r@etna-alternance.net>
** 
** Started on  Thu Nov 10 13:37:05 2016 EL GOHARY Rouis
** Last update Fri Nov 11 15:37:28 2016 EL GOHARY Rouis
*/

#include "ftl.h"

static const t_repair_command repair_command[] =
{
	{"ftl_drive", ftl_drive_system_repair},
	{"navigation_tools", navigation_tools_system_repair},
	{"weapon", weapon_system_repair},
	{NULL, NULL}
};

int		ftl_drive_system_repair(t_ship *ship)
{
	my_putstr("reparation du reacteur en cours...\n");
	if (ship->ftl_drive->system_state != NULL) {
		free(ship->ftl_drive->system_state);
		if ((ship->ftl_drive->system_state = my_strdup("online")) != NULL) {
			my_putstr_color("green", "reparation termine! systeme reacteur OK!\n");
			return 1;
		}
	}
	my_putstr_color("red", "les reparations du reacteur ont echoue\n");
	return 0;
}

int		navigation_tools_system_repair(t_ship *ship)
{
	my_putstr("reparation du systeme de navigation en cours...\n");
	if (ship->navigation_tools->system_state != NULL) {
		free(ship->navigation_tools->system_state);
		if ((ship->navigation_tools->system_state = my_strdup("online")) != NULL) {
			my_putstr_color("green", "reparation termine! systeme de navigation OK!\n");
			return 1;
		}
	}
	my_putstr_color("red", "les reparations des outils de navigations ont echoue\n");
	return 0;
}

int		weapon_system_repair(t_ship *ship)
{
	my_putstr("reparation du systeme d'armement en cours...\n");
	if (ship->weapon->system_state != NULL) {
		free(ship->weapon->system_state);
		if ((ship->weapon->system_state = my_strdup("online")) != NULL) {
			my_putstr_color("green", "reparation termine! systeme d'armement OK!\n");
			return 1;
		}
	}
	my_putstr_color("red", "les reparations du systeme d'armement ont echoue\n");
	return 0;
}

int		system_repair(t_ship *ship)
{
	char		*command;
	int	i;

	my_putstr("repair_system~>");
	command = readline();
	if (command == NULL) {
		my_putstr_color("red", "[SYSTEM FAILURE] : le lecteur de commande est bloque\n");
		return 0;
	} else {
		i = 0;
		while (repair_command[i].command_name != NULL) {
			if (my_strcmp(command, repair_command[i].command_name) == 0) {
				repair_command[i].command_func(ship);
				return 1;
			}
			++i;
		}
		my_putstr_color("red", "[SYSTEM FAILURE] : commande inconnue\n");
	}
	return 0;
}
