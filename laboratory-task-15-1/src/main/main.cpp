#include <string.h>
#include "../TDeque/TDeque.hpp"

void doubling(int32_t inf)
{
    inf = inf * 2;

}

void printInt(int32_t inf) {
    std::cout << inf << " ";
}

int main()
{
    try{
           TDeque<int32_t> intDeque;

            // Тестирование вставки в дек
            intDeque.InsFront(5);
            intDeque.InsRear(6);
            intDeque.InsFront(7);
            intDeque.InsRear(8);
            intDeque.InsFront(3);

            std::cout << "Дек после вставок: ";
            intDeque.print();

            // Тестирование функции удвоения
            intDeque.Browse(doubling);

            std::cout << "Дек после удвоения: ";
            intDeque.print();

            // Тестирование функции печати
            std::cout << "Печать элементов дека: ";
            intDeque.Browse(printInt);
            std::cout << std::endl;

            // Тестирование изменения элемента по индексу
            intDeque.SetByIndex(9, 0);
            std::cout << "Дек после SetByIndex: ";
            intDeque.print();

            // Тестирование получения элемента по индексу
            int32_t elem = intDeque.GetByIndex(2);
            std::cout << "Элемент на индексе 2: " << elem << std::endl;

            // Тестирование удаления из головы и хвоста
            int32_t temp;
            intDeque.DelFront(temp);
            intDeque.DelRear(temp);

            std::cout << "Дек после удаления: ";
            intDeque.print();
            
            TDeque<char*> deque;

            char* str1 = new char[6];
            char* str2 = new char[6];
            char* str3 = new char[6];
            char* str4 = new char[8];
            char* str5 = new char[5];

            strcpy(str1, "Vadim");
            strcpy(str2, "Dima");
            strcpy(str3, "Danik");
            strcpy(str4, "Dasha");
            strcpy(str5, "Vlad");

            // Тестирование вставки в дек
            deque.InsFront(str1);
            deque.InsRear(str2);
            deque.InsFront(str3);
            deque.InsRear(str4);
            deque.InsFront(str5);

            std::cout << "Дек после вставок: ";
            deque.print();

            // Тестирование изменения элемента по индексу
            char* newStr = new char[10];
            strcpy(newStr, "NewString");
            deque.SetByIndex(newStr, 0);
            std::cout << "Дек после SetByIndex: ";
            deque.print();

            // Тестирование получения элемента по индексу
            char* elm = deque.GetByIndex(2);
            std::cout << "Элемент на индексе 2: " << elm << std::endl;

            // Тестирование удаления из головы и хвоста
            char* tmp;
            deque.DelFront(tmp);
            delete[] tmp;
            deque.DelRear(tmp);
            delete[] tmp; 

            std::cout << "Дек после удаления: ";
            deque.print();

        }   

    catch(std::out_of_range e)
    {
        std::cerr << e.what() << "\n";
    }
    return 0;
}