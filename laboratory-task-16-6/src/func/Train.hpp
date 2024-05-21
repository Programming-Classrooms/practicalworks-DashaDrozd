#ifndef TRAIN_HPP
#define TRAIN_HPP
#include <iostream>
enum class  TrainType{ 
    fast,
    passengers,
};

class Train {
    private:
    size_t number;
    std::string stationName;
    TrainType type;
    std::string departureTime;
    std::string travelTime;
    
    public:
    Train();
    Train(size_t, std::string, TrainType, std::string, std::string);
    Train(const Train&);
    ~Train();
    std::string getDepartureTime();
    std::string getStationName();
    TrainType getType();
    std::string getTravelTime();
    Train& operator=(const Train&);
    bool operator<(const Train&) const;
    bool operator==(const Train&) const;
    friend std::istream& operator>>(std::istream&, Train&);
    friend std::ostream& operator<<(std::ostream&, const Train&);
};
#endif