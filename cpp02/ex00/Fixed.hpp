#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
    int value;
    static const int fixed_bits;
public:
    Fixed(void);
    Fixed(const Fixed &obj);
    ~Fixed(void);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    Fixed   &operator=(const Fixed &obj);
};

#endif