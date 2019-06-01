/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 11:04:07 by vkostenk          #+#    #+#             */
/*   Updated: 2019/01/27 18:51:43 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "bullet.hpp"

Player::Player(void)
{
    _shot = new Bullet();
    return ;
}

Player::Player(const Player &src)
{
    *this = src;
    return ;
}

Player::Player(std::string const &ship)
{
    this->_ship = ship;
    _shot = new Bullet();
    return ;
}

Player::~Player(void)
{
    return ;
}

Player &Player::operator= (const Player &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return (*this);
}

void Player::shoot(void)
{
    Bullet *tmp = new Bullet();

    tmp->set_cur_x(cur_x+(_ship.length()/2));
    tmp->set_cur_y(cur_y - 1);
    _shot->enqueue(*tmp, *_shot->getFirst());
}

void Player::handleBullets(Window &win)
{
    if (_shot->getFirst())
    {
        Bullet *tmp = _shot->getFirst();

        while (tmp)
        {
            tmp->moveup();
            tmp->draw(win);
            tmp = tmp->getNext();
        }
        if (_shot->getFirst()->get_cur_y() < 2)
            _shot->dequeue(*_shot->getFirst());
    }
}

