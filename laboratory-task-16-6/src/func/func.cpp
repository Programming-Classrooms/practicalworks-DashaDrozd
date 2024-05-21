#include "func.hpp"
#include "Train.hpp"

void checkFile(std::fstream& file)
{
    if(!file.good())
    {
       throw std::runtime_error("File is not exist!");
    }

    if(!file)
    {
        throw std::runtime_error("File is not open!");
    }

    if(file.peek() == EOF)
    {
        throw std::runtime_error("File is empty!");
    }
}

void readFromFile(std::fstream &file, std::vector<Train> &trains)
{
    Train train;
    while(file >> train)
    {
        trains.push_back(train);
    }

}

bool compareDepartureTime(Train &first, Train &second)
{
    return first < second;
}

void printVector(std::vector<Train> &trains)
{
    for(size_t i = 0; i < trains.size(); ++i)
    {
        std::cout << trains[i] << std::endl;
    }
}

void trainsInTimePeriod(std::vector<Train> &trains)
{
    std::string fromTime;
    std::string toTime;
    std::cout << "Введите начало промежутка: ";
    std::cin >> fromTime;
    std::cout << "Введите конец промежутка: ";
    std::cin >> toTime;
    bool found = false ;

    if(toTime < fromTime)
    {
        std::swap(toTime,fromTime);
    }

    for(Train train:trains)
    {
        if(toTime >= train.getDepartureTime() &&  train.getDepartureTime() >= fromTime)
        {
            std::cout << train << std::endl;
            found = true;
        }
    }

    if(!found)
    {
        throw std::logic_error("There are not such trains\n");
    }

}

void trainsInStation(std::vector<Train> &trains)
{
    std::string station;
    std::cout << "Введите название пункта назначения: ";
    std::cin >> station;
    bool found = false;
    for(Train train:trains)
    {
        if(train.getStationName() == station)
        {
            std::cout << train << std::endl;
            found = true;
        }
    }

    if(!found)
    {
        throw std::logic_error("There are not such trains\n");
    }
}

void fastTrainsInStation(std::vector<Train> &trains)
{
    std::string station;
    std::cout << "Введите название пункта назначения: ";
    std::cin >> station;
    bool found = false;

    for(Train train:trains)
    {
        if(train.getStationName() == station && train.getType() == TrainType::fast)
        {
            std::cout << train << std::endl;
            found = true;
        }
    }

    if(!found)
    {
        throw std::logic_error("There are not such trains\n");
    }

}

Train fastestTrainsInStation(std::vector<Train> &trains)
{
    std::string station;
    std::cout << "Введите название пункта назначения: ";
    std::cin >> station;
    Train fastestTrain;
    bool found = false;
    std::string minTime = "99:59" ;
    for(Train train:trains)
    {
        if(train.getStationName() == station)
        {
            if(train.getTravelTime() < minTime)
            {
                minTime = train.getTravelTime();
                fastestTrain = train;
            }

            found = true;
        }
    }

    if(!found)
    {
        throw std::logic_error("There are not such trains\n");
    }
    
    return fastestTrain;
}