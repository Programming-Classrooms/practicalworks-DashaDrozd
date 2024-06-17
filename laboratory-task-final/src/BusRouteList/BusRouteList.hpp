#include <map>
#include <vector>

#include "src/BusRoute/BusRoute.hpp"

class BusRouteList
{

private:

    std::vector <BusRoute> busList;

public:
    BusRouteList() = default;
    BusRouteList(std::vector<BusRoute> initBusList);
    BusRouteList( const BusRouteList& rhs);
    ~BusRouteList(){};

    friend std::istream& operator>>(std::istream& in, BusRouteList &rhs);
    friend std::ostream& operator<<(std::ostream &out, const BusRouteList &rhs);

    bool cmp(const BusRoute &rhs, const BusRoute &lhs);
    //void sortByBusAndRouteNums(BusRouteList &rhs);

    std::vector<BusRoute> getBusList();
};