/*
    Находит для заданного натурального N все пифагоровы тройки
    чисел, каждое из которых не превосходит N.
*/

#include <iostream> 


void inputNumb(int32_t& n)
{
    std::cout << "Enter natural number"; 
    std::cin >> n; 

     while (n <= 0) 
    { 
        std::cout << "Not natural number.Try again: "; 
        std::cin >> n; 
    } 
}

int main() 
{ 
    int32_t n; 
    inputNumb(n);

    for (size_t a = 1;a <= n; a++) {
        for (size_t b = 1;b <= n; b++) {
            for (size_t c = 1; c <= n; c++) { 
                if ( c * c == a * a + b * b) { 
                    std::cout << " a= " << a << " b= " << b << " c= " << c<<'\n'; 
                } 

                if (a * a == c * c + b * b) { 
                    std::cout << " a= " << a << " b= " << b << " c= " << c << '\n'; 
                } 

                if (b * b == c * c + a * a) { 
                    std::cout << " a= " << a << " b= " << b << " c= " << c << '\n'; 
                } 
            } 
        }

    }
    
    return 0; 
}
