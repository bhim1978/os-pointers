// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <cmath>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    student.f_name = new char[128];
    student.l_name = new char[128];

    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("Please enter the student's id number", 0, 999999999);

    std::cout << "Please enter the student's first name: ";
    std::cin.getline(student.f_name, 128);

    std::cout << "Please enter the student's last name: ";
    std::cin.getline(student.l_name, 128);

    student.n_assignments = promptInt("Please enter how many assignments were graded", 0, 134217728);
    std::cout << std::endl;

    // Call `CalculateStudentAverage(???, ???)
    calculateStudentAverage(&student, &average);

    // Output average
    std::cout << std::endl << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]" << std::endl;
    std::cout << "  Average grade: " << average << std::endl;

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    int userInput;

    userInput = 0;

    std::cout << message << ": ";
    std::cin >> userInput;
    std::cin.ignore();

    while (userInput > max || userInput < min)
    {
    std::cout << "Sorry, I cannot understand your answer" << std::endl << message << ": ";
    std::cin >> userInput;
    std::cin.ignore();
    }

    return userInput;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double userInput;
    
    userInput = 0;

    std::cout << message << ": ";
    std::cin >> userInput;
    std::cin.ignore();

    while (userInput > max || userInput < min)
    {
    std::cout << "Sorry, I cannot understand your answer" << std::endl << message << ": ";
    std::cin >> userInput;
    std::cin.ignore();
    }

    return userInput;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg) // pass in the grades and number of assignments
{
    Student *studentPointer = (Student*) object;
    // Code to calculate and store average grade
    double sum;
    double average;

    sum = 0.0;
    average = 0.0;

    studentPointer->grades = new double[studentPointer->n_assignments];

    for (int i = 0; i < studentPointer->n_assignments; i++)
    {
        studentPointer->grades[i] = promptDouble("Please enter grade for assignment " + std::to_string(i), 0, 1000.0);
    }

    for (int i = 0; i < studentPointer->n_assignments; i++)
    {
        sum = sum + studentPointer->grades[i];
    }

    average = (sum/studentPointer->n_assignments);
    average = std::ceil(average*10.0)/10.0;

    *avg = average;
    // NOTE: only output one decimal after for the average grade
}
