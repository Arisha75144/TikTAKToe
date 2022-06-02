//
// Created by Dmitry Morozov on 2/6/22.
//

#ifndef TIKTAKTOE_PLAYER_HPP
#define TIKTAKTOE_PLAYER_HPP

#include <iostream>


class Player {
public :
    Player (); // default constructor
    Player (std::string name, bool is_human); // constructor with parameters

    ~Player (); // destructor
    void setName (std::string); // set player name
    std::string getName (); // get player name
    void setScore (int); // set player score
    int getScore (); // get player score
private:
    std::string Name_;
    int Score_;
    bool is_human_;

};


#endif //TIKTAKTOE_PLAYER_HPP
