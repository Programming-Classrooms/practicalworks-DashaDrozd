#include <iostream> 
#include <math.h>

int32_t getNumb(int& num)
{
    std::cout << "Input natural number:\n";
    std::cin >> num;
    while (num <= 0)
    {
        std::cout << "Not a natural";
        return 0;
    }
}

int main()
{
    int temp, num, max = 0;
    double cnt = 1.0;
    getNumb(num);
    temp = num;
    
           temp = num;
            while (temp != 0)
            {
                if (temp % 10 > max )
                {
                    max = temp % 10;
                }

                temp /= 10;
                cnt++;
            }

    std::cout << max * pow(10,cnt) + num *10 + max <<'\n';
    std::cout << max << num << max<<'\n';
        return 0;
    }
