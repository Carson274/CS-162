#ifndef ADVENTURER_H
#define ADVENTURER_H 

#include <vector>
#include <iostream>

using namespace std;

class Adventurer {
private:
    int num_arrows;
    int num_lives;
    int position[3];
    bool gold;
public:
    Adventurer();
    ~Adventurer();

    void setup_cave();

    void set_num_arrows(const int);
    void set_num_lives(const int);
    void set_position(const int, const int, const int);
    void set_gold(const bool);
    int get_num_arrows() const;
    int get_num_lives() const;
    int* get_position();
    bool get_gold() const;

};



#endif