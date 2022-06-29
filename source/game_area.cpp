#include "game_area.h"
#include "guess_checker.h"


GameArea::GameArea(std::unique_ptr<GuessChecker> guess_checker) {

}

void GameArea::makeGuess(const SequenceRow& guess_row) {
    SequenceRow description_row = _checker->makeHintRow(guess_row);
    Guess next_guess{description_row, guess_row};
    _guesses.emplace_back(std::move(next_guess));
}
