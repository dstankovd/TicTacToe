//
//  Board.hpp
//  TicTacToeCPP
//
//  Created by Dimitar Dimov on 9/6/16.
//

#pragma once

namespace TicTacToe {
    
    class Board {
    
    public:
        static const int BOARD_WIDTH = 3;
        static const int BOARD_HEIGHT = 3;
        static const char WHITE_SPACE_SYMBOL = ' ';
        
        Board();
        void clearBoard();
        void printBoard();
        bool positionValid(int x, int y);
        bool positionOccupied(int x, int y);
        void placeMarker(int x, int y, char symbol);
        bool checkForVictory(char currentSymbol);
        bool checkForTie();
        
    private:
        char _board[Board::BOARD_HEIGHT][Board::BOARD_WIDTH];
        
    };
    
}