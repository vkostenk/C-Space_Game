/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 01:32:23 by amontano          #+#    #+#             */
/*   Updated: 2019/01/27 01:32:25 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <iostream>
#include <sstream>
#include "Window.hpp"

class Entity
{
  public:
	Entity(void);
	Entity(const Entity &src);
	Entity(std::string ship);
	~Entity(void){};

	Entity &operator=(const Entity &rhs);

	void setShip(std::string ship);
	void set_cur_x(int x);
	void set_cur_y(int y);

	void moveleft(void);
	void moveright(int max);
	void moveup(void);
	void movedown(int max);
	std::string getShip(void) const;

	int get_cur_x(void) const;
	int get_cur_y(void) const;
	void draw(Window &w);

	bool isHit(Window *win, int y, int x);

  protected:
	std::string _ship;
	int cur_y;
	int cur_x;
	bool _hit;
};

#endif
