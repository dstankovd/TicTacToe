//
//  Game.hpp
//  TicTacToeCPP
//
//  Created by Dimitar Dimov on 8/30/16.
//

#pragma once

namespace TicTacToe {
    
    class Game {
        
    public:
        Game();
        
        void run();

    private:
        char _board[3][3];
        
        char _playerOneSymbol = 'X';
        char _playerTwoSymbol = 'O';
        char _currentPlayer;
        
        bool _running = false;
        
        // validates marker can be placed and places it
        bool _placeMarker(int x, int y);
        
        // checks if currentPlayer has won
        bool _checkForVictory();
        // checks if there are free cells
        bool _checkForTie();
        
        // gets player input
        int _getInput(char axis);
        
        // clears markers on board and set currentPlayer to first player
        void _resetGame();
        
        // outputs the board
        void _printBoard();
    };
    
}