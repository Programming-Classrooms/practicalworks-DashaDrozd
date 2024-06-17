#include "BusRoute.hpp"

// -------------------------------------------Конструкторы-----------------------------------------------------
BusRoute::BusRoute(int32_t initRouteNum, 
std::string initDriver,
int32_t initBusNum,
std::string initBusBrend): routeNum(initRouteNum),
driver(initDriver),
busNum(initBusNum),
busBrend(initBusBrend)
{
    setBusNum(initBusNum);
    setRouteNum(initRouteNum);
}

BusRoute::BusRoute(const BusRoute &rhs):routeNum(rhs.routeNum),
driver(rhs.driver),
busNum(rhs.busNum),
busBrend(rhs.busBrend)
{
    setBusNum(rhs.busNum);
    setRouteNum(rhs.routeNum);
}

//Оператор присваивания
BusRoute &BusRoute::operator=(BusRoute &rhs)
{
    if(this != &rhs)
    {
        routeNum = rhs.routeNum;
        driver = rhs.driver;
        busNum = rhs.busNum;
        busBrend = rhs.busBrend;
    }

    return *this;
}

//-------------------------------------------------------Геттеры----------------------------------------------------------------
int32_t BusRoute::getRouteNum() const
{
    return this->routeNum;
}

std::string BusRoute::getDriver() const
{
    return this->driver;
}

int32_t BusRoute::getBusNum() const
{
    return this->busNum;
}

std::string BusRoute::getBusBrend() const
{
    return this->busBrend;
}

//--------------------------------------------------------Сеттеры-----------------------------------------------------
void BusRoute::setRouteNum(int32_t initRouteNum)
{
    if(initRouteNum < 0)
    {
        throw std::invalid_argument("Number cannot be negative number!\n");
    }

    routeNum = initRouteNum;
}

void BusRoute::setDriver(std::string initDriver)
{
    driver = initDriver;
}

void BusRoute::setBusNum(int32_t initBusNum)
{
   if(initBusNum < 0)
    {
        throw std::invalid_argument("Number cannot be negative number!\n");
    }

    busNum = initBusNum;
}

void BusRoute::setBusBrend(std::string initBusBrend)
{
    busBrend = initBusBrend;
}

bool BusRoute::operator==(const BusRoute &rhs) const
{
    return routeNum == rhs.routeNum;
}

bool BusRoute::operator<(const BusRoute &rhs) const
{
    return routeNum < rhs.routeNum;
}

//Оператор ввода
std::istream &operator>>(std::istream &in, BusRoute &rhs)
{
    in >> rhs.routeNum >> rhs.driver >> rhs.busNum >> rhs.busBrend;
    return in;
}

//Оператор вывода
std::ostream &operator<<(std::ostream &out, const BusRoute &rhs)
{
    out << "Route Number:  " << rhs.routeNum << "\nDriver: " << rhs.driver << "\n Bus Number: " << rhs.busNum << "\n Bus Brend: " << rhs.busBrend;
    out << std::endl;

    return out;
}
