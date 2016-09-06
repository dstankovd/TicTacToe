//
//  Game.hpp
//  TicTacToeCPP
//
//  Created by Dimitar Dimov on 8/30/16.
//

#pragma once

#include "Player.hpp"
#include "Board.hpp"

namespace TicTacToe {

    class Game {
        
    public:
        Game();
        ~Game();
        
        void run();

    private:
        Player *_playerOne, *_playerTwo;
        Board *_board;
        int _currentPlayer;
        bool _running = false;
        
        void _handleTurn(Player *player);
    };
    
}