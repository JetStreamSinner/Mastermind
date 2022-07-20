#pragma once

#include "types.h"
#include <memory>

class GuessChecker;

class GameArea {
public:
    explicit GameArea(std::size_t guesses_count, std::unique_ptr<GuessChecker> guess_checker);
    bool makeGuess(const SequenceRow &guess_row);
    bool lastGuessValid() const;
    SequenceRow lastGuessHint() const;
    ~GameArea();

private:
    class GameAreaImpl;
    std::unique_ptr<GameAreaImpl> _impl;
};