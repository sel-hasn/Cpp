#include "Point.hpp"

Point::Point():x(0), y(0)
{
}

Point::~Point()
{
}

Point::Point(const float _x, const float _y):x(_x), y(_y)
{
}

Point::Point(const Point &other)
{
    std::cout<<"hello"<<std::endl;
    *this = other;
}

Fixed Point::get_x() const
{
    return x;
}

Fixed Point::get_y() const
{
    return y;
}

Point   &Point::operator=(const Point &obj)
{
    if (this != &obj)
    {
        this->x = obj.x;
        this->y = obj.y;
    }
    return (*this);
}

bool    Point::operator!=(const Point &other) const
{
    return this->x != other.x && this->y != other.y;
}

bool    Point::operator==(const Point &other) const
{
    return this->x == other.x && this->y == other.y;
}
