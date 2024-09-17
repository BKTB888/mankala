//
// Created by Bánfalvi Katalin on 2024. 09. 13..
//

#ifndef MANKALA5_MANKALA_H
#define MANKALA5_MANKALA_H


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
};


#endif //MANKALA5_MANKALA_H
