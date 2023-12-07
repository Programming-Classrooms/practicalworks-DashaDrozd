#include <iostream> 
#include <functional> 
#include <cmath> 
 
using std::cout; 
using std::cin; 
 
double funct1(double x) 
{ 
   return asin(sqrt(x)) / (sqrt(x * (1 - x))); 
} 
double funct2(double x) 
{ 
   return pow(x, 3) * exp(2 * x); 
} 
double funct3(double x) 
{ 
   return pow(tan((x/2)+(acos(-1.0)/4)),3); 
} 
 
double trapezoidMethodIntergtal(const std::function<double(double)>& f, double a, double b,double eps ) 
{ 
   uint64_t n = 4; 
   double width = 0; 
   double x1 = 0, x2 = 0; 
   double s1 = 0; 
   double s2 = 0.5 * (f(a) + f(b)) * (b - a); 
   
   do { 
      s1 = s2; 
      n *= 2; 
      width = (b - a) / n; 
      s2 = 0; 
      
      for (int step = 0; step < n; ++step)  
      { 
         x1 = a + step * width; 
         x2 = a + (step + 1) * width; 
         s2 += 0.5 * (x2 - x1) * (f(x1) + f(x2)); 
      } 
      
   } while (fabs(s1 - s2) > eps); 
   
   return s2; 
} 
 
double rightRectangleMethodIntergtal(const std::function<double(double)>& f, double a, double b, double eps) 
{ 
   uint64_t n = 4; 
   double width = 0; 
   double x = 0; 
   double s1 = 0; 
   double s2 = f(b) * (b - a); 
   
   while (fabs(s1 - s2) >= eps) 
   { 
      s1 = s2; 
      s2 = 0.0; 
      n *= 2; 
      width = (b - a) / n; 
      
      for (int step = 1; step <= n; ++step) 
      { 
         x = a + step * width; 
         s2 += width * f(x); 
      } 
   
   } 
   
   return s2; 
} 
 
void getBoarders(double& boarder1, double& boarder2) 
{ 
   std::cout << "Enter the first boarder = "; 
   std::cin >> boarder1; 
   std::cout << "Enter the second boarder = "; 
   std::cin >> boarder2;

   if (boarder1 > boarder2) 
   {
      std::swap(boarder1, boarder2);
   }
   

} 

 void getEpsilon(double& eps)
 {
      while (eps <= 0) 
      { 
         std::cout << "Enter natural epsilon: "; 
         std::cin >> eps; 
      } 
 }
 
int main() { 
   double boarder1, boarder2; 
   boarder1 = 0; 
   boarder2 = 0; 
   double eps = -1; 
   getEpsilon(eps);
   double (*funct[3])(double) = {funct1, funct2, funct3}; 

   for (size_t i = 0; i < 3; ++i) 
   { 
      getBoarders(boarder1, boarder2); 
      cout << "Intergtal of " << i + 1 << " function by trapezoid method : " << trapezoidMethodIntergtal(funct[i], boarder1, boarder2, eps) << '\n'; 
      cout << "Intergtal of " << i + 1 << " function by right rectangle method : " << rightRectangleMethodIntergtal(funct[i], boarder1, boarder2, eps) << '\n'; 
   } 
   
   return 0; 
}
