/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:53:24 by vkostenk          #+#    #+#             */
/*   Updated: 2019/01/27 18:52:17 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void)
{
    return ;
}

Enemy::Enemy(const Enemy &src)
{
    *this = src;
    return ;
}

Enemy::Enemy(std::string ship)
{
    this->_ship = ship;
    return ;
}

Enemy::~Enemy(void)
{
    return ;
}

Enemy &Enemy::operator= (const Enemy &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return (*this);
}


void Enemy::handleMove(Window &win)
{
    if (this->cur_y & 0x1) {
        _hit = this->isHit(&win, cur_y, cur_x + 1);
        moveright(win.getX());
    }
    else
    {
       _hit = this->isHit(&win, cur_y, cur_x - 1);
        moveleft();
    }
    if ((this->cur_x + _ship.length() >= (win.getX() - _ship.length() - 2)) || (this->cur_x <= 1))
    {
        _hit = this->isHit(&win, cur_y + 1, cur_x);
        movedown(win.getY());
    }
    if (_hit)
        setShip("");
    this->draw(win);
}
