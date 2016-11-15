/*
** air_shed.c for  in /Users/Rouis/Desktop/ftl
** 
** Made by EL GOHARY Rouis
** Login   <elgoha_r@etna-alternance.net>
** 
** Started on  Thu Nov 10 13:36:36 2016 EL GOHARY Rouis
** Last update Sat Nov 12 12:49:06 2016 EL GOHARY Rouis
*/
#include "ftl.h"

t_ship	*create_ship()
{
	t_ship		*ship;

	my_putstr_color("blue", "[SHIP] Construction du vaisseau en cours...\n");
	my_wait(1);
	ship = malloc(sizeof(t_ship));
	if (ship == NULL) {
		my_putstr_color("red", "[SHIP] Construction du vaisseau impossible : manque de materiaux\n");
		return NULL;
	}
	ship->hull = 50;
	ship->weapon = NULL;
	ship->ftl_drive = NULL;
	ship->navigation_tools = NULL;
	ship->container = NULL;
	ship->enemy = NULL;
	my_putstr_color("green", "[SHIP] Construction du vaisseau terminee avec succes!\n");
	return ship;
}

int		add_weapon_to_ship(t_ship *ship)
{
	t_weapon	*weapon;

	my_putstr_color("blue", "[WEAPON] Ajout des armes en cours...\n");
	my_wait(1);
	weapon = malloc(sizeof(t_weapon));
	if (weapon == NULL) {
		my_putstr_color("red", "[WEAPON] Ajout des armes echoue : vaisseau detruit lors de l'operation\n");
		return 0;
	}
	weapon->damage = 10;
	weapon->system_state = my_strdup("online");
	ship->weapon = weapon;
	my_putstr_color("green", "[WEAPON] Ajout des armes effectue avec succes!\n");
	return 1;
}

int		add_ftl_drive_to_ship(t_ship *ship)
{
	t_ftl_drive	*ftl_drive;

	my_putstr_color("blue", "[REACTOR] Ajout des reacteurs en cours...\n");
	my_wait(1);
	ftl_drive = malloc(sizeof(t_ftl_drive));
	if (ftl_drive == NULL) {
		my_putstr_color("red", "[REACTOR] Ajout des reacteurs echoue : vaisseau detruit lors de l'operation\n");
		return 0;
	}
	ftl_drive->energy = 10;
	ftl_drive->system_state = my_strdup("online");
	ship->ftl_drive = ftl_drive;
	my_putstr_color("green", "[REACTOR] Ajout des reacteurs effectue avec succes!\n");
	return 1;
}

int		add_navigation_tools_to_ship(t_ship *ship)
{
	t_navigation_tools	*navigation_tools;

	my_putstr_color("blue", "[NAV TOOLS] Ajout des outils de navigation en cours...\n");
	my_wait(1);
	navigation_tools = malloc(sizeof(t_navigation_tools));
	if (navigation_tools == NULL) {
		my_putstr_color("red", "[NAV TOOLS] Ajout des outils de navigation echoue : vaisseau detruit lors de l'operation\n");
		return 0;
	}
	navigation_tools->sector = 0;
	navigation_tools->evade = 25;
	navigation_tools->system_state = my_strdup("online");
	ship->navigation_tools = navigation_tools;
	my_putstr_color("green", "[NAV TOOLS] Ajout des outils de navigation effectue avec succes!\n");
	return 1;
}
