#include "Fixed.hpp"

const int Fixed::fixed_bits = 8;

Fixed::Fixed(void):value(0)
{
}

Fixed::Fixed(const int val)
{
    value = val << fixed_bits;
}

Fixed::Fixed(const float val)
{
    value = roundf(val * (1 << fixed_bits));
}

Fixed::Fixed(const Fixed &obj)
{
    *this = obj;
}

Fixed::~Fixed(void)
{
}

bool    Fixed::operator>(const Fixed &other) const
{
    return this->value > other.value;
}

bool    Fixed::operator<(const Fixed &other) const
{
    return this->value < other.value;
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return this->value >= other.value;
}

bool    Fixed::operator<=(const Fixed &other) const
{
    return this->value <= other.value;
}

bool    Fixed::operator==(const Fixed &other) const
{
    return this->value == other.value;
}

bool    Fixed::operator!=(const Fixed &other) const
{
    return this->value  != other.value;
}

Fixed   Fixed::operator+(const Fixed &other) const
{
    Fixed res;

    res.value = this->value + other.value;
    return res;
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    Fixed res;

    res.value = this->value - other.value;
    return res;
}

Fixed   Fixed::operator*(const Fixed &other) const
{
    Fixed res;

    res.value = (this->value * other.value) / (1 << fixed_bits);
    return res;
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    Fixed res;

    res.value = (this->value * (1 << fixed_bits)) / other.value;
    return res;
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
    if (this != &obj)
        this->value = obj.value;
    return (*this);
}

Fixed &Fixed::operator++()
{
    value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    value += 1;
    return temp;
}

Fixed &Fixed::operator--()
{
    value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    value -= 1;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed)
{
    out<<Fixed.toFloat();
    return out;
}
