/*
    Для заданных натуральных чисел А и В определяет возможность
    получения числа А вычеркиванием цифр из числа В.
*/


#include <iostream> 
#include <cmath>


 int32_t inputNumber(int32_t& A)
{
    std::cout << "Enter number : "; 
        std::cin >> A; 

     while (A <= 0) { 
        std::cout << "A is not a natural number.Try again: "; 
        std::cin >> A; 
    } 

    return A;
}

void countDigits(int32_t& temp,int32_t& counterA)
{
    while (temp > 0) { 
        temp = temp / 10; 
        ++counterA; 
    } 

}

void compareNumbers(int32_t& A, int32_t& B)
{
  if (A > B) { 
        std::cout << "Impossible"; 
    } 
}

int32_t compareDigitOfNumbs(int32_t& counterA, int32_t& digitA,
                           int32_t& A, int32_t& B,
                           int32_t& tempB, int32_t& tempB2,
                           int32_t& counterB,  int32_t& counter, int32_t& digitB)
{
     for (size_t i = 0; i < counterA; ++i) { 
        digitA = A % 10; 
        tempB = 0; 
        tempB2/= 10; 
        for (size_t j = 0; j < counterB; ++j) { 
            digitB = tempB2 % 10;

            if ( digitA == digitB) { 
                ++counter; 
                B /= 10; 
            } 

            tempB += digitB * pow(10, i); 

            if (digitB == digitA) { 
                ++counter; 
                B = tempB2 + tempB; 
            } 

            else { 
                tempB2 /= 10; 
            } 
        } 
        A /= 10; 
    } 

}
int main() { 
    int32_t A, B; 
    int32_t counterA = 0, counterB = 0, counter = 0, digitA = 0, digitB = 0, temp = 0, tempB2 = 0; 
    inputNumber(A);
    inputNumber(B);
    compareNumbers(A,B);
    temp = A; 
    int32_t tempB = B; 
    countDigits(temp,counterA);
    temp = B; 
    countDigits(temp,counterB);
    int32_t tempA = A; 
    digitB = tempB2 % 10; 
    digitA =  tempA % 10; 
    tempB2 = B; 
    compareDigitOfNumbs(counterA, digitA, A, B, tempB, tempB2, counterB, counter, digitB);
    
    if (counter >= counterA) { 
        std::cout << "Possible"; 
    } 
    else { 
        std::cout << "Impossible"; 
    } 

    return 0;
}