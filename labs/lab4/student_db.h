#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
    int id;
    string firstname;
    string lastname;
    string major;
    double gpa;
};

Student * create_student_db(int);

void populate_student_db_info(Student *, int, ifstream &);

void find_student_name(Student *, int, ofstream &);

void print_to_output_file(Student *, int, ofstream &);

void sort_student_db_info(Student *, int, ofstream &);

void delete_student_db_info(Student *&);