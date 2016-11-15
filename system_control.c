/*
** system_control.c for  in /Users/Rouis/Desktop/ftl
** 
** Made by EL GOHARY Rouis
** Login   <elgoha_r@etna-alternance.net>
** 
** Started on  Thu Nov 10 13:35:30 2016 EL GOHARY Rouis
** Last update Sat Nov 12 13:02:34 2016 EL GOHARY Rouis
*/

#include "ftl.h"

void	ftl_drive_system_check(t_ship *ship)
{
	my_putstr("verification du reacteur en cours...\n");
	if (ship != NULL) {
		if (my_strcmp(ship->ftl_drive->system_state, "online") == 0)
			my_putstr_color("green", "reacteur OK!\n");
		else
			my_putstr_color("red", "reacteur hors service!\n");
	}
}

void	navigation_tools_system_check(t_ship *ship)
{
	my_putstr("verification du systeme de navigation en cours...\n");
	if (ship != NULL) {
		if (my_strcmp(ship->navigation_tools->system_state, "online") == 0)
			my_putstr_color("green", "systeme de navigation OK!\n");
		else
			my_putstr_color("red", "systeme de navigation hors service!\n");
	}
}

void	weapon_system_check(t_ship *ship)
{
	my_putstr("verification du systeme d'armement en cours...\n");
	if (ship != NULL) {
		if (my_strcmp(ship->weapon->system_state, "online") == 0)
			my_putstr_color("green", "systeme d'armement OK!\n");
		else
			my_putstr_color("red", "systeme d'armement hors service!\n");
	}
}

void	system_control(t_ship *ship)
{
	my_putstr_color("blue", "[SYSTEM CHECK] System check start\n");
	my_wait(6);
	ftl_drive_system_check(ship);
	my_wait(6);
	navigation_tools_system_check(ship);	
	my_wait(6);
	weapon_system_check(ship);
	my_wait(6);
	my_putstr_color("blue", "[SYSTEM CHECK] System check finished\n");
}
