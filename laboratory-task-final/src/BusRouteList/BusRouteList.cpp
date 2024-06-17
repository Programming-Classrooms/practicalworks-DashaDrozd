#include <algorithm>
#include "BusRouteList.hpp"

BusRouteList::BusRouteList(std::vector<BusRoute> initBusList):busList(initBusList)
{

}

BusRouteList::BusRouteList(const BusRouteList &rhs):busList(rhs.busList)
{
}

bool BusRouteList::cmp(const BusRoute &rhs, const BusRoute &lhs)
{
    if(rhs.getBusNum()  < lhs.getBusNum())
    {
        if(rhs.getRouteNum() < lhs.getRouteNum())
        {
            return true;
        }
    }
    return false;
}

//void BusRouteList::sortByBusAndRouteNums(BusRouteList &rhs)
 //{
    //rhs.busList.sort(rhs.busList.begin(),rhs.busList.end(), cmp);
 //}

 std::vector<BusRoute> BusRouteList::getBusList()
 {
     return this->busList;
 }

std::istream &operator>>(std::istream &in, BusRouteList &rhs)
{
    BusRoute bus;
    while(in >> bus)
    {
        rhs.busList.push_back(bus);
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, const BusRouteList &rhs)
{

    for(const auto& bus : rhs.busList)
    {
        out << bus << " ";
    }

    out << std::endl;

    return out;
}
