/*
** enemy.c for  in /Users/Rouis/Desktop/ftl
** 
** Made by EL GOHARY Rouis
** Login   <elgoha_r@etna-alternance.net>
** 
** Started on  Fri Nov 11 18:44:17 2016 EL GOHARY Rouis
** Last update Sat Nov 12 12:50:26 2016 EL GOHARY Rouis
*/
#include "ftl.h"

t_enemy	*create_enemy()
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (enemy == NULL) {
		my_putstr_color("red", "[SYSTEM FAILURE] [!] Enemy problem!\n");
		return NULL;
	}
	enemy->damage = 0;
	enemy->health = 0;
	return enemy;
}

int		detect_enemy()
{
	int	n;

	n = random_int();
	if (n >= 0 && n < 30)
	{
		my_putstr_color("red", "[!] Ennemi detecte attention il peut attaquer!\n");
		return 1;
	}
	my_putstr_color("green", "[+] Pas d'ennemi detecte dans cette zone!\n"); 
	return 0;
}

t_enemy	*new_enemy(t_zone *zone)
{
	t_enemy *enemy;

	enemy = create_enemy();
	if (zone->enemy->damage == 0 || zone->enemy->damage == 0)
	{
		enemy->damage = 10;
		enemy->health = 20;
	}
	else
	{
		enemy->damage = zone->enemy->damage + (zone->enemy->damage / 2);
		enemy->health = zone->enemy->health + (zone->enemy->health / 2);
	}
	zone->enemy->damage = enemy->damage;
	zone->enemy->health = enemy->health;
	++(zone->enemy_exist);
	return enemy;
}

int		battle_info(t_ship *ship, t_enemy *enemy)
{
	if (enemy != NULL)
	{
		my_putstr_color("cyan", "\nVotre vaisseau:\t\t\tLe vaisseau ennemi:\n");
		my_putstr_color("green", "Votre vie:\t");
		my_put_nbr(ship->hull);
		my_putstr_color("red", "\t\tVie de l'ennemi:\t");
		my_put_nbr(enemy->health);
		my_putstr("\n");
		my_putstr_color("green", "Votre attaque:\t");
		my_put_nbr(ship->weapon->damage);
		my_putstr_color("red", "\t\tAttaque de l'ennemi:\t");
		my_put_nbr(enemy->damage);
		my_putstr("\n\n");
		return 1;
	}
	return 0;
}

int		enemy_attack(t_ship *ship, t_zone *zone)
{
	int	n;
	int	m;
	int	k;

	n = random_int();
	m = random_int();
	k = random_int();
	if (!zone->enemy_exist || ship->enemy->health <= 0)
		return 0;
	else if (n >= 0 && n < ship->navigation_tools->evade)
	{
		if (ship->hull >= 0)
		{
			ship->hull -= ship->enemy->damage;
			if (ship->hull < 0)
				ship->hull = 0;
			battle_info(ship, ship->enemy);
			my_putstr_color("red", "[ENEMY] Le vaisseau ennemi vous a attaque\n");
			if (ship->hull <= 0)
			{
				my_putstr_color("red", "[ENEMY] Le vaisseau ennemi a reussi a vous detruire!\n");
				return -1;
			}
			if (m >= 0 && m < 20)
			{
				if (k >= 0 && k < 33)
					my_putstr_color("magenta", "[WEAPON] L'attaque du vaisseau ennemi a touche vos armes, elles sont tombees en panne...\n");
				else if (k >= 33 && k < 65)
					my_putstr_color("magenta", "[REACTOR] L'attaque du vaisseau ennemi a touche vos reacteurs, ils sont tombes en panne...\n");
				else if (k >= 65 && k < 100)
					my_putstr_color("magenta", "[NAV TOOLS] L'attaque du vaisseau ennemi a touche vos outils de navigation, ils sont tombes en panne...\n");
			}
			return 0;
		}
	}
	my_putstr_color("green", "[ENEMY] Le vaisseau ennemi n'as pas reussi a vous toucher!\n");
	return 0;
}
