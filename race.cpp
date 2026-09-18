#include <iostream>
#include <cstdlib>
#include <ctime>

const int NUM_HORSES = 5;
const int TRACK_LENGTH = 15;

void advance(int horseNum, int* horses) {
    int coin = rand() % 2; // 0 = tails, 1 = heads
    if (coin == 1) {
        horses[horseNum] = horses[horseNum] + 1;
    }
}

void printLane(int horseNum, int* horses) {
    for (int position = 0; position < TRACK_LENGTH; position++) {
        if (position == horses[horseNum]) {
            std::cout << horseNum;
        } else {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

bool isWinner(int horseNum, int* horses) {
    if (horses[horseNum] >= TRACK_LENGTH - 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    srand(time(NULL));

    int horses[NUM_HORSES] = {0, 0, 0, 0, 0};
    bool someoneWon = false;

    while (!someoneWon) {

        // one full turn: move and print every horse
        for (int horseNum = 0; horseNum < NUM_HORSES; horseNum++) {
            advance(horseNum, horses);
            printLane(horseNum, horses);
        }

        // check if anyone crossed the finish line this turn
        for (int horseNum = 0; horseNum < NUM_HORSES; horseNum++) {
            if (isWinner(horseNum, horses)) {
                someoneWon = true;
                std::cout << "Horse " << horseNum << " WINS!!!" << std::endl;
            }
        }

        if (!someoneWon) {
            std::cout << "Press enter for another turn";
            std::cin.get();
        }
    }

    return 0;
}
