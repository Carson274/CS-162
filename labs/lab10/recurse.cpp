#include <iostream>

using namespace std;

void print_spaces(int col) {
    for(int i = 0; i < col; ++i){
        cout << " ";
    }
    return;
}

void print_stars(int n) {
    for(int i = 0; i < n; ++i){
        cout << "* ";
    }
    cout << endl;
    return;
}

void pattern(int n, int col) {

    if(n == 2) {
        print_spaces(col);
        print_stars(1);
        print_spaces(col);
        print_stars(2);
        print_spaces(col + n);
        print_stars(1);
        return;
    }

    pattern(n / 2, col);

    print_spaces(col);
    print_stars(n);

    pattern(n / 2, col * n);
}

int main() {
    
    pattern(4, 1);

}