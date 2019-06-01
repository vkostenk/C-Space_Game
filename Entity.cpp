/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <amontano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 01:33:59 by amontano          #+#    #+#             */
/*   Updated: 2019/01/27 18:52:04 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"
#include "bullet.hpp"

Entity::Entity(void) { _hit = false; }

Entity::Entity(const Entity &src) { *this = src; }

Entity::Entity(std::string ship) { 
	_hit = false;
	this->_ship = ship; 
}

Entity &Entity::operator=(const Entity &rhs)
{
	if (this != &rhs)
	{
		this->_ship = rhs._ship;
		this->cur_x = rhs.cur_x;
		this->cur_y = rhs.cur_y;
	}
	return (*this);
}

void Entity::setShip(std::string ship) { this->_ship = ship; }

void Entity::set_cur_x(int x) { this->cur_x = x; }

void Entity::set_cur_y(int y) { this->cur_y = y; }

std::string Entity::getShip(void) const { return (this->_ship); }

int Entity::get_cur_x(void) const { return this->cur_x; }

int Entity::get_cur_y(void) const { return this->cur_y; }

// move

void Entity::moveleft(void)
{
	if (this->cur_x > 1)
		this->cur_x--;
}

void Entity::moveright(int max)
{
	if (this->cur_x + _ship.length() <= (max - _ship.length() + 1))
		this->cur_x++;
}

void Entity::moveup(void)
{
	if (this->cur_y > 1)
		this->cur_y--;
}

void Entity::movedown(int max)
{
	if (this->cur_y <= max + 1)
		this->cur_y++;
}
//atack

void Entity::draw(Window &w)
{
	wmove(w.get_win(), cur_y, cur_x);
	for (size_t i = 0; i < _ship.length(); i++)
		wprintw(w.get_win(), "%c", _ship[i]);
}

//for each char of _ship check collision
//	scanf position and if it returns not empty return FALSE
bool Entity::isHit(Window *win, int y, int x)
{
	for (size_t i = 0; i < _ship.length(); i++)
	{
		if ((mvwinch(win->get_win(), y, x + i) & '|') == '|')
			return (true);
	}
	return (false);
}
