/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 11:11:29 by vkostenk          #+#    #+#             */
/*   Updated: 2019/05/31 20:21:21 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include <string>
#include "Player.hpp"
#include "Enemy.hpp"
#include "bullet.hpp"
#include <time.h>
#include <unistd.h>


# define DELAY 30000
# define N_ENEMY 20
int main()
{

	Window *win = new Window();
	wborder(win->get_win(), '*', '*', '*', '*', '*', '*', '*', '*');
	wmove(win->get_win(), win->getY() - 10, win->getX() / 2);
	Player *pl1 = new Player("-=8*8=-");
	pl1->set_cur_x(win->getX() / 2);
	pl1->set_cur_y(win->getY() - 3);
	Enemy *enemy1[N_ENEMY];
	int line = 0;
	size_t space = 2;
	for (int i = 0; i < N_ENEMY; i++)
	{

		enemy1[i] = new Enemy("\\\\~o//");
		enemy1[i]->set_cur_x(space);
		space += enemy1[i]->getShip().length() + 2;
		if (!(space < (size_t)win->getX() - 2))
			space = 2;
		enemy1[i]->set_cur_x(space);
		if (space == 2)
			line++;
		enemy1[i]->set_cur_y(line);
	}

	keypad(win->get_win(), true);
	//int c = wgetch(win->get_win());

	clock_t	t = clock();
	double ms;
	bool victor = false;
	bool fail = false;
	while (victor == false && fail == false)
	{
		//clock stuff

		wclear(win->get_win());
		t = clock();
		int c = wgetch(win->get_win());
		//bullets handled first
		pl1->handleBullets(*win);
		//then player
		if (c == KEY_LEFT)
			pl1->moveleft();
		else if (c == KEY_RIGHT)
			pl1->moveright(win->getX());
		else if (c == KEY_UP)
			pl1->shoot();
		else if (c == 'q')
			break ;
		//then enemy
		for (int i = 0; i < N_ENEMY; i++)
		{
			enemy1[i]->handleMove(*win);
			enemy1[i]->draw(*win);
		}
		pl1->draw(*win);
		wborder(win->get_win(), '*', '*', '*', '*', '*', '*', '*', '*');
		wrefresh(win->get_win());
		t = clock() - t;
		ms = t / CLOCKS_PER_SEC;
		victor = true;
		fail = pl1->isHit(win, pl1->get_cur_y(), pl1->get_cur_x());
		for (int i = 0; i < N_ENEMY; i++)
		{
			if (enemy1[i]->getShip() != "")
				victor = false;
			if (enemy1[i]->get_cur_y() > win->getY() - 2)
				fail = true;
		}
		usleep(DELAY - ms);
	}
	endwin();
	delete win;
	delete pl1;
	for (int i = 0; i < N_ENEMY; i++)
	{
		delete enemy1[i];
	}
	if (victor)
		std::cout << "YOU WIN!" << std::endl;
	if (fail)
		std::cout << "YOU LOSE!" << std::endl;
	return 0;
}
