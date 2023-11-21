#include <iostream>
#include <fstream>
#include "student_db.h"

using namespace std;

Student * create_student_db(int num_students){
    Student *array = new Student[num_students];
    return array;
}

void populate_student_db_info(Student *studentArray, int num_students, ifstream &infile){
    // for each student in infile, "cin" their information
    for (int i = 0; i < num_students; i++)
    {
        infile >> studentArray[i].id;
        infile >> studentArray[i].firstname;
        infile >> studentArray[i].lastname;
        infile >> studentArray[i].major;
        infile >> studentArray[i].gpa;
    }
}

void find_student_name(Student *studentArray, int num_students, ofstream &outfile){
    string searchName;
    cout << "Enter the name you wish to find: ";
    cin >> searchName;
    for(int i = 0; i < num_students; ++i){
        if(searchName == studentArray[i].lastname){
            outfile << "ID: " << studentArray[i].id << endl;
            outfile << "First Name: " << studentArray[i].firstname << endl;
            outfile << "Last Name: " << studentArray[i].lastname << endl;
            outfile << "Major: " << studentArray[i].major << endl;
            outfile << "GPA: " << studentArray[i].gpa << endl;
        }
    }
}

void print_to_output_file(Student *studentArray, int num_students, ofstream &outfile){
    for(int i = 0; i < num_students; ++i){
        if(studentArray[i].gpa >= 3.50){
            outfile << "ID: " << studentArray[i].id << endl;
            outfile << "First Name: " << studentArray[i].firstname << endl;
            outfile << "Last Name: " << studentArray[i].lastname << endl;
            outfile << "Major: " << studentArray[i].major << endl;
            outfile << "GPA: " << studentArray[i].gpa << endl;
        }
    }
}

void sort_student_db_info(Student *studentArray, int num_students, ofstream &outfile){
    bool isSorted = false;
    int tempid, tempgpa;
    cout << "Number of students: " << num_students << endl;
    string tempfirstname, templastname, tempmajor;
    while(!isSorted){
        isSorted = true;
        for(int i = 1; i < num_students; i++){
            if(studentArray[i].id < studentArray[i-1].id){
                isSorted = false;
                tempid = studentArray[i].id;
                tempfirstname = studentArray[i].firstname;
                templastname = studentArray[i].lastname;
                tempmajor = studentArray[i].major;
                tempgpa = studentArray[i].gpa;

                studentArray[i].id = studentArray[i-1].id;
                studentArray[i].firstname = studentArray[i-1].firstname;
                studentArray[i].lastname = studentArray[i-1].lastname;
                studentArray[i].major = studentArray[i-1].major;
                studentArray[i].gpa = studentArray[i-1].gpa;

                studentArray[i-1].id = tempid;
                studentArray[i-1].firstname = tempfirstname;
                studentArray[i-1].lastname = templastname;
                studentArray[i-1].major = tempmajor;
                studentArray[i-1].gpa = tempgpa;
            }
        }
    }
    for(int i = 0; i < num_students; ++i){
        outfile << "ID: " << studentArray[i].id << endl;
        outfile << "First Name: " << studentArray[i].firstname << endl;
        outfile << "Last Name: " << studentArray[i].lastname << endl;
        outfile << "Major: " << studentArray[i].major << endl;
        outfile << "GPA: " << studentArray[i].gpa << endl;
    }
}

void delete_student_db_info(Student *&studentArray){
    delete [] studentArray;
}