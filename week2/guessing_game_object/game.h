#ifndef GAME_H
#define GAME_H

class Game {
    int maxNumber, playerGuess, randomNumber, numOfGuesses;
    void printGameResult();

public:
    Game(int max);
    ~Game();
    void play();

};

#endif // GAME_H
