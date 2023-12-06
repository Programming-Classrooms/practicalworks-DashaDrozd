#include <iostream> 
#include <functional> 
#include <cmath> 
 
using std::cout; 
using std::cin; 
 
double functFirst(double x) 
{ 
 return asin(sqrt(x)) / (sqrt(x * (1 - x))); 
} 
double functSecond(double x) 
{ 
 return pow(x, 3) * exp(2 * x); 
} 
double functThird(double x) 
{ 
 return pow(tan((x/2)+(acos(-1.0)/4)),3); 
} 
 
double trapIntegral(const std::function<double(double)>& f, double a, double b,double eps ) 
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
 
double rightRectIntegral(const std::function<double(double)>& f, double a, double b, double eps) 
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
 
void getAAndB(double& a, double& b) 
{ 
 std::cout << "Enter a = "; 
 std::cin >> a; 
 std::cout << "Enter b = "; 
 std::cin >> b; 
 if (a > b) 
  std::swap(a, b); 
} 
 
 
int main() { 
 double a, b; 
 a = 0; 
 b = 0; 
 double eps = -1; 
 while (eps <= 0) { 
  std::cout << "Enter natural epsselont: "; 
  std::cin >> eps; 
 } 
 double (*funct[3])(double) = {functFirst,functSecond,functThird}; 
 
 for (size_t i = 0; i < 3; ++i) 
 { 
  getAAndB(a, b); 
  cout << "Integrall of " << i + 1 << " function by trapecia method : " << trapIntegral(funct[i], a, b, eps) << '\n'; 
  cout << "Integrall of " << i + 1 << " funtion by right rectangle method : " << rightRectIntegral(funct[i], a, b, eps) << '\n'; 
 } 
 
 return 0; 
}
