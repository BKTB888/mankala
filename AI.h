//
// Created by Bánfalvi Katalin on 2024. 09. 07..
//

#ifndef MANKALA5_AI_H
#define MANKALA5_AI_H
#include "BoardState.h"
#include <random>
#include <utility>



typedef std::function<unsigned char (const BoardState&)> AI_logic;
typedef std::function<float(const BoardState&)> BoardEval_logic;

class AI{
    const AI_logic function;
    BoardState* board{};
public:
    explicit AI(AI_logic&& function) : function(std::move(function)){}
    void setBoard(BoardState* _board);
    void makeMove();
};
AI create_AI(BoardEval_logic&& evaluate);

extern AI randy, randy2;
#endif //MANKALA5_AI_H
