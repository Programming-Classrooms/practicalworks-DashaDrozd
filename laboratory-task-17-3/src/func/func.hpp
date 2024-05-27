#ifndef FISH_HPP
#define FISH_HPP

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <fstream>

void writeFishermanData(std::ofstream&, const std::set<std::string>&, const std::string&);
void writeFishData(std::ostream&, const std::set<std::string>&);

#endif // FISH_HPP
