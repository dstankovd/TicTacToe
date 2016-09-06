//
//  Player.cpp
//  TicTacToeCPP
//
//  Created by Dimitar Dimov on 9/6/16.
//

#include "Player.hpp"

#include <iostream>

namespace TicTacToe {
    
    Player::Player(Board *board) {
        _board = board;
    }
    
    void Player::getNameAndSymbol() {
        std::cout << "Please enter your name: ";
        std::cin >> _name;
        
        std::cout << "Please enter your desired symbol: ";
        std::cin >> _symbol;
    }
    
    void Player::makeTurn() {
        std::cout << std::endl <<  "It's " << _name << "'s turn!" << std::endl;
        
        int x = _getInput('X');
        int y = _getInput('Y');
        
        while(!_board->positionValid(x, y) || _board->positionOccupied(x, y)) {
            std::cout << "Position was not valid!" << std::endl;
            x = _getInput('X');
            y = _getInput('Y');
        }
        
        _board->placeMarker(x, y, _symbol);
    }
    
    int Player::_getInput(char axis) {
        int input;
        std::cout << "Enter " << axis << " coordinate ";
        std::cin >> input;
        return input - 1;
    }
}