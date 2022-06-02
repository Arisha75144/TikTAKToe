//
// Created by Dmitry Morozov on 2/6/22.
//

#include "Player.hpp"


Player::Player (std::string name = "") {
    this->Name_ = name;
    this->Score_ = 0;
    this->is_human_ = true;
}
