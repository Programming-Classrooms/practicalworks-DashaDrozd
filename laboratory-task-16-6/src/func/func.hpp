#ifndef FUNC_HPP
#define FUNC_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include "Train.hpp"

void checkFile(std::fstream&);
void readFromFile(std::fstream&, std::vector<Train>&);
bool compareDepartureTime(Train&, Train&);
void printVector(std::vector<Train>&);
void trainsInTimePeriod(std::vector<Train>&);
void trainsInStation(std::vector<Train>&);
void fastTrainsInStation(std::vector<Train>&);
Train fastestTrainsInStation(std::vector<Train>&);
#endif