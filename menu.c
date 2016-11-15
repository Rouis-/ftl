/*
** menu.c for  in /Users/Rouis/Desktop/ftl
** 
** Made by EL GOHARY Rouis
** Login   <elgoha_r@etna-alternance.net>
** 
** Started on  Fri Nov 11 14:17:51 2016 EL GOHARY Rouis
** Last update Sat Nov 12 12:00:02 2016 EL GOHARY Rouis
*/

#include "ftl.h"

int		menu()
{
	int	start;

	start = 0;
	my_putstr_color("clear", "\n———————————————————— Bienvenue sur my_ftl ————————————————————\n\n");
	if ((start = start_game()))
	{}
	my_putstr_color("clear", "\n———————————————————— Au revoir et a bientot! ————————————————————\n\n");
	return 0;
}

int		start_game()
{
	my_putstr_color("cyan", "Voulez-vous commencer une partie ? [oui/non]\n");
	if (get_menu_command() == 1)
	{
		init_game();
		return 1;
	}
	return 0;
}

int		get_menu_command()
{
	char	*cmd;

	my_putstr("[>] ");
	cmd = readline();
	if (my_strcmp(cmd, "oui") == 0)
	{
		my_putstr("Le jeu va commencer dans un instant!\n");
		return (1);
	}
	else if (my_strcmp(cmd, "non") == 0)
		return 0;
	free(cmd);
	return get_menu_command();
}

int		init_game()
{
	t_zone	*zone;
	t_ship	*ship;

	ship = create_ship();
	add_weapon_to_ship(ship);
	add_ftl_drive_to_ship(ship);
	add_navigation_tools_to_ship(ship);
	zone = create_zone();
	start_zone(ship, zone);
	free(ship);
	free(zone);
	return 0;
}
