/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 22:34:20 by amontano          #+#    #+#             */
/*   Updated: 2019/01/26 22:34:22 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <string>
# include <iostream>
#include <sstream>
#include <curses.h>

class Window
{
    public:
        Window(void);
        ~Window(void) {};

        int getX();
        int getY();
        WINDOW *get_win();
    private:
        int _x;
        int _y;
        WINDOW *_w;
};

#endif
