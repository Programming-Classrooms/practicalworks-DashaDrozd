#include "../Matrix/Matrix.h"
#include "../Fraction/Fraction.h"
#include "../Toy/Toy.h"
#include "../List/List.h"

Toy increaseAge(const Toy toy) {
    Toy modifiedToy = toy;
    modifiedToy.setAge(toy.getAge() + 1);
    return modifiedToy;
}

void printToy( const Toy& toy) {
    std::cout << toy;
}

int main()
{
	try {
		
		 Matrix right;
		 std::cin >> right;
		 std::cout << right;
		 Matrix left;
		 std::cin >> left;
		 std::cout << left << '\n';
		 std::cout <<"Sum: " << left + right << '\n';
		 std::cout <<"Multiplication by the scalar on the right: " << left * 5 << '\n';
		 std::cout <<"Multiplication by the scalar on the left: " << 5 * left << '\n';
		 std::cout <<"Division by the scalar: " << left / 4 << '\n';
		 std::cout <<"Multiplication: " << left * right << '\n';
		 if (left != right)
		 {
		 	std::cout << "they are not equal\n";
		 }

		Fraction drob(5,5);
		std::cin >> drob;
		std::cout << drob;
		Fraction drob2;
		std::cin >> drob2;
		std::cout << drob2;
		std::cout <<"Sum: " << drob2 + drob;
		std::cout <<"Division: " << drob2 / drob;
		std::cout <<"Multiplication: " << drob2 * drob;
		std::cout << "Decrement ++: " << drob++;
		std::cout << "Increment --: " << --drob;
		std::cout << "Increment ++: " << ++drob;
		std::cout << "Decrement --:" << drob--;
		if(drob2 != drob)
		{
			std::cout << "they are not equal\n";
		}

		Toy toy;
		std::cin >> toy;
		std::cout<< toy;
		List<Toy> toyList;
	    toyList.insertFront(toy);// Вставка в начало
		toyList.insertEnd(Toy("Car", 3));
        toyList.insertEnd(Toy("Doll", 5));//Вставка в конец
		Toy ball("Ball", 2); 
		toyList.insertEnd(ball);//Вставка в конец
		Toy teddy("Teddy", 0); 
		size_t count = 0;
		toyList.insertFront(teddy);
		std::cout << "List of toys: ";
		toyList.print();//вывод
		if(toyList.find(teddy, count))
		{
			std::cout << "find teddy, number of comparisons: " << count << '\n';
		}
		std::cout <<" Deleted first toy: ";
		toyList.deleteFront();//Удаление первого
		toyList.print();
		std::cout << "Deleted last toy: ";
		toyList.deleteEnd();//Удаление последнего
		toyList.print();
		std::cout << "Deleted Car";
		toyList.deleteValue(Toy("Car", 3));//Удаление по значению
		toyList.print();
		toyList.forEachModify(increaseAge);//увеличиваем возраст на 1

		std::cout << "\nAfter modification (increase age by 1):" << '\n';
		toyList.print(); // Cписок после изменения

		std::cout << "\nPrinting toys without modification:" << '\n';
		toyList.forEachCallback(printToy);//без изменения

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