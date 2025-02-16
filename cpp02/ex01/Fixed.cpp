#include "Fixed.hpp"

const int Fixed::fixed_bits = 8;

Fixed::Fixed(void):value(0)
{
    std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int val)
{
    std::cout<<"Int constructor called"<<std::endl;
    value = val << fixed_bits;
}

Fixed::Fixed(const float val)
{
    std::cout<<"Float constructor called"<<std::endl;
    value = roundf(val * (1 << fixed_bits));
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = obj;
}

Fixed::~Fixed(void)
{
    std::cout<<"Destructor called"<<std::endl;
}

float Fixed::toFloat( void ) const
{
    return ((float) value / (1 << fixed_bits));
}

int Fixed::toInt(void) const
{
    return (value >> fixed_bits);
}

Fixed   &Fixed::operator=(const Fixed &obj)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (this != &obj)
        this->value = obj.value;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed)
{
    out<<Fixed.toFloat();
    return out;
}
