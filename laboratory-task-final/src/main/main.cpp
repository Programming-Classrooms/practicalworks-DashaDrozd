#include <fstream>
#include <exception>
#include <sstream>

#include "../BusRouteList/BusRouteList.hpp"

void checkFile(std::fstream &file)
{
    if(!file.good())
    {
        throw std::runtime_error("File is not exist!\n");
    }

    if(!file)
    {
        throw std::runtime_error("File is not open!\n");
    }

    if(file.peek() == EOF)
    {
        throw std::runtime_error("File is empty!\n");
    }
}

int main()
{
    std::fstream file("src/files/busRoutes.txt");
    checkFile(file);
    BusRouteList buses;
    file >> buses ;
    std::cout << buses;
    //buses.sortByBusAndRouteNums(buses);
    std::cout << buses;
    std::map<std::string, BusRoute> busList;
    for(auto& bus:buses.getBusList())
    {
        busList.insert(std::pair(bus.getDriver(), bus));
    }

    for(const auto& pair: busList)
    {
       
       std::cout << pair.second <<std::endl;
    }

     //for(const auto& pair: busList)
    //{
     //  for(suze_t i = 0, i < busList.size(), ++i)
      // if(s)
    //}


}