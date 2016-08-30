//
//  Game.cpp
//  TicTacToeCPP
//
//  Created by Dimitar Dimov on 8/30/16.
//

#include "Game.hpp"

#include <iostream>

namespace TicTacToe {
    
    Game::Game() : _running(true) {
        _resetGame();
    }
    
    void Game::run() {
        while(_running) {
            _printBoard();
            std::cout << "Current player: " << _currentPlayer << std::endl;
            
            int x = _getInput('X');
            int y = _getInput('Y');
            
            if(!_placeMarker(x, y)) {
                std::cout << "Cant place your marker there!\n";
            } else {
                if (_checkForVictory()) {
                    _printBoard();
                    std::cout << "The game is over! Player " << _currentPlayer << " has won!\n";
                    _running = false;
                } else if (_checkForTie()) {
                    _printBoard();
                    std::cout << "It's a tie game!\n";
                    _running = false;
                }
                
                if(_currentPlayer == _playerOneSymbol) {
                    _currentPlayer = _playerTwoSymbol;
                } else {
                    _currentPlayer = _playerOneSymbol;
                }
            }
        }
    }
    
    bool Game::_placeMarker(int x, int y) {
        if (_board[y][x] != ' ') {
            return false;
        }
        
        _board[y][x] = _currentPlayer;
        return true;
    }
    
    bool Game::_checkForVictory() {
        for (int i = 0; i < 3; i++) {
            if ((_board[i][0] == _currentPlayer) && (_board[i][0] == _board[i][1]) && (_board[i][1] == _board[i][2])) {
                return true;
            }
        }
        
        for (int i = 0; i < 3; i++) {
            if ((_board[0][i] == _currentPlayer) && (_board[0][i] == _board[1][i]) && (_board[1][i] == _board[2][i])) {
                return true;
            }
        }

        if ((_board[0][0] == _currentPlayer) && (_board[0][0] == _board[1][1]) && (_board[1][1] == _board[2][2])) {
            return true;
        }
        
        if ((_board[2][0] == _currentPlayer) && (_board[2][0] == _board[1][1]) && (_board[1][1] == _board[0][2])) {
            return true;
        }
        
        return false;
    }
    
    bool Game::_checkForTie() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(_board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
    
    int Game::_getInput(char axis) {
        int input;
        bool isValudInput = false;
        
        while(!isValudInput) {
            std::cout << "Enter " << axis << " coordinate ";
            std::cin >> input;
            
            if(input < 1 || input > 3) {
                std::cout << "Invalid input!\n";
            } else {
                isValudInput = true;
            }
        }
        
        return input - 1;
    }
    
    void Game::_printBoard() {
        std::cout << "---------\n";
        std::cout << "|\\|1|2|3|\n";
        for(int x = 0; x < 3; x++) {
            std::cout << "---------\n" << "|" << x + 1 << "|";
            for(int y = 0; y < 3; y ++) {
                std::cout << _board[x][y] << "|";
            }
            std::cout << "\n";
        }
        std::cout << "---------\n";
    }
    
    void Game::_resetGame() {
        std::cout << "Initializing new game...\n";
        
        _currentPlayer = _playerOneSymbol;
        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                _board[x][y] = ' ';
            }
        }
    }
}