#include "../func/Train.hpp"
#include "Train.hpp"

Train::Train(): number(1), stationName("Minsk-passengir"), type(TrainType::passengers), departureTime("11:00"), travelTime("1:39")
{
}

Train::Train(size_t num, std::string name, TrainType inType, std::string inDepTime, std::string inTravelTime): number(num), stationName(name), type(inType), departureTime(inDepTime), travelTime(inTravelTime)
{
}

Train::Train(const Train &rhs): number(rhs.number), stationName(rhs.stationName), type(rhs.type), departureTime(rhs.departureTime), travelTime(rhs.travelTime)
{
}

Train::~Train()
{
}

std::string Train::getDepartureTime()
{
    return departureTime;
}

std::string Train::getStationName()
{
    return stationName;
}

TrainType Train::getType()
{
    return type;
}

std::string Train::getTravelTime()
{
    return travelTime;
}

Train &Train::operator=(const Train &rhs)
{
    if(this != &rhs){
        number = rhs.number;
        stationName = rhs.stationName;
        type = rhs.type;
        departureTime = rhs.departureTime;
        travelTime = rhs.travelTime;
    }

    return *this;
}

bool Train::operator<(const Train &rhs) const
{
    return departureTime < rhs.departureTime;
}

bool Train::operator==(const Train &rhs) const
{
    return stationName == rhs.stationName;
}

std::istream &operator>>(std::istream &in, Train &train)
{
    size_t num;
    std::string name;
    std::string type;
    std::string depTime;
    std::string travelTime;

    in >> num >> name >> type >> depTime >> travelTime;

    train.number = num;
    train.stationName = name;
    if(type == "fast")
    {
        train.type = TrainType::fast;
    }

    if(type == "passengers")
    {
        train.type = TrainType::passengers;
    }

    train.departureTime = depTime;
    train.travelTime = travelTime;

    return in;

}

std::ostream &operator<<(std::ostream &out, const Train &train)
{
    out << "Train number: " << train.number << std::endl;
    out << "Station name: " << train.stationName << std::endl;
    out << "Type of train: " ;
    switch(train.type)
    {
        case TrainType::fast:
        out << "fast" << std::endl;
        break;

        case TrainType::passengers:
        out << "passengers" << std::endl;
        break;

    }
    out << "Departure time: " << train.departureTime << std::endl;
    out << "Travel time: " << train.travelTime << std::endl;
    out << std::endl;

    return out;
}
