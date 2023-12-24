/*
    В массиве, состоящем из п целых элементов, вычислить:

    - минимальный по модулю элемент массива;
    - сумму элементов массива, расположенных после последнего нулевого элемента.
    Преобразовать массив таким образом, чтобы в первой его половине располагались все
    элементы с четными номерами , а во второй половине — с нечетными. Порядок следования
    элементов не изменять.

*/
#include <iostream> 
#include <cstdlib>  
#include <ctime> 

void printArr(int32_t* arr, const int32_t& n) 
{ 
    for (size_t i = 0; i < n; ++i)  { 
        std::cout << arr[i]<<" "; 
    } 
} 

void mySwap(int32_t& a, int32_t& b) 
{ 
    int32_t temp; 
    temp = a; 
    a = b; 
    b = temp; 
} 

int32_t minimum(int32_t* arr, const int32_t& n) 
{ 
    int32_t min = arr[0]; 

    for (size_t i = 1; i < n; ++i) {
        if (abs(arr[i]) < min) {
            min = arr[i];
        } 
    }

    return min;
} 

int32_t sum(int32_t* arr, const int32_t& n) 
{ 
    bool exist = false; 
    int32_t sum = 0; 

    for (int i = 0; i < n; ++i) { 
        if (arr[n - 1 - i] == 0) { 
            exist = true; 
            return sum; 
        } 
        sum += arr[n - 1 - i]; 
    } 

    if (arr[n - 1] == 0) throw "last!\n"; 
    if ( exist == false) throw "Zero is not exsist!\n"; 

    return 0; 
} 

void shiftLeft(int32_t* arr, const int32_t& n,const int32_t& ind, int32_t shiftLen) 
{ 
    if (ind > n) { 
        throw "Index must be lower than size of array\n"; 

    } 
    
    if (shiftLen > n) { 
       throw "Number of shifts must be lower than size of array\n"; 
    }
    
    for (size_t i = 0; i < shiftLen; ++i) { 
         mySwap(arr[ind-i], arr[ind - i-1]); 
    }  
} 

void inputArrayFromKeyboard(int32_t* arr, const int32_t& size) 
{ 
    std::cout << "Enter elements of array : "; 
    
    for (size_t i = 0; i < size; ++i) { 
        std::cin >> arr[i]; 
    } 
} 

void inputArrayFromRandom(int* arr, const int32_t& size) 
{ 
    int32_t a, b; 
    std::cout << "Enter borders: "; 
    std::cin >> a >> b; 

    if (a > b) { 
        mySwap(a, b); 
    } 

    for (size_t i = 0; i < size; ++i) { 
        arr[i] = rand() % (b - a) + a; 
    } 

} 

void getNumber(int32_t& n)
{
    while (n <= 0) { 
        std::cout << "Enter number of elements: " << std::endl; 
        std::cin >> n; 
    }
    
 }  

int main() 
{ 
    int32_t n; 
    getNumber(n);
    int32_t* arr = new int32_t [n];
    int32_t oper; 
    std::cout << "Input number 0 - random, 1- keyboard : "; 
    std::cin >> oper; 

    switch (oper) { 
        case 0: 
            inputArrayFromRandom(arr, n); 
        break; 
        case 1: 
            inputArrayFromKeyboard(arr, n); 
        break; 
        default: 
            std::cout << "Input incorrect value.Get out of my program!"; 
        return 1; 
    } 

    std::cout << "\nSource array: "; 
    printArr(arr, n); 
    std::cout << "\n"; 

    auto p =  minimum(arr,n); 
    std::cout << "\n\nMinimum element: " << p << "\n"; 

    try { 
        std::cout<<"Sum of elements after last 0: "<<sum(arr, n); 
        std:: cout<<"\nSorted array: ";
        
        for (size_t i = 0; i < n; i+=2){ 
            shiftLeft(arr, n, i , i >> 2); 
        } 
        
    } 
    
    catch (const char* msg) { 
        std::cout << msg; 
        printArr(arr, n); 
        std::cout << "\n";
    } 
    
    delete [] arr;
    return 0; 
}

