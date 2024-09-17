//
// Created by Bánfalvi Katalin on 2024. 09. 13..
//
#include "AI.h"
#include "Helper.h"


AI randy([](const BoardState& board) -> unsigned char{
    return Random::randomElement(board.getValidChoices());
});

AI randy2([](const BoardState& board) -> unsigned char{
    auto vec=board.getValidChoices();
    return Random::randomElement(std::span<unsigned char>(vec));
});

void AI::setBoard(BoardState* const _board) {
    board=_board;
}

void AI::makeMove() {
    const unsigned char choice=function(*board);
    ///std::cout<<choice<<std::endl;
    board->move(choice);
}

AI create_AI(BoardEval_logic&& evaluate){
    return AI( [evaluate(std::move(evaluate))] [[gnu::const]](const BoardState& board) -> unsigned char {
        const auto validChoices=board.getValidChoices();
        const unsigned char size=validChoices.size();
        std::vector<float> scores(size);

        unsigned char max=0;
        for (unsigned char i=0; i<size; ++i){
            scores[i]=evaluate(board.testMove(validChoices[i]));
            if (scores[i]>scores[max])
                max=i;
        }
        return validChoices[max];
    });
}