//o сумму чисел;
// o общее количество чисел;
// o количество чисел, равных заданному;
// o количество чисел, удовлетворяющих условию, например,
// «больше, чем n»;
// o заменить все нули средним арифметическим (взять целую
// часть);
// o добавить к каждому элементу вектора сумму всех чисел из
// заданного интервала этого же вектора (не числовой оси, а
// вектора);
// o заменить все числа, модуль которых есть четное число, на
// разность максимального и минимального элемента этого
// вектора;
// o удалить из последовательности все равные по модулю числа,
// кроме первого из них.

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include <sstream>
#include <set>


int main(){
	try{
    setlocale(LC_ALL, ".1251");
	std::vector <int32_t> numbers;
	int32_t num;
	std::cout << "Вводите числа в контейнер. Для прекращения введите букву\n";
	while (std::cin >> num) {
		numbers.push_back(num);
	}

	//o суммa чисел;
	int32_t sum = std::accumulate(numbers.begin(), numbers.end(), 0);
	std::cout << "Сумма чисел в контейнере: " << sum << '\n';

	// o общее количество чисел;
	int32_t count = numbers.size();
	std::cout << "Общее количество чисел: " << count << '\n';

	// o количество чисел, равных заданному;
	int32_t value = 0;
	std::cout <<"Введите число для подсчета: ";
	std::cin.clear();
	std::cin.ignore();
	std::cin >> value;
	std::cout << "Количество чисел равных " << value <<" : " <<std::count(numbers.begin(), numbers.end(), value) << '\n';

	// o количество чисел, удовлетворяющих условию, например,
    // «больше, чем n»;
	int32_t compNum = 0;
	std::cout << "Число для сравнения: ";
	std::cin.clear();
	std::cin.ignore();
	std::cin >> compNum;
	std::cout << "Количество чисел больших, чем " << compNum << " : " << std::count_if(numbers.begin(), numbers.end(), [compNum](int32_t testNum) { return testNum > compNum; }) << '\n';

	// o заменить все нули средним арифметическим (взять целую
	// часть);
	std::cout << "Контейнер  в котором все нули заменены на среднее арифметическое: ";
	int32_t average = std::floor(double(sum / count));
	std::replace_if(numbers.begin(), numbers.end(), [](int32_t testNum) { return testNum == 0; }, average);
	for (auto& num : numbers) {
		std::cout << num << ' ';
	}

	// o добавить к каждому элементу вектора сумму всех чисел из
	// заданного интервала этого же вектора (не числовой оси, а
	// вектора);

	size_t start = 0;
	size_t end = 0;

	std::cout << "\nВведите диапозон чисел(индексы): ";
	std::cin.clear();
	std::cin.ignore();
	std::cin >> start >> end;
    if (start > end)
    {
        std::swap(start, end);
    }

	if(start < 0 || end > count)
    {
        throw std::invalid_argument("Значение от 0 до конца контейнера");
	}
    int32_t sumInRange = std::accumulate(numbers.begin() + start, numbers.begin() + end, 0);
	std::cout << "\nКонтейнер в котором к каждому элементу добавлена сумма всех чисел из заданного диапозона: ";
	for (auto& num : numbers) {
		std::cout << num + sumInRange << ' ';
	}
	
	// заменить все числа, модуль которых есть четное число, на
	// разность максимального и минимального элемента этого
	// вектора;

	int32_t minNum = numbers[0];
	int32_t maxNum = numbers[0];
	for (auto& num : numbers) {
		if(num > maxNum){
			maxNum = num;
		}
	}

	for (auto& num : numbers) {
		if(num < minNum){
			minNum = num;
		}
	}
	 
	std::cout << "\nКонтейнер где элементы, модуль которых четный, заменены на разность максимального и минимального элементов: ";
	int32_t temp  = maxNum - minNum;
	for (auto& num : numbers) {
		if(abs(num) % 2 == 0)
		{
			num = temp;
		}
		std::cout << num << ' ';
	}

	// o удалить из последовательности все равные по модулю числа,
	// кроме первого из них.	

	std::set<int32_t> uniqueModules;
        std::vector<int32_t> uniqueNumbers;

        for (int32_t num : numbers) {
          int module = std::abs(num);
          if (uniqueModules.find(module) == uniqueModules.end()) {
               uniqueModules.insert(module);
               uniqueNumbers.push_back(num); 
        }
    }

	std::cout << "\nПоследовательность, после удаления равных по модулю чисел: ";
	for(auto& num: uniqueNumbers)
	{
		std::cout << num << "  ";
	}
	std::cout << std::endl;
	}

	catch(std::invalid_argument e)
	{
		std::cout << e.what() <<'\n';
	}
	catch(std::out_of_range e)
	{
		std::cout << e.what() <<'\n';
	}

	catch(std::runtime_error e)
	{
		std::cout << e.what() <<'\n';
	}
	return 0;
}
