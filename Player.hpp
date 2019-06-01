/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 11:01:12 by vkostenk          #+#    #+#             */
/*   Updated: 2019/01/27 18:42:09 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include <iostream>
#include <sstream>
#include "Window.hpp"
#include "Entity.hpp"
#include "bullet.hpp"


class Player : public Entity
{
    public:
        Player(void);
        Player(const Player &src);
        Player(std::string const & ship);
        ~Player(void);

        Player     &operator= (const Player &rhs);

        void shoot(void);
        void handleBullets(Window &win);
    
    private:
        Bullet *_shot;
};

#endif
