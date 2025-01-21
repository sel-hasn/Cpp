#include <iostream>
#include <fstream>
#include <string>

void    replace(std::string &filename, std::string &s1, std::string &s2)
{
    std::ifstream in_file(filename.c_str());
    if (!in_file.is_open()){
        std::cerr<<"Error :in_file cannot open"<<std::endl;
        return ;
    }
    std::ofstream out_file((filename + ".replace").c_str());
    if (!out_file.is_open()){
        std::cerr<<"Error :out_file cannot open"<<std::endl;
        in_file.close();
        return ;
    }
    std::string line;
    std::getline(in_file, line);
    if (in_file.eof()){
        std::cerr<<"Error :in_file cannot be empty"<<std::endl;
        return ;
    }
    size_t pos;
    do
    {
        pos = 0;
        // while ((pos = line.find(s1, pos)) != -1)
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        out_file<<line<<std::endl;
    } while (std::getline(in_file, line));
    in_file.close();
    out_file.close();
}

int main(int arc, char **arv)
{
    if (arc != 4){
        std::cerr<<"Error : wrong number of argement"<<std::endl;
        return 1;
    }
    std::string filename = arv[1];
    std::string s1 = arv[2];
    std::string s2 = arv[3];
    if (s1.empty()){
        std::cerr<<"Error : s1 cannot be empty"<<std::endl;
        return 1;
    }
    replace(filename, s1, s2);
}