/*
    добавляет слева и справа в записи числа цифру, повторяющуюся
    максимальное число раз;
*/


#include <iostream>
#include <math.h>


void inputNumb(int &num)
{
    std::cout << "Input natural number:\n";
    std::cin >> num;

    while (num <= 0)
    {
        std::cout << "Not a natural";
        std::cin >> num;
    }
}

int main()
{
    int temp = 0, num = 0, max = 0;
    double cnt = 1.0;
    inputNumb(num);
    temp = num;
    double lastDigit = temp % 10;
    
    while (temp != 0)
    {
        if (lastDigit> max)
        {
            max = lastDigit;
        } 

        temp /= 10;
        cnt++;
    }

    std::cout << max * pow(10, cnt) + num * 10 + max << '\n';
    std::cout << max << num << max << '\n';
    return 0;
}
