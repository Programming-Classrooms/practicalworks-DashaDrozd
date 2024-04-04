#include "../Matrix/Matrix.h"
#include "../Fraction/Fraction.h"

int main()
{
	try {
		
		 Matrix right;
		 std::cin >> right;
		 std::cout << right;
		 Matrix left;
		 std::cin >> left;
		 std::cout << left << '\n';
		 std::cout << left + right << '\n';
		 std::cout << left * 5 << '\n';
		 std::cout << 5 * left << '\n';
		 std::cout << left / 4 << '\n';
		 std::cout << left * right << '\n';
		 if (left != right)
		 {
		 	std::cout << "true\n";
		 }

		Fraction drob(5,5);
		std::cin >> drob;
		std::cout << drob;
		Fraction drob2;
		std::cin >> drob2;
		std::cout << drob2;
		std::cout << drob2 + drob;
		std::cout << drob2 / drob;
		std::cout << drob2 * drob;

		if(drob2 != drob)
		{
			std::cout << "true";
		}
		return 0;
	}
	
	catch (std::out_of_range e) {
		std::cout << e.what();
		return 1;
	}

	catch (std::invalid_argument e) {
		std::cout << e.what();
		return 1;
	}

}