#include "game_area.h"
#include "guess_checker.h"


GameArea::GameArea(std::size_t guesses_count, std::unique_ptr<GuessChecker> guess_checker) : _checker(std::move(guess_checker)),
                                                                                             _max_guess_count(guesses_count) {

}

bool GameArea::makeGuess(const SequenceRow& guess_row) {
    if (_guesses.size() + 1 >= _max_guess_count) {
        return false;
    }

    SequenceRow description_row = _checker->makeHintRow(guess_row);
    Guess next_guess{description_row, guess_row};
    _guesses.emplace_back(std::move(next_guess));
    return true;
}
