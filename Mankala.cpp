//
// Created by Bánfalvi Katalin on 2024. 09. 13..
//

#include "Mankala.h"
Mankala::Mankala(AI player1, AI player2) : player1(std::move(player1)), player2(std::move(player2)){
    this->player1.setBoard(&board);
    this->player2.setBoard(&board);
}
Result Mankala::play() {
    ///std::cout<<"No moves:"<<std::endl<<board<<std::endl;
    bool p1_won=false, p2_won=false;
    while(!p1_won and !p2_won){

        ///std::cout<<"player1 moved: ";
        player1.makeMove();
        ///std::cout<<board<<std::endl;

        ///std::cout<<"player2 moved: ";
        player2.makeMove();
        ///std::cout<<board<<std::endl;

        p1_won=board.getNumChoices(true)==0;
        p2_won=board.getNumChoices(false)==0;
    }
    board.reset();
    if (p1_won) {
        ///std::cout << "Player1 wins!";
        return Result::player1;
    }
    else {
        ///std::cout<<"Player2 wins!";
        return Result::player2;
    }
}

void Mankala::makeStats(const unsigned int numOfPlays) {
    std::vector<Result> results(numOfPlays);
    for (unsigned i=0;i<numOfPlays;++i)
        results[i]=this->play();
    unsigned p1_wins = std::count(results.begin(), results.end(), Result::player1),
             p2_wins = std::count(results.begin(), results.end(), Result::player2);

    std::cout<<"Player1 percentage: " << (double) p1_wins/numOfPlays << std::endl
             <<"Player2 percentage: " << (double) p2_wins/numOfPlays << std::endl;
}
