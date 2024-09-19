//
// Created by Bánfalvi Katalin on 2024. 09. 07..
//

#ifndef MANKALA5_BOARDSTATE_H
#define MANKALA5_BOARDSTATE_H
#include <iostream>
#include <vector>
#include <array>

class BoardState {
    std::array<unsigned char, 14> array;
    bool firstPlayersTurn; //0 is first 1 is second
public:
    constexpr BoardState() noexcept : array{6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6}, firstPlayersTurn(true){}
    constexpr void reset() noexcept {*this=BoardState();}
    [[nodiscard]] unsigned char choiceToIdx(unsigned char choice) const;
    [[gnu::const]][[nodiscard]] static unsigned char choiceToIdx(unsigned char choice, bool isFirstPlayer);
    [[nodiscard]] std::array<unsigned char, 6> getMySide() const;
    [[nodiscard]] std::array<unsigned char, 6> getOpponentSide() const;
    [[nodiscard]] std::array<unsigned char, 6> getSide(bool isFirstPlayer) const;
    [[nodiscard]] std::vector<unsigned char> getValidChoices() const;
    [[nodiscard]] std::vector<unsigned char> getValidChoices(bool forFirstPlayer) const;
    [[nodiscard]] unsigned char getNumChoices(bool forFirstPlayer) const;
    void endTurn();
    void move(unsigned char choice);
    [[nodiscard]] unsigned char getNumChoices() const;
    [[nodiscard]] unsigned char getMyTrash() const;
    [[nodiscard]] unsigned char getOpponentsTrash() const;
    void turn(unsigned char choice);
    [[nodiscard]] BoardState testMove(unsigned char choice) const;


    friend std::ostream& operator<<(std::ostream& os,const BoardState& board);
};
std::ostream& operator<<(std::ostream& os,const BoardState& board);

#endif //MANKALA5_BOARDSTATE_H
