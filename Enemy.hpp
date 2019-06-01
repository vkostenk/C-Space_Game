/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 23:12:12 by vkostenk          #+#    #+#             */
/*   Updated: 2019/01/27 18:31:58 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>
# include <iostream>
#include <sstream>
#include "Window.hpp"
#include "Entity.hpp"

class Enemy : public Entity
{
    public:
        Enemy(void);
        Enemy(const Enemy &src);
        Enemy(std::string ship);
        ~Enemy(void);

        Enemy     &operator= (const Enemy &rhs);

        void handleMove(Window &win);

};

#endif
