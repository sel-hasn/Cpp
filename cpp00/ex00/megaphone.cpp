#include <iostream>

int main(int arc, char **arv)
{
    std::string str;
    for (int i = 1; i < arc; i++)
    {
        str = arv[i];
        for (int j = 0; j < (int)str.length(); j++)
        {
            str.at(j) = toupper(str.at(j));
        }
        std::cout << str;
    }
    if (arc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
}