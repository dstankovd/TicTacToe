//
//  Board.cpp
//  TicTacToeCPP
//
//  Created by Dimitar Dimov on 9/6/16.
//  Copyright © 2016 Z Point. All rights reserved.
//

#include "Board.hpp"

#include <iostream>

namespace TicTacToe {
    
    Board::Board() {
        clearBoard();
    }
    
    void Board::clearBoard() {
        for(int i = 0; i < Board::BOARD_HEIGHT; i++) {
            for(int j = 0; j < Board::BOARD_WIDTH; j++) {
                _board[i][j] = Board::WHITE_SPACE_SYMBOL;
            }
        }
    }
    
    void Board::printBoard() {
        std::cout << "---------" << std::endl;
        std::cout << "|\\|1|2|3|" << std::endl;
        for(int x = 0; x < 3; x++) {
            std::cout << "---------" << std::endl;
            std::cout << "|" << x + 1 << "|";
            for(int y = 0; y < 3; y ++) {
                std::cout << _board[x][y] << "|";
            }
            std::cout << std::endl;
        }
        std::cout << "---------" << std::endl;
    }
    
    bool Board::positionValid(int x, int y) {
        return ((x >= 0 && x <= Board::BOARD_WIDTH) && (y >= 0 && y <= Board::BOARD_HEIGHT));
    }
    
    bool Board::positionOccupied(int x, int y) {
        return _board[x][y] != Board::WHITE_SPACE_SYMBOL;
    }
    
    void Board::placeMarker(int x, int y, char symbol) {
        _board[x][y] = symbol;
    }
    
    bool Board::checkForVictory(char currentSymbol) {
        for(int i = 0; i < 3; i++) {
            if((_board[i][0] == currentSymbol) && (_board[i][0] == _board[i][1]) && (_board[i][1] == _board[i][2])) {
                return true;
            }
        }
        
        for(int i = 0; i < 3; i++) {
            if((_board[0][i] == currentSymbol) && (_board[0][i] == _board[1][i]) && (_board[1][i] == _board[2][i])) {
                return true;
            }
        }
        
        if((_board[0][0] == currentSymbol) && (_board[0][0] == _board[1][1]) && (_board[1][1] == _board[2][2])) {
            return true;
        }
        
        if((_board[2][0] == currentSymbol) && (_board[2][0] == _board[1][1]) && (_board[1][1] == _board[0][2])) {
            return true;
        }
        
        return false;
    }
    
    bool Board::checkForTie() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(_board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

}