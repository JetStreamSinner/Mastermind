#include "game_area.h"
#include "guess_checker.h"

struct Guess {
    SequenceRow guess;
    SequenceRow hint;
    explicit Guess(const SequenceRow &_guess, const SequenceRow &_hint) : guess(_guess), hint(_hint) {
    }
};

class GameArea::GameAreaImpl {
public:
    explicit GameAreaImpl(std::size_t guesses_count, std::unique_ptr<GuessChecker> guess_checker);
    bool makeGuess(const SequenceRow &guess_row);
    bool lastGuessValid() const;
    SequenceRow lastGuessHint();

private:
    std::vector<Guess> _guesses;
    std::unique_ptr<GuessChecker> _checker;
    std::size_t _max_guess_count;
};

GameArea::GameAreaImpl::GameAreaImpl(std::size_t guesses_count, std::unique_ptr<GuessChecker> guess_checker) : _checker(std::move(guess_checker)),
                                                                                                               _max_guess_count(guesses_count) {
}

bool GameArea::GameAreaImpl::makeGuess(const SequenceRow &guess_row) {
    if (_guesses.size() + 1 >= _max_guess_count) {
        return false;
    }

    SequenceRow hint = _checker->makeHintRow(guess_row);
    Guess next_guess(guess_row, hint);
    _guesses.emplace_back(std::move(next_guess));
    return true;
}

bool GameArea::GameAreaImpl::lastGuessValid() const {
    Guess last_guess = _guesses.back();
    return _checker->guessValid(last_guess.guess);
}

SequenceRow GameArea::GameAreaImpl::lastGuessHint() {
    if (_guesses.empty()) {
        return {};
    }
    return _guesses.back().hint;
}

GameArea::GameArea(std::size_t guesses_count, std::unique_ptr<GuessChecker> guess_checker) : _impl(std::make_unique<GameArea::GameAreaImpl>(guesses_count, std::move(guess_checker))) {
}

bool GameArea::makeGuess(const SequenceRow &guess_row) {
    return _impl->makeGuess(guess_row);
}

bool GameArea::lastGuessValid() const {
    return _impl->lastGuessValid();
}

SequenceRow GameArea::lastGuessHint() const {
    return _impl->lastGuessHint();
}

GameArea::~GameArea() = default;
