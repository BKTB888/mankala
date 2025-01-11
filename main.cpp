#include "Mankala.h"
#include <chrono>

void tester(Mankala& mankala, const unsigned numOfGames){
    const auto start = std::chrono::high_resolution_clock::now();
    mankala.makeStats(numOfGames);
    const auto end = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double, std::micro> duration = end - start;
    std::cout << "A single game on average: " << duration.count()/numOfGames << " microseconds" << std::endl;
}
const AI maxy = create_AI([] [[gnu::const]](const BoardState& board) -> float {

    const auto opSide=board.getOpponentSide();
    const unsigned char ballsInPlay =72 - board.getMyTrash() - board.getOpponentsTrash();
    const unsigned char opBalls = std::accumulate(opSide.begin(), opSide.end(), 0);

    return static_cast<float>(opBalls)/ballsInPlay;
});
int main() {
    Mankala test(randy, randy);

    constexpr int numOfGames=1000000;

    Mankala test2(randy2, randy2);
    Mankala test3(randy2, maxy);

    tester(test2, numOfGames);
    tester(test3, numOfGames);

    return 0;
}
