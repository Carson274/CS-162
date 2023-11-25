#ifndef WUMPUS_H
#define WUMPUS_H 

#include "event.h"

class Wumpus : public Event {
    private:
        bool is_alive;
    public:
        Wumpus();
        ~Wumpus();

        void set_position(const int, const int, const int);
        void set_alive(const bool);
        int* get_position();
        bool get_alive() const;
        char get_icon() override;
        string get_name() override;
        string get_encounter_message() override;
        string get_percept_message() override;

        void encounter();
        void move();
};

#endif