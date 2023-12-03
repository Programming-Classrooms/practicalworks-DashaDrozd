#include <iostream> 
int main() { 
    int32_t A, B; 
    int32_t cntA = 0, cntB = 0, sch = 0, digitA = 0, digitB = 0, temp = 0, tempBB = 0; 
    std::cout << "Enter number A: "; 
        std::cin >> A; 

    while (A <= 0) 
    { 
        std::cout << "A is not a natural number.Try again: "; 
        std::cin >> A; 
    } 

    std::cout << "Enter number B: "; 
    std::cin >> B; 
 
    while (B <= 0) 
    { 
        std::cout << "B is not a natural number"; 
        std::cin >> B; 
    } 

    if (A > B) 
    { 
        std::cout << "Impossible"; 
        return 0; 
    } 
 
    temp = A; 
    int32_t tempB = B; 

    while (temp > 0)
    { 
        temp = temp / 10; 
        ++cntA; 
    } 
    temp = B; 

    while (temp > 0) 
    { 
        temp = temp / 10; 
        ++cntB; 
    } 
     
    
    int32_t tempA = A; 
        digitB = tempBB % 10; 
        digitA =  tempA % 10; 
        tempBB = B; 

    for (size_t i = 0; i < cntA; ++i) 
    { 
        digitA = A % 10; 
        tempB = 0; 
          tempBB/= 10; 
        for (size_t j = 0; j < cntB; ++j)
        { 
            digitB = tempBB % 10;

            if ( digitA == digitB) 
            { 
                ++sch; 
                B /= 10; 
            } 

            tempB += digitB * pow(10, i); 

            if (digitB == digitA)
            { 
                ++sch; 
                B = tempBB + tempB; 
            } 

            else 
            { 
                tempBB /= 10; 
            } 
        } 
        A /= 10; 
    } 

    if (sch >= cntA) 
    { 
        std::cout << "Possible"; 
    } 
    else 
    { 
        std::cout << "Impossible"; 
    } 
    return 0;
}
