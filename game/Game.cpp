//
//  Game.cpp
//  TicTacToeCPP
//
//  Created by Dimitar Dimov on 8/30/16.
//

#include "Game.hpp"

#include <iostream>

namespace TicTacToe {
    
    Game::Game() : _running(true), _currentPlayer(1) {
        _board = new Board();
        _playerOne = new Player(_board);
        _playerTwo = new Player(_board);
    }
    
    Game::~Game() {
        delete _board;
        delete _playerOne;
        delete _playerTwo;
    }
    
    void Game::run() {
        _playerOne->getNameAndSymbol();
        _playerTwo->getNameAndSymbol();
        while(_running) {
            _board->printBoard();
            
            switch(_currentPlayer) {
                case 1:
                    _handleTurn(_playerOne);
                    _currentPlayer = 2;
                    break;
                case 2:
                    _handleTurn(_playerTwo);
                    _currentPlayer = 1;
                    break;
            }
            
        }
    }
    
    void Game::_handleTurn(Player *player) {
        player->makeTurn();
        if(_board->checkForVictory(player->getSymbol())) {
            std::cout << player->getName() << " wins!" << std::endl;
            _running = false;
        }
        
        if(_board->checkForTie()) {
            std::cout << "It's a tie!" << std::endl;
            _running = false;
        }
    }
}