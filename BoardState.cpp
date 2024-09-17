//
// Created by Bánfalvi Katalin on 2024. 09. 07..
//

#include "BoardState.h"
#include <stdexcept>

void BoardState::move(const unsigned char choice) {
    unsigned char idx=choiceToIdx(choice);
    BoardState& board=*this;

    if (board[idx]==0) [[unlikely]]
        throw std::invalid_argument("Must choose a non 0 field!");

    auto stops = [](BoardState b, size_t idx){ //could be capture by reference
        idx%=14;
        if (idx==3 || idx==10 || b[idx]==1) [[unlikely]]
            return true;
        else [[likely]]
            return false;
    };
    do{
        for(unsigned char& hand=board[idx];hand > 0;--hand) {
            board[++idx]++;
        }
    }while(!stops(board, idx));
    firstPlayersTurn=!firstPlayersTurn;
}

unsigned char &BoardState::operator[](const unsigned char idx) {
    return array[idx%14];
}

unsigned char BoardState::choiceToIdx(const unsigned char choice) const {
    return choiceToIdx(choice, firstPlayersTurn);
}
std::ostream& operator<<(std::ostream& os,const BoardState& board){
    for (unsigned char i : board.array)
        std::cout<<i<<" ";
    std::cout<<std::endl;
    return os;
}

std::vector<unsigned char> BoardState::getValidChoices() const {
    return getValidChoices(firstPlayersTurn);
}

unsigned char BoardState::choiceToIdx(const unsigned char choice, const bool isFirstPlayer) {

    if (choice>6) [[unlikely]]
        throw std::invalid_argument("Must be between 1 and 6!");

    unsigned char result=choice;
    if (choice<=3)
        --result;

    if (!isFirstPlayer)
        result+=7;

    return result;
}

std::array<unsigned char, 6> BoardState::getMySide() const {
    return getSide(firstPlayersTurn);
}

std::array<unsigned char, 6> BoardState::getOpponentSide() const {
    return getSide(!firstPlayersTurn);
}

std::array<unsigned char, 6> BoardState::getSide(const bool isFirstPlayer) const {
    std::array<unsigned char, 6> result{};
    for (unsigned char i=1;i<=6;++i)
        result[i-1]=(array[choiceToIdx(i,isFirstPlayer)]);
    return result;
}

unsigned char BoardState::getMyTrash() const {
   unsigned char idx;
    if (firstPlayersTurn)
        idx=3;
    else
        idx=10;
    return array[idx];
}

unsigned char BoardState::getOpponentsTrash() const {
    unsigned char idx;
    if (!firstPlayersTurn)
        idx=3;
    else
        idx=10;
    return array[idx];}

std::vector<unsigned char> BoardState::getValidChoices(const bool forFirstPlayer) const {
    std::vector<unsigned char> result(6);
    unsigned char choice=1;
    unsigned char idx=0;
    for(const unsigned char& hole : getSide(forFirstPlayer)){
        if (hole!=0) {
            result[idx++]=choice;
        }
        ++choice;
    }
    result.resize(idx);
    return result;
}

unsigned char BoardState::getNumChoices(const bool forFirstPlayer) const {
    unsigned char result=0;
    for (const unsigned char& hole : getSide(forFirstPlayer)){
        if (hole!=0)
            ++result;
    }
    return result;
}

unsigned char BoardState::getNumChoices() const {
    return getNumChoices(firstPlayersTurn);
}

BoardState BoardState::testMove(const unsigned char choice) const {
    BoardState result=*this;
    unsigned char idx=choiceToIdx(choice);

    if (result[idx]==0) [[unlikely]]
                throw std::invalid_argument("Must choose a non 0 field!");

    auto stops = [](BoardState b, size_t idx){ //could be capture by reference
        idx%=14;
        if (idx==3 || idx==10 || b[idx]==1) [[unlikely]]
            return true;
        else [[likely]]
            return false;
    };
    do{
        for(unsigned char& hand=result[idx];hand > 0;--hand) {
            result[++idx]++;
        }
    }while(!stops(result, idx));
    return result;
}
