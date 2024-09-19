//
// Created by Bánfalvi Katalin on 2024. 09. 13..
//

#ifndef MANKALA5_MANKALA_H
#define MANKALA5_MANKALA_H

#include <chrono>
#include <utility>
#include "AI.h"

enum class Result{
    player1,
    player2
};

class Mankala {
    AI player1, player2;
    BoardState board;

public:
    Mankala(AI player1, AI player2) : player1(std::move(player1)), player2(std::move(player2)){
        this->player1.setBoard(&board);
        this->player2.setBoard(&board);
    }
    Result play();
    void makeStats(unsigned numOfPlays);

    Result playTest() {
        std::cout<<"No moves:"<<std::endl<<board<<std::endl;
        bool p1_won=false, p2_won=false;
        while(!p1_won and !p2_won){

            std::cout<<"player1 moved: ";
            player1.makeMove();
            std::cout<<board<<std::endl;

            std::cout<<"player2 moved: ";
            player2.makeMove();
            std::cout<<board<<std::endl;

            p1_won=board.getNumChoices(true)==0;
            p2_won=board.getNumChoices(false)==0;
        }
        board.reset();
        if (p1_won) {
            std::cout << "Player1 wins!";
            return Result::player1;
        }
        else {
            std::cout<<"Player2 wins!";
            return Result::player2;
        }
    }
};

void tester(Mankala& mankala, unsigned numOfGames);
#endif //MANKALA5_MANKALA_H
