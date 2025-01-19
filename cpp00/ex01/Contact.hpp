#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cstring>
#include <iomanip>

class contact
{
private:
    std::string first_Name;
    std::string last_Name;
    std::string nick_Name;
    std::string phone_Number;
    std::string darkest_Secret;
public:
    std::string get_first_Name(void);
    std::string get_last_Name(void);
    std::string get_nick_Name(void);
    std::string get_phone_Number(void);
    std::string get_darkest_Secret(void);
    void        set_first_Name(std::string input);
    void        set_last_Name(std::string input);
    void        set_nick_Name(std::string input);
    void        set_phone_Number(std::string input);
    void        set_darkest_Secret(std::string input);
    void        desplay_info(contact contact);
};

#endif