#include <iostream>

using namespace std;

struct student{
    string name;
    int id;
    float gpa;
};

int main(){

    student* s1 = new struct student;

    s1->gpa = 3.9;

    cout << "Student 1 GPA: " << s1->gpa << endl;

    return 0;
}