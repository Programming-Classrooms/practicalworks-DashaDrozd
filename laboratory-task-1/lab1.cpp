#include <iostream> 
#include <cmath> 


int main() 
{ 
 double eps, p, s, x; 
 int32_t n; 

 std::cout << "input x="; 
 std::cin >> x; 
 std::cout << "input eps="; 
 std::cin >> eps; 

 p = x; 
 s = 0; 
 n = 1; 

 if (x < -1 || x >= 1) { 
  std::cout << "error x belongs [-1;1)" << '\n'; 
 } 
 while (fabs(p) >= eps) { 
  s -= p; 
  p = ( p * x ) / n; 
  ++n; 
 } 
  
 std::cout << "ln(1-x)=" << logf(1 - x) << "\ts=" << s; 
 
 return 0;
}
