#include <string.h>
#include "../Carriage/Carriage.hpp"
#include "../Stack/Stack.hpp"

//Функция переформирования вагона
void reorderTrain(Stack<Carriage>& train) {
    Stack<Carriage> redCarriages;
    Stack<Carriage> greenCarriages;
//Раскидывание по цветам
    while (!train.isEmpty()) {
        Carriage carr = train.top();
        train.pop();
        switch (carr.getColor()) {
            case Color::RED:
                redCarriages.push(carr);
                break;
            case Color::GREEN:
                greenCarriages.push(carr);
                break;
        }
    }

//чередование
    bool turnRed = true;
    while (!redCarriages.isEmpty() || !greenCarriages.isEmpty()) {
        if (turnRed && !redCarriages.isEmpty()) {
            train.push(redCarriages.top());
            redCarriages.pop();
        } else if (!turnRed && !greenCarriages.isEmpty()) {
            train.push(greenCarriages.top());
            greenCarriages.pop();
        }
        turnRed = !turnRed;
    }
}   

int main()
{
    try{
            Stack<Carriage> train;
            train.push(Carriage(Color::RED));
            train.push(Carriage(Color::RED));
            train.push(Carriage(Color::GREEN));
            train.push(Carriage(Color::GREEN));
            train.push(Carriage(Color::RED));

            std::cout << "Original train: ";
            train.print();

            reorderTrain(train);

            std::cout << "Reordered train: ";
            train.print();
 

    }   

    catch(std::out_of_range e)
    {
        std::cerr << e.what() << "\n";
    }
    return 0;
}