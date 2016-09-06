//
//  Player.hpp
//  TicTacToeCPP
//
//  Created by Dimitar Dimov on 9/6/16.//
//

#pragma once

#include <string>
#include "Board.hpp"

namespace TicTacToe {
    
    class Player {
        
    public:
        Player(Board *_board);
        
        void getNameAndSymbol();
        void makeTurn();
        
        char getSymbol() { return _symbol; }
        std::string getName() { return _name; }
    private:
        Board *_board;
        char _symbol;
        std::string _name;
        
        int _getInput(char axis);
    };
}