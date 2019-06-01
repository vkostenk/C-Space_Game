/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 22:34:26 by amontano          #+#    #+#             */
/*   Updated: 2019/01/26 22:34:26 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"
#include <curses.h>

Window::Window(void)
{
    initscr();
    cbreak();
    curs_set(0);
    noecho();
    getmaxyx(stdscr, _y, _x);
    _w = newwin(_y, _x, 0, 0);
    wtimeout(_w, 0);
}

int Window::getX()          { return _x; }
int Window::getY()          { return _y; }
WINDOW *Window::get_win()   { return _w; }
