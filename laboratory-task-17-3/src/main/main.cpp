#include <iostream> 
#include <fstream> 
#include <set> 
#include <algorithm> 

#include "../func/func.hpp"
 
int main() { 
    setlocale(LC_ALL, "Rus"); 
    std::set<std::string> fisherman1 = { "щука", "окунь" }; 
    std::set<std::string> fisherman2 = { "окунь", "карп" }; 
    std::set<std::string> fisherman3= { "щука", "судак" }; 
 
    // Все виды рыб, пойманные хотя бы одним рыбаком 
    std::set<std::string> allFish; 
    allFish.insert(fisherman1.begin(), fisherman1.end()); 
    allFish.insert(fisherman2.begin(), fisherman2.end()); 
    allFish.insert(fisherman3.begin(), fisherman3.end()); 
 
    // Виды рыб в озере 
    std::set<std::string> lake = { "щука", "окунь", "карп", "судак", "лещ" }; 
 
    // Рыбы, которые есть в озере, но не в улове рыбаков 
    std::set<std::string>  fishOnlyInLake; 
    std::set_difference(lake.begin(), 
    lake.end(), 
    allFish.begin(), 
    allFish.end(), 
    std::inserter(fishOnlyInLake, fishOnlyInLake.end())); 
 
    // Запись информации в файл 
    std::ofstream file("src/files/fishermans.txt"); 
    writeFishermanData(file, fisherman1, "Рыбак 1");
    writeFishermanData(file, fisherman2, "Рыбак 2");
    writeFishermanData(file, fisherman3, "Рыбак 3");
    file << "Рыбы, выловленные хотя бы одним рыбаком: ";
    writeFishData(file, allFish);
    file << "Рыбы в озере, но не в улове рыбаков: ";
    writeFishData(file, fishOnlyInLake);
    file.close();
    return 0; 
}