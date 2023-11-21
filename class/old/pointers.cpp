#include <iostream>

using namespace std;

void test_fun1(int val) {
    //some code here
}

void test_fun2(int* ptr) {
    //some code here
}

void test_fun3(int ** ptr) {
    //some code here
}

void test_fun4(int *** ptr) {
    //some code here
}

int main(){
    int x = 1;
    int *p1;
    p1 = &x;
    int **p2;
    p2 = &p1;

    cout << "x: " << x << endl;
    cout << "p1: " << *p1 << endl;
    cout << "p2: " << **p2 << endl;

    test_fun2(x);
    test_fun2(p1);
    test_fun2(*p2);

    cout << endl;

    cout << "&x (addr of x): " << &x << endl;
    cout << "p1: " << p1 << endl;
    cout << "*p2 (deref of p2 once): " << *p2 << endl;

    test_fun2(&x);
    test_fun2(p1);
    test_fun2(*p2);

    cout << endl;

    cout << "&p1 (addr of p1): " << &p1 << endl;
    cout << "p2: " << p2 << endl;

    test_fun3(&p1);
    test_fun3(p2);

    cout << endl;

    cout << "&p2 (addr of p2): " << &p2 << endl;

    //test_fun4(&p3);
    
    return 0;
}