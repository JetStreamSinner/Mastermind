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
    explicit GameArea(std::size_t guesses_count, std::unique_ptr<GuessChecker> guess_checker);
    bool makeGuess(const SequenceRow& guess_row);
    bool lastGuessValid() const;
private:
    std::vector<Guess> _guesses;
    std::unique_ptr<GuessChecker> _checker;
    std::size_t _max_guess_count;
};