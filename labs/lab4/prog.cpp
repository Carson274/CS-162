#include <iostream>
#include <fstream>
#include "student_db.h"

using namespace std;

int main()
{
    ifstream infile;
    infile.open("input.txt");

    if (!infile.is_open())
    {
        cout << "Error opening file..." << endl;
        return 1;
    }

    int num_students = 0;

    // "cin" num_students
    infile >> num_students;

    Student *studentArray = create_student_db(num_students);

    populate_student_db_info(studentArray, num_students, infile);

    int choice;
    cout << "Pick one: " << endl;
    cout << "1. Search students by last name." << endl;
    cout << "2. Print all students that have GPA >= 3.50." << endl;
    cout << "3. Sort students by ID number." << endl;
    cout << "Choice: ";
    cin >> choice;

    ofstream outfile;
    outfile.open("output.txt");

    if(!outfile.is_open()){
        cout << "Error opening output file..." << endl;
        return 1;
    }

    if(choice == 3){
        sort_student_db_info(studentArray, num_students, outfile);
    }
    else if(choice == 1){
        find_student_name(studentArray, num_students, outfile);
    }
    else{
        print_to_output_file(studentArray, num_students, outfile);
    }

    delete_student_db_info(studentArray);

    return 0;

}