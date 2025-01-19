#include "Contact.hpp"

void    contact::set_first_Name(std::string input)
{
	first_Name = input;
}

void    contact::set_last_Name(std::string input)
{
	last_Name = input;
}

void    contact::set_nick_Name(std::string input)
{
	nick_Name = input;
}

void    contact::set_phone_Number(std::string input)
{
	phone_Number = input;
}

void    contact::set_darkest_Secret(std::string input)
{
	darkest_Secret = input;
}

std::string    contact::get_first_Name(void)
{
	return (first_Name);
}

std::string    contact::get_last_Name(void)
{
	return (last_Name);
}

std::string    contact::get_nick_Name(void)
{
	return (nick_Name);
}

std::string    contact::get_phone_Number(void)
{
	return (phone_Number);
}

std::string    contact::get_darkest_Secret(void)
{
	return (darkest_Secret);
}

void    contact::desplay_info(contact contact)
{
	std::cout << "first Name       : " << first_Name << std::endl;
	std::cout << "last Name        : " << last_Name << std::endl;
	std::cout << "nick Name        : " << nick_Name << std::endl;
	std::cout << "phone Number     : " << phone_Number << std::endl;
	std::cout << "darkest Secret   : " << darkest_Secret << std::endl;
}
