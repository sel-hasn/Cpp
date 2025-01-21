#include "PhoneBook.hpp"

int non_print(std::string mes)
{
    for (int i = 0; i < mes.length(); i++)
        if (mes[i] < 32 || mes[i] > 126)
            return(0);
    return(1);
}

std::string PhoneBook::get_input(std::string missage)
{
    std::string input;

    while (input.empty())
    {
        std::cout << missage;
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit (1);
        else if (!non_print(input))
            std::cout<<"Wrong input, try again"<<std::endl;
    }
    return (input);
}

void    PhoneBook::add(void)
{
    contact tmp;

    if (contact_nbr <= 8)
        contact_nbr++;
    for (int i = 7; i > 0; i--)
        my_contact[i] = my_contact[i - 1];
    my_contact[0].set_first_Name(get_input("enter first Name : "));
    my_contact[0].set_last_Name(get_input("enter last Name : "));
    my_contact[0].set_nick_Name(get_input("enter nick Name : "));
    my_contact[0].set_phone_Number(get_input("enter phone Number : "));
    my_contact[0].set_darkest_Secret(get_input("enter darkest Secret : "));
    std::cout << "~~contact has created succesfully~~" << std::endl;
}

void    PhoneBook::search(void)
{
    std::string indx;

    if (contact_nbr == 0) {
        std::cout<<"There is no contact, try to add one"<<std::endl;
        return ;
    }
    display_all(my_contact);
    std::cout<<"enter the index of contact that you looking for : ";
    std::getline(std::cin, indx);
    if (std::cin.eof())
        exit (1);
    int i = atoi(indx.c_str());
    if (i == 0 || i > 8 || i > contact_nbr)
    {
        std::cout<<"Wronge index, try again"<<std::endl;
        return ;
    }
    std::cout<<"contact you looking for is :"<<std::endl;
    my_contact[i - 1].desplay_info(my_contact[i - 1]);
}

std::string fix_length(std::string str)
{
    if (str.length() > 10)
    {
        return (str.substr(0, 9) + '.');
    }
    return (str);
}

void    PhoneBook::display_all(contact *my_contact)
{
    std::cout<<std::setw(10)<<"index"<<" | "<<std::setw(10)<<"first name"<<" | ";
    std::cout<<std::setw(10)<<"lastname"<<" | "<<std::setw(10)<<"nickname"<<std::endl;
    for (int i = 0; i < contact_nbr; i++)
    {
        std::cout<<std::setw(10)<<i+1<<" | ";
        std::cout<<std::setw(10)<<fix_length(my_contact[i].get_first_Name())<<" | ";
        std::cout<<std::setw(10)<<fix_length(my_contact[i].get_last_Name())<<" | ";
        std::cout<<std::setw(10)<<fix_length(my_contact[i].get_nick_Name())<<std::endl;
    }
}

int main()
{
    PhoneBook my_phonebook;
    std::string input;

    std::cout<<"        ~~~Welcome To My Awesome PhoneBook~~~"<<std::endl;
    while (true)
    {
        std::cout<<"Enter a Command frome this (ADD, SEARCH, EXIT) : ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit (1);
        if (input == "ADD")
            my_phonebook.add();
        else if (input == "SEARCH")
            my_phonebook.search();
        else if (input == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break ;
        }
        else
            std::cout<<"Wronge input, try again"<<std::endl;
    }
    return (0);
}
