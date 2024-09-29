#include "Mankala.h"


int main() {
    Mankala test(randy, randy);

    test.playTest();
    int numOfGames=100000;

    Mankala test2(randy2, randy2);
    Mankala test3(randy2, minimax);

    tester(test, numOfGames);
    tester(test2, numOfGames);
    tester(test3, numOfGames);

    return 0;
}
