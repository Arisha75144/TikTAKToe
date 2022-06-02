//
// Created by Dmitry Morozov on 28/5/22.
//

#ifndef TIKTAKTOE_GAME_HPP
#define TIKTAKTOE_GAME_HPP


class Game {
public:
    Game (); // default constructor
    ~Game (); // destructor


    void Start (); // Game entry point
private:
    bool is_playing_; // flag to check if the game is still running

    std::string InputUserName (); // function to get user name

};


#endif //TIKTAKTOE_GAME_HPP
