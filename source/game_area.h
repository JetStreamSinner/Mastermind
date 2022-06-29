#pragma once

#include <memory>
#include "types.h"
class GuessChecker;

struct Guess {
    SequenceRow validator;
    SequenceRow guessed;
};

class GameArea {
public:
    explicit GameArea(std::unique_ptr<GuessChecker> guess_checker);
    void makeGuess(const SequenceRow& guess_row);
private:
    std::vector<Guess> _guesses;
    std::unique_ptr<GuessChecker> _checker;
};