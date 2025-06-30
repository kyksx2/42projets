/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:56:08 by marvin            #+#    #+#             */
/*   Updated: 2025/06/30 14:56:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

class Point
{
public:
    Point();
    Point(const float x, const float y);*
    Point(Point const &src)
    ~Point();

    Point& operator=(Point const& src);

private:
    Fixed const x;
    Fixed const y;
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif