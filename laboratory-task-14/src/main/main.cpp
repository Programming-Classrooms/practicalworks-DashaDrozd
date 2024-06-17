#include "../func/Student.h"
#include "../func/Professor.h"


void addStudent(Person** arr, size_t& counter, size_t size)
{
	if (counter > size)
	{
		throw std::out_of_range("A lot of persons\n");
	}
	char buf[1000];
	int32_t course = 0;
	int32_t group = 0;
	std:: cout << "Enter full name of student: ";
	std::cin.ignore();
	std::cin.getline(buf,1000);
	std:: cout << "\nEnter course of student: ";
	std::cin >> course;
	std:: cout << "\nEnter group of student: ";
	std::cin >> group;
	arr[counter++] = new Student(buf, course, group);
}

void addProfessor(Person** arr, size_t& counter, size_t size)
{
	if (counter > size)
	{
		throw std::out_of_range("A lot of persons\n");
	}

	char buf[1000];
	char dep[1000];
	std:: cout << "Enter full name of Professor: ";
	std::cin.ignore();
	std::cin.getline(buf,1000);
	std:: cout << "\nEnter department of Professor: ";
	std::cin.ignore();
	std::cin.getline(dep,1000);
	arr[counter++] = new Professor(buf, dep);
}


 void listOfStudents(Person** arr, size_t counter)
 {
	 bool isStudent = false;
	 for (size_t i = 0; i < counter; ++i)
	 {
		 if (dynamic_cast<Student*>(arr[i]))
		 {
			 isStudent = true;
			 arr[i]->print(std::cout);
		 }
	 }

	 if (!isStudent)
	 {
		 std::cout << "Students aren't found! ";
	 }
	
 }

 void listOfProfessors(Person** arr, size_t counter)
 {
	 bool isProfessor = false;
	 for (size_t i = 0; i < counter; ++i)
	 {
		 if (dynamic_cast<Professor*>(arr[i]))
		 {
			 isProfessor = true;
			 arr[i]->print(std::cout);
		 }
	 }

	 if (!isProfessor)
	 {
		 std::cout << "Professors aren't found! ";
	 }

 }

 int main()
 {
	 try {
		 size_t size = 0;
		 while (size <= 0)
		 {
			std::cout << "How much persons you want to enter?\n ";
			std::cin >> size;

		 }
		 Person** arr = new Person * [size];
		 size_t counter = 0;
		 int32_t operation = 0;

		 while (operation != 5 && size >  counter) {
			std::cout<<"#####################################################\n";
			std::cout << "What do you want to do?\n 1.Enter a Student.\n 2.Enter a Professor\n 3.Display a list of students.\n 4.Display a list of professors.\n 5.End of work.\n";
			std::cout << "Enter number of operation: \n";
			std::cin >> operation;


			 switch (operation)
			 {
			 case 1:
				 addStudent(arr, counter, size);
				 break;

			 case 2:
				 addProfessor(arr, counter, size);
				 break;

			 case 3:
			     std::cout<<"#####################################################\n";
				 std::cout << "Students: \n";
				 listOfStudents(arr, counter);
				 
				 break;
			 case 4:
			 	 std::cout<<"#####################################################\n";
				 std::cout << "Professors: \n";
				 listOfProfessors(arr, counter);
				 break;

			 case 5:
				 break;

			 default:
				 std::cout << "ENTER 1-5!!!!!!!!!";
				 return 1;

				 
			 }

			 if (counter == size)
				 {
					 listOfProfessors(arr, size);
					 listOfStudents(arr, size);
					 std::cout<<"#####################################################\n";
				 }
		 }

			for (size_t i = 0; i < counter; ++i) {
				 delete arr[i];
			 }
			 delete[] arr;

	 }

	catch (std::out_of_range e)
	{
		std::cout << e.what();
	}
}