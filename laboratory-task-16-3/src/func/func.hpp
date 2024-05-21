#ifndef FUNC_HPP
#define FUNC_HPP
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include <sstream>

void checkFile(std::ifstream&);
bool comp(std::string &, std::string &);
void print(std::vector<std::string>&);
void printByFirstLetter(std::vector<std::string>&);
void deleteByFirstLetter(std::vector<std::string>&);

#endif