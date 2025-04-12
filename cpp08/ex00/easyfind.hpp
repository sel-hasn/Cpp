#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int ToFind)
{
    typename T::iterator i = std::find(container.begin(), container.end(), ToFind);
    if (i == container.end()){
        throw std::runtime_error("Value not found");
    }
    return i;
}

#endif