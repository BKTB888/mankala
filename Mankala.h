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
    Mankala(AI player1, AI player2);
    Result play();
    void makeStats(unsigned numOfPlays);
};


#endif //MANKALA5_MANKALA_H
