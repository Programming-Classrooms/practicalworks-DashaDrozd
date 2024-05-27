#include "func.hpp"

void writeFishermanData(std::ofstream& file, const std::set<std::string>& fisherman, const std::string& fishermanName) {
    file << fishermanName << " поймал: ";
    for (const auto& fish : fisherman) {
        file << fish << " ";
    }
    file << std::endl;
}

void writeFishData(std::ostream& file, const std::set<std::string>& fishSet) {
    for (const auto& fish : fishSet) {
        file << fish << " ";
    }
    file << std::endl;
}
