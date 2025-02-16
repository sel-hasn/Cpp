#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value;
    static const int fixed_bits;
public:
    Fixed(void);
    Fixed(const int);
    Fixed(const float val);
    Fixed(const Fixed &obj);
    ~Fixed(void);

    float toFloat( void ) const;
    int toInt(void) const;

    bool    operator>(const Fixed &other) const;
    bool    operator<(const Fixed &other) const;
    bool    operator>=(const Fixed &other) const;
    bool    operator<=(const Fixed &other) const;
    bool    operator==(const Fixed &other) const;
    bool    operator!=(const Fixed &other) const;

    Fixed   operator+(const Fixed &obj) const;
    Fixed   operator-(const Fixed &obj) const;
    Fixed   operator*(const Fixed &obj) const;
    Fixed   operator/(const Fixed &obj) const;

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    Fixed   &operator=(const Fixed &obj);

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed);

#endif