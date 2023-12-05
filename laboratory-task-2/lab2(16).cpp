#include <iostream> 
#include <cmath>

 int32_t getNumber(int32_t& A)
{
    std::cout << "Enter number A: "; 
        std::cin >> A; 

     while (A <= 0) 
    { 
        std::cout << "A is not a natural number.Try again: "; 
        std::cin >> A; 
    } 
    return A;
}

int32_t devisionByNumb(int32_t& temp,int32_t& counterA)
{
    while (temp > 0)
    { 
        temp = temp / 10; 
        ++counterA; 
    } 
    return counterA;
}

int main() { 
    int32_t A, B; 
    int32_t counterA = 0, counterB = 0, counter = 0, digitA = 0, digitB = 0, temp = 0, tempB2 = 0; 
    getNumber(A);
    getNumber(B);

    if (A > B) 
    { 
        std::cout << "Impossible"; 
        return 0; 
    } 
    temp = A; 
    int32_t tempB = B; 
    devisionByNumb(temp,counterA);
    temp = B; 
    devisionByNumb(temp,counterB);
    int32_t tempA = A; 
        digitB = tempB2 % 10; 
        digitA =  tempA % 10; 
        tempB2 = B; 

    for (size_t i = 0; i < counterA; ++i) 
    { 
        digitA = A % 10; 
        tempB = 0; 
          tempB2/= 10; 
        for (size_t j = 0; j < counterB; ++j)
        { 
            digitB = tempB2 % 10;

            if ( digitA == digitB) 
            { 
                ++counter; 
                B /= 10; 
            } 

            tempB += digitB * pow(10, i); 

            if (digitB == digitA)
            { 
                ++counter; 
                B = tempB2 + tempB; 
            } 

            else 
            { 
                tempB2 /= 10; 
            } 
        } 
        A /= 10; 
    } 

    if (counter >= counterA) 
    { 
        std::cout << "Possible"; 
    } 
    else 
    { 
        std::cout << "Impossible"; 
    } 

    return 0;
}
