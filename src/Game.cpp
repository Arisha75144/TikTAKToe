#include <iostream>
#include <stdlib.h>
#include "Game.hpp"
#include "player.hpp"


Game::Game () {

    std::cout << "class Game constructor is running" << std::endl;
    srand (time (nullptr));

}

Game::~Game () {
    std::cout << "class Game destructor is running" << std::endl;

}

//Point 2. Main Game loop. Initialize the game.
void Game::Start () {
    std::cout << "Game started" << std::endl;

    //Point 3. Create two players. ( Ask for type of player and name of player)


    HumanPlayer player1 (InputUserName ());
    players_.push_back (&player1); // Put player1 address in vector

    HumanPlayer player2 (InputUserName ());
    players_.push_back (&player2);

    //Point 4. Set first player.
    current_player_ = getFirstPlayer ();

    players_[current_player_]->setMark ('X');
    players_[(current_player_ + 1) % 2]->setMark ('O');


    do {
        Loop ();
    } while (IsPlayAgain ());

}


Player &Game::getCurrentPlayer () {
    return *players_[current_player_];
}

std::string Game::InputUserName () {
    std::cout << "Enter Player name : ";
    std::string name;
    std::cin >> name;
    return name;
}


bool Game::IsPlayAgain () {
    std::cout << "Do you want to play again? (y/n)";
    char answer;
    std::cin >> answer;
    if (answer == 'y') {
        return true;
    } else {
        return false;
    }
}

//Point 5.1. Main game logic loop.
void Game::Loop () {
    bool game_active = true;

    while (game_active) {

        board_.PrintBoard ();

        std::cout << "Player " << getCurrentPlayer ().getName () << " turn" << std::endl;

        int next_move = getCurrentPlayer ().engageMove (board_);

        if (!board_.setPosition (next_move, getCurrentPlayer ().getMark ())) {
            std::cout << "Invalid move" << std::endl;
            continue;
        }

        //Point 5.5. Check if the game is over.
        if (board_.isWinner ()) {
            std::cout << "Player " << getCurrentPlayer ().getName () << " won!" << std::endl;
            board_.PrintBoard ();
            getCurrentPlayer ().addWin (); // Add one win to the player score_
            game_active = false;
        } else if (board_.isFull ()) {
            std::cout << "Draw!" << std::endl;
            game_active = false;
        } else {
            setNextPlayer ();
        }
    }
}


bool Game::is_playing () {
    std::cout << "is_playing" << std::endl;
    return true;
}


int Game::getFirstPlayer () {
    return rand () % 2; // Native C function to generate random number
}


void Game::setNextPlayer () { //current_player ( 0 or 1 )
    current_player_ = 1 - current_player_;

}
