/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:24:18 by vkostenk          #+#    #+#             */
/*   Updated: 2019/01/27 18:54:15 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bullet.hpp"

Bullet::Bullet(void) : Entity("|")
{
    _first = nullptr;
    _last = nullptr;
    _next  = nullptr;
    return ;
}

Bullet::Bullet(const Bullet &src)
{
    *this = src;
    return ;
}

Bullet::~Bullet(void)
{
    return ;
}

Bullet &Bullet::operator= (const Bullet &rhs)
{
  if (this != &rhs) {
    *this = rhs;
  }
    return (*this);
}

Bullet *Bullet::getFirst() { return _first; };
Bullet *Bullet::getNext() { return _next; }
Bullet *Bullet::getLast() { return _last; };

void Bullet::setFirst(Bullet &f)    { _first = &f; }
void Bullet::setNext(Bullet &n)     { _next = &n; }
void Bullet::setLast(Bullet &l)     { _last = &l; }

void Bullet::enqueue(Bullet &src, Bullet &dst)
{
    if (&dst == nullptr)
    {
        this->_first = &src;
        this->_last = &src;
        this->_next = nullptr;
    }
    else
    {
        src._first = this->_first;
        this->_last->_next = &src;
        this->_last = &src;
        src._next = nullptr;
    }

}
void Bullet::dequeue(Bullet &qu)
{

    if (this->_first != this->_last)
    {
        _first  = _first->_next;
        qu._first = _first;
    }
    else
    {
        _first = nullptr;
    }
    delete &qu;
}
