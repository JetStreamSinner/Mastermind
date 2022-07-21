#include "guess_state.h"
#include "../game_area.h"
#include "../interfaces/abstract_input_writer.h"
#include "../interfaces/abstract_input_reader.h"
#include "../utils.h"
#include "lose_state.h"
#include "win_state.h"
#include <iostream>

enum class NextState {
    Win,
    Lose,
    Same
};

class GuessState::GuessStateImpl {
public:
    explicit GuessStateImpl();
    bool exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader);
    std::unique_ptr<AbstractMastermindState> nextState();

private:
    NextState _nextState;
};

GuessState::GuessStateImpl::GuessStateImpl() : _nextState(NextState::Same) {
}

bool GuessState::GuessStateImpl::exec(std::shared_ptr<GameArea> &area,
                                      const std::unique_ptr<AbstractInputWriter> &writer,
                                      const std::unique_ptr<AbstractInputReader> &reader) {
    writer->writeMessage("Make your guess");
    SequenceRow guess = reader->requestGuess();
    const bool suggestions_end = !area->makeGuess(guess);

    if (suggestions_end) {
        writer->writeMessage("Suggestion end");
        _nextState = NextState::Lose;
        return true;
    }

    const bool last_guess_valid = area->lastGuessValid();
    if (last_guess_valid) {
        writer->writeMessage("Suggestion correct");
        _nextState = NextState::Win;
        return true;
    }

    const std::string hint_message = stringFromSequenceRow(area->lastGuessHint());
    writer->writeMessage(hint_message);

    _nextState = NextState::Same;
    return false;
}

std::unique_ptr<AbstractMastermindState> GuessState::GuessStateImpl::nextState() {
    switch (_nextState) {
        case NextState::Win:
            return std::make_unique<WinState>();
        case NextState::Lose:
            return std::make_unique<LoseState>();
        case NextState::Same:
            return std::make_unique<GuessState>();
    }
    throw std::runtime_error("State error");
}

GuessState::GuessState() : _impl(std::make_unique<GuessState::GuessStateImpl>()) {
}

bool GuessState::exec(std::shared_ptr<GameArea> &area,
                      const std::unique_ptr<AbstractInputWriter> &writer,
                      const std::unique_ptr<AbstractInputReader> &reader) {
    return _impl->exec(area, writer, reader);
}

std::unique_ptr<AbstractMastermindState> GuessState::nextState() {
    return _impl->nextState();
}

GuessState::~GuessState() = default;
