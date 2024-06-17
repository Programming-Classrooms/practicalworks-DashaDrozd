#ifndef BUSROUTE
#define BUSROUTE

#include <iostream>
#include <string>

class BusRoute
{
 private:
    int32_t  routeNum;
    std::string driver;
    int32_t busNum;
    std::string busBrend;

public:
    //Конструкторы
    BusRoute() = default; // по умолчанию
    BusRoute(int32_t initRouteNum, std::string initDriver, int32_t initBusNum, std::string initBusBrend); // с параметрами
    BusRoute(const BusRoute &rhs); // копирования

    ~BusRoute(){}; // деструктор

    BusRoute& operator=(BusRoute &rhs); // перегрузка оператора присваивания

    // Геттеры
    int32_t getRouteNum() const;
    std::string getDriver() const;
    int32_t getBusNum() const;
    std::string getBusBrend() const;

    //Сеттеры
    void setRouteNum(int32_t initRouteNum);
    void setDriver(std::string initDriver);
    void setBusNum(int32_t initBusNum);
    void setBusBrend(std::string initBusBrend);

    //Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& in, BusRoute &rhs);

    //Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream &out, const BusRoute &rhs);

    //перегрузка операторов сравнения

    bool operator==(const BusRoute &rhs) const;
    bool operator<(const BusRoute &rhs) const;

    
};

#endif // !BUSROUTE
