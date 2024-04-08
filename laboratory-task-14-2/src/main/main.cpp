#include "../func/Student2.h"
#include "../func/Student1Session.h"
#include "../func/Student2Session.h"

double averageScoreAfterFirstSession(Student1Session* students, int32_t numStudents, int32_t group) {
    int32_t totalMarks = 0;
    int32_t numGroupStudents = 0;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].getGroup() == group) {
            totalMarks += students[i].AverageMark();
            numGroupStudents++;
        }
    }

    return static_cast<double>(totalMarks) / numGroupStudents;
}

double averageScoreAfterSecondSession(Student2Session* students, int32_t numStudents, int32_t group) {
    int32_t totalMarks = 0;
    int32_t numGroupStudents = 0;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].getGroup() == group) {
            totalMarks += students[i].AverageMark();
            numGroupStudents++;
        }
    }

    return static_cast<double>(totalMarks) / numGroupStudents;
}

int main() {
	int32_t arr1[4] ={4, 5, 3, 4};
	int32_t arr2[4] ={4, 5, 3, 4};
	int32_t arr3[4] = {3, 4, 4, 5};

    Student1Session studentsFirstSession [3] = {
        {"Dima", 2, 1, 1001, arr1},
        {"Danik", 2, 2, 1002, arr2},
        {"Vanya", 3, 1, 1003, arr3}
    };

	int32_t arr4[5] = {4, 5, 3, 4, 5};
	int32_t arr5[5] = {5, 4, 5, 4, 5};
	int32_t arr6[5] = {3, 4, 4, 5, 4};
   
    Student2Session studentsSecondSession[3] = {
        {"Dima", 2, 1, 1001, arr1, arr4},
        {"Danik", 2, 2, 1002, arr2, arr5},
        {"Vanya", 3, 1, 1003, arr3, arr6}
    };

    int32_t numStudentsFirstSession = 3; 
    int32_t numStudentsSecondSession = 3; 

    int32_t group = 1; 
    double avgScoreFirstSession = averageScoreAfterFirstSession(studentsFirstSession, numStudentsFirstSession, group);
    std::cout << "Average score in group " << group << " after the first session: " << avgScoreFirstSession << '\n';
    double avgScoreSecondSession = averageScoreAfterSecondSession(studentsSecondSession, numStudentsSecondSession, group);
    std::cout << "Average score in group " << group << " after the second session: " << avgScoreSecondSession << '\n';

    return 0;
}
