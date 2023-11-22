#ifndef ADVENTURER_H
#define ADVENTURER_H 

#include <vector>
#include <iostream>

using namespace std;

class Adventurer {
private:
    int num_arrows;
    int num_lives;
public:
    Adventurer();
    ~Adventurer();

    void setup_cave();

    void set_num_arrows(const int);
    void set_num_lives(const int);
    int get_num_arrows() const;
    int get_num_lives() const;

};



#endif