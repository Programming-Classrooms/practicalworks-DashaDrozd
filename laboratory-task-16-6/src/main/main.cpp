#include <exception>
#include <fstream>
#include <vector>
#include <algorithm>
#include "../func/func.hpp"
#include "../func/Train.hpp" 

int main ()
{
    try{
    std::fstream file("src/files/trains.txt");
    checkFile(file);
    std::vector<Train> trains;
    readFromFile(file,trains);
    std::cout <<"Упорядочение данных по времени отправления поездов" << std::endl;
    //упорядочение данных по времени отправления поездов;
    std::sort(trains.begin(), trains.end(), compareDepartureTime);
    printVector(trains);
    std::cout << "***************************************************************************" << std::endl;
    std::cout <<"Информация обо всех поездах из заданного диапазона времени" << std::endl;
    trainsInTimePeriod(trains);
    std::cout << "***************************************************************************" << std::endl;
    std::cout <<"Информации о всех поездах, направляющихся в заданный пункт назначения" << std::endl;
    trainsInStation(trains);
    std::cout << "***************************************************************************" << std::endl;
    std::cout <<"Информации о скорых поездах, направляющихся в заданный пункт назначения" << std::endl;
    fastTrainsInStation(trains);
    std::cout << "***************************************************************************" << std::endl;
    std::cout <<"Информации о скорых поездах, направляющихся в заданный пункт назначения" << std::endl;
    fastTrainsInStation(trains);
    std::cout << "***************************************************************************" << std::endl;
    std::cout << "Самый быстрый поезд в заданный пункт назначения " << std::endl;
    std::cout << fastestTrainsInStation(trains) << std::endl;
    }

    catch(std::logic_error e)
    {
        std::cerr << e.what(); 
    }

    catch(std::runtime_error e)
    {
        std::cerr << e.what(); 
    }

    return 0;

}