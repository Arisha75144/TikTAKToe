//
// Created by Dmitry Morozov on 10/6/22.
//
#include <iostream>
#include "Board.hpp"


Board::Board () {
    std::cout << "class Board constructor is running" << std::endl;

}


void Board::setPosition (int position, char mark) {
    std::cout << "SetPosition" << std::endl;
    positions_[position] = mark;
}

//FIXME: Check scope resolution operator for std::string
//TODO: Change var names to be more descriptive ( str, str1 )
//TODO: Test code before submitting to git hub!!!
void Board::PrintBoard () { // Ok! Everything is correct

    string str= " ---|-----|--- ";
    string str1="    |     | ";
    
    
    
    std::cout << "    |     |   " << std::endl; //Better way to use std::endl.
    std::cout <<" " <<positions_[1] << "  | " << positions_[2] << "   | " << positions_[3] << std::endl;
    std::cout << str<< std::endl;
    std::cout << " " << positions_[4] << "  |" << positions_[5] << "    |" << positions_[6] << std::endl;
    std::cout << str1<< std::endl;
    std::cout << str<< std::endl;
    std::cout << " " << positions_[7] << "  | " << positions_[8] << "   | " << positions_[9] << std::endl;
    std::cout << str1<< std::endl;
    


}


void Board::ClearBoard () { // Fill positions with empty characters
//    
    for (int i = 0; i < positions_.size (); i++) {
        positions_[i] = ' ';
    }
//    positions_.fill (' ');
}

//TODO: Implement method

bool Board::isFull () {
    for (const auto &i: positions_) {

        if (i != ' ') { //FIXME: Check the logic!
            return true;
        }
    }

    return false;


//    return std::any_of (positions_.begin (), positions_.end (), [] (char c) { return c == ' '; });
}



//Correct!
bool Board::isFree (int position) {
    return positions_[position] == ' ';
}
