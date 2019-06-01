/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 11:01:21 by vkostenk          #+#    #+#             */
/*   Updated: 2019/01/26 13:33:37 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

# include <string>
# include <iostream>
#include <sstream>

#include "Entity.hpp"

class Bullet : public Entity
{
    public:
        Bullet(void);
        Bullet(const Bullet &src);
        ~Bullet(void);

        Bullet     &operator= (const Bullet &rhs);
    
        void enqueue(Bullet &src, Bullet &dst);
        void dequeue(Bullet &qu);

        Bullet *getFirst();
        Bullet *getNext();
        Bullet *getLast();
        void setFirst(Bullet &);
        void setNext(Bullet &);
        void setLast(Bullet &);
    private:
        Bullet *_first;
        Bullet *_last;
        Bullet *_next;
   
};

#endif
