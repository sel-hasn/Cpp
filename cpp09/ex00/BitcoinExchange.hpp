#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <climits> 
#include <cerrno>

bool isValidRate(std::string rate);
bool isValidDate(std::string date);
std::map<std::string, double> loadDatabase();
void parseInput(std::string &line, std::map<std::string, double> &map);
void Processinginput(std::ifstream &input, std::map<std::string, double> &map);

#endif