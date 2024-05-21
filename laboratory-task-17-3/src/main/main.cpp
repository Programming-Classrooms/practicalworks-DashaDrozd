#include <iostream> 
#include <fstream> 
#include <set> 
#include <algorithm> 
 
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
    std::set_difference(lake.begin(), lake.end(), allFish.begin(), allFish.end(), std::inserter(fishOnlyInLake, fishOnlyInLake.end())); 
 
    // Запись информации в файл 
    std::ofstream file("src/files/рыбаки.txt"); 
        file << "Рыбак 1 поймал: "; 
        for (const auto& fish : fisherman1) { 
            file << fish << " "; 
        } 
        file <<std::endl; 
 
        file << "Рыбак 2 поймал: "; 
        for (const auto& fish : fisherman2) { 
            file << fish << " "; 
        } 
        file << std::endl; 
 
        file << "Рыбак 3 поймал: "; 
        for (const auto& fish : fisherman3) { 
            file << fish << " "; 
        } 
        file << std::endl; 
 
        // Виды рыб, пойманные хотя бы одним рыбаком 
        file << "Рыбы, выловленные хотя бы одним рыбаком: "; 
        for (const auto& fish : allFish) { 
            file << fish << " "; 
        } 
        file << std::endl; 
 
        // Рыбы в озере, но не в улове рыбаков 
        file << "Рыбы в озере, но не в улове рыбаков: "; 
        for (const auto& fish : fishOnlyInLake) { 
            file << fish << " "; 
        } 
        file << std::endl; 
 
        file.close(); 
        std::cout << "Информация успешно записана в файл 'рыбаки.txt'." << std::endl; 
 
    return 0; 
}