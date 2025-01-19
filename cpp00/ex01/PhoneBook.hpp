#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    contact my_contact[8];
    int     contact_nbr = 0;
public:
    std::string get_input(std::string);
    void        add(void);
    void        search(void);
    void        display_all(contact *my_contact);
};

#endif