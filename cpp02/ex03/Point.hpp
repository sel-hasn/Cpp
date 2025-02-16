#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point{
private:
    Fixed x;
    Fixed y;
public:
    Point ();
    ~Point ();
    Point (const Point &other);
    Point (const float _x, const float _y);

    Fixed get_x() const;
    Fixed get_y() const;

    Point   &operator=(const Point &obj);
    bool    operator!=(const Point &other) const;
    bool    operator==(const Point &other) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif