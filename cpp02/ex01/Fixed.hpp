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
    float toFloat( void ) const;
    int toInt(void) const;
    ~Fixed(void);
    Fixed   &operator=(const Fixed &obj);
};

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed);

#endif