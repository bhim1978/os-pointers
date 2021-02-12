# os-pointers
C / C++ Pointers

The purpose of this program is to take in some student information, including their ID, name, and grades to
produce their grade average.

In order to run this program, please compile the program with "g++ -std=c++11 -o pointers pointers.cpp" and
then run with "./pointers" in the terminal.

The program is able to take in a student ID that is no more than 9 digits, names no more than 128 characters
long, number of assignments of less than 134,217,728, and grade scores no more than 1000.00. The code is able
to handle these length and number constraints. It will throw an error and ask for input again in the case
that the user input does not follow those guidelines.
